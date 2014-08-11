//
//  Script.cpp
//  AngelScript
//
//  Created by Simon Geilfus on 13/02/14.
//
//

#include "script.h"

#include <scriptstdstring/scriptstdstring.h>
#include <scriptbuilder/scriptbuilder.h>
#include <serializer/serializer.h>
#include <scriptmath/scriptmath.h>
#include <scriptarray/scriptarray.h>
#include <scriptdictionary/scriptdictionary.h>

#include "cinder/Utilities.h"
#include "cinder/app/App.h"

using namespace std;
using namespace ci;

namespace as {
    
    // static variables
    asIScriptEngine* Script::sEngine = NULL;
    int Script::sNumScripts = 0;
    
    Script::Script( const std::string &moduleName )
    : mContext( NULL ), mModuleName( moduleName ), mModule( NULL ), mSerializer( NULL ), mIsBuilt( false )
    {
        mModule = getEngine()->GetModule( mModuleName.c_str(), asGM_ALWAYS_CREATE );
        mSerializer = new CSerializer();
        sNumScripts++;
    }
    
    //! create and returns a ScriptRef
    ScriptRef Script::create( const std::string &moduleName )
    {
        return ScriptRef( new Script( moduleName ) );
    }
    //! create, load script from DataSourceRef and returns a ScriptRef
    ScriptRef Script::create( ci::DataSourceRef script, const std::string &moduleName )
    {
        ScriptRef ref( new Script( moduleName ) );
        if( ref->loadFromFile( script ) && ref->build() ){
            return ref;
        }
        else return ScriptRef();
    }
    //! create, load script from std::string and returns a ScriptRef
    ScriptRef Script::create( const std::string &script, const std::string &moduleName )
    {
        ScriptRef ref( new Script( moduleName ) );
        if( ref->loadFromMemory( script ) &&  ref->build() ){
            return ref;
        }
        else return ScriptRef();
    }
    
    Script::~Script()
    {
        // Clean up
        if( mModule ){
           // mModule->Discard();
        }
        
        if( mContext ){
            mContext->Abort();
            mContext->Unprepare();
            mContext->Release();
        }
        
        
        getEngine()->GarbageCollect();
        
        sNumScripts--;
        
        /*if( sNumScripts <= 0 )
         getEngine()->Release();*/
    }
    
    //! load a script section from a file on disk. Returns false on errors
    bool Script::loadFromFile( ci::DataSourceRef script )
    {
        return processScriptSection( loadString( script ) ) >= 0;
    }
    //! load a script section from memory. Returns false on errors
    bool Script::loadFromMemory(const std::string &script )
    {
        return processScriptSection( script ) >= 0;
    }
    
    
    void Script::clear()
    {
        if( mContext ){
            mContext->Abort();
        }
        
        mModule     = getEngine()->GetModule( mModuleName.c_str(), asGM_ALWAYS_CREATE );
        mIsBuilt    = false;
        mFunctions.clear();
        mModifiedScript.clear();
        mIncludedScripts.clear();
    }
    
    //! add a pre-processor define for conditional compilation
    void Script::define( const std::string &word )
    {
        if( mDefinedWords.find(word) == mDefinedWords.end() )
        {
            mDefinedWords.insert(word);
        }
    }
    
    //! build the added script sections
    bool Script::build()
    {
        int r = mModule->Build();
        mIsBuilt = (r >= 0);
        return mIsBuilt;
    }
    
    //! returns wether the script has been built without errors
    bool Script::isBuilt()
    {
        return mIsBuilt;
    }
    
    //! returns the Script Context
    asIScriptContext* Script::getContext()
    {
        // Create our context and prepare it
        if( mContext == NULL ){
            mContext = getEngine()->CreateContext();
        }
        
        assert( mContext != NULL );
        
        return mContext;
    }
    //! returns the Script Module
    asIScriptModule* Script::getModule() const
    {
        assert( mModule != NULL );
        return mModule;
    }
    //! returns the Script Module Name
    const std::string& Script::getModuleName() const
    {
        return mModuleName;
    }
    //! returns the global Script Engine
    asIScriptEngine* Script::getEngine()
    {
        if( sEngine == NULL ){
            initializeEngine();
        }
        return sEngine;
    }
    //! returns the script Serializer
    CSerializer* Script::getSerializer() const
    {
        return mSerializer;
    }
    //! returns a function by its name
    asIScriptFunction* Script::getFunction( const std::string &name )
    {
        return mFunctions[name];
    }
    
    //! returns the address of a global variable by its name
    void* Script::getAddress( const std::string &name )
    {
        asIScriptModule *mod = getEngine()->GetModule( mModuleName.c_str() );
        int index = mod->GetGlobalVarIndexByName( name.c_str() );
        if( index >= 0 ){
            return mod->GetAddressOfGlobalVar( index );
        }
        return nullptr;
    }
    
    
    //! calls a scripted function
    void Script::call( const std::string &function )
    {
        if( prepareFunction( function ) ){
            executeFunction();
        }
    }
    
    
    void Script::registerErrorHandler( const std::function<void(int,int,const std::string&,const std::string&)> callback ){
        mErrorHandler = callback;
    }
    
    
    void Script::compileScript( const std::string &script )
    {
    }
    
    bool Script::prepareFunction( const std::string &name )
    {
        if( !isBuilt() )
            return false;
        /*
         cout << "isContextNull: " << (getContext() == NULL) << endl;
         cout << "isModuleNull: " << (getModule() == NULL) << endl;*/
        
        
        asIScriptFunction *func;
        /*if( mFunctions.count( name ) && mFunctions[name] != NULL ){
         func = mFunctions[name];
         }
         else {*/
        func = mModule->GetFunctionByDecl( name.c_str() );
        if( func == 0 )
        {
            // The function couldn't be found. Instruct the script writer
            // to include the expected function in the script.
            /* cout << "The script must have the function " <<  name << ". Please add it and try again." << endl;*/
            return false;
        }
        /*    mFunctions[name] = func;
         }*/
        
        int state = getContext()->GetState();
        /* switch( state ){
         case asEXECUTION_FINISHED      : cout << "State: " << "asEXECUTION_FINISHED" << endl; break;
         case asEXECUTION_SUSPENDED     : cout << "State: " << "asEXECUTION_SUSPENDED" << endl; break;
         case asEXECUTION_ABORTED       : cout << "State: " << "asEXECUTION_ABORTED" << endl; break;
         case asEXECUTION_EXCEPTION     : cout << "State: " << "asEXECUTION_EXCEPTION" << endl; break;
         case asEXECUTION_PREPARED      : cout << "State: " << "asEXECUTION_PREPARED" << endl; break;
         case asEXECUTION_UNINITIALIZED : cout << "State: " << "asEXECUTION_UNINITIALIZED" << endl; break;
         case asEXECUTION_ACTIVE        : cout << "State: " << "asEXECUTION_ACTIVE" << endl; break;
         case asEXECUTION_ERROR         : cout << "State: " << "asEXECUTION_ERROR" << endl; break;
         }*/
        
        if( func == NULL || state == asEXECUTION_EXCEPTION || state == asEXECUTION_ERROR )
            return false;
        
        /* assert(func);
         
         cout << "isFunctionNull: " << ( func == nullptr) << endl;
         cout << "functionName: " << ( func->GetName() ) << endl;*/
        
        
        int r = getContext()->Prepare(func);
        return r >= 0;
    }
    bool Script::executeFunction()
    {
        int r = getContext()->Execute();
        if( r != asEXECUTION_FINISHED )
        {
            // The execution didn't complete as expected. Determine what happened.
            if( r == asEXECUTION_EXCEPTION )
            {
                // An exception occurred, let the script writer know what happened so it can be corrected.
                printf("An exception '%s' occurred. Please correct the code and try again.\n", getContext()->GetExceptionString());
            }
            return false;
        }
        return true;
    }
    
    int  Script::processScriptSection( const std::string &script )
    {
        vector<string> includes;
        
        mModifiedScript = script;
        
        // First perform the checks for #if directives to exclude code that shouldn't be compiled
        unsigned int pos = 0;
        int nested = 0;
        while( pos < mModifiedScript.size() )
        {
            int len;
            asETokenClass t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
            if( t == asTC_UNKNOWN && mModifiedScript[pos] == '#' && (pos + 1 < mModifiedScript.size()) )
            {
                int start = pos++;
                
                // Is this an #if directive?
                asETokenClass t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                
                string token;
                token.assign(&mModifiedScript[pos], len);
                
                pos += len;
                
                if( token == "if" )
                {
                    t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                    if( t == asTC_WHITESPACE )
                    {
                        pos += len;
                        t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                    }
                    
                    if( t == asTC_IDENTIFIER )
                    {
                        string word;
                        word.assign(&mModifiedScript[pos], len);
                        
                        // Overwrite the #if directive with space characters to avoid compiler error
                        pos += len;
                        overwriteCode( start, pos-start );
                        
                        // Has this identifier been defined by the application or not?
                        if( mDefinedWords.find(word) == mDefinedWords.end() )
                        {
                            // Exclude all the code until and including the #endif
                            pos = excludeCode( pos );
                        }
                        else
                        {
                            nested++;
                        }
                    }
                }
                else if( token == "endif" )
                {
                    // Only remove the #endif if there was a matching #if
                    if( nested > 0 )
                    {
                        overwriteCode( start, pos-start );
                        nested--;
                    }
                }
            }
            else
                pos += len;
        }
        
        // Then check for meta data and #include directives
        pos = 0;
        while( pos < mModifiedScript.size() )
        {
            int len;
            asETokenClass t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
            if( t == asTC_COMMENT || t == asTC_WHITESPACE )
            {
                pos += len;
                continue;
            }
            
            // Is this a preprocessor directive?
            if( mModifiedScript[pos] == '#' && (pos + 1 < mModifiedScript.size()) )
            {
                int start = pos++;
                
                asETokenClass t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                if( t == asTC_IDENTIFIER )
                {
                    string token;
                    token.assign(&mModifiedScript[pos], len);
                    if( token == "include" )
                    {
                        pos += len;
                        t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                        if( t == asTC_WHITESPACE )
                        {
                            pos += len;
                            t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                        }
                        
                        if( t == asTC_VALUE && len > 2 && (mModifiedScript[pos] == '"' || mModifiedScript[pos] == '\'') )
                        {
                            // Get the include file
                            string includefile;
                            includefile.assign(&mModifiedScript[pos+1], len-2);
                            pos += len;
                            
                            // Store it for later processing
                            includes.push_back(includefile);
                            
                            // Overwrite the include directive with space characters to avoid compiler error
                            overwriteCode( start, pos-start );
                        }
                    }
                }
            }
            // Don't search for metadata/includes within statement blocks or between tokens in statements
            else
            {
                pos = skipStatement( pos );
            }
        }
        
        // Build the actual script
        getEngine()->SetEngineProperty(asEP_COPY_SCRIPT_SECTIONS, true);
        mModule->AddScriptSection( "MainSection", mModifiedScript.c_str(), mModifiedScript.size());
        
        if( includes.size() > 0 )
        {
            
            for( int n = 0; n < (int)includes.size(); n++ )
            {
                
                DataSourceRef includeData;
                try {
                    includeData = app::App::get()->loadAsset( includes[n] );
                }
                catch( ci::app::AssetLoadExc exc ){
                    cout << exc.what() << endl;
                }
                
                if( !includeData ){
                    cout << "The script couldn't load " << includes[n] << " include. Please correct the path and try again." << endl;
                    
                    getEngine()->WriteMessage( "MainSection", 1, 1, asMSGTYPE_ERROR, ("The script couldn't load " + includes[n] + " include. Please correct the path and try again.").c_str() );
                }
                else {
                    if( includeIfNotAlreadyIncluded( includes[n] ) )  {
                        int r = processScriptSection( loadString( includeData ) );
                        if( r < 0 )
                            return r;
                    }
                    
                    return 0;
                }
            }
            
        }
        return 0;
    }
    
	bool Script::includeIfNotAlreadyIncluded( const std::string &filename )
    {
        if( mIncludedScripts.find(filename) != mIncludedScripts.end() ) {
            // Already included
            return false;
        }
        
        // Add the file to the set of included sections
        mIncludedScripts.insert(filename);
        
        return true;
    }
    
    int  Script::skipStatement( int pos )
    {
        int len;
        
        // Skip until ; or { whichever comes first
        while( pos < (int)mModifiedScript.length() && mModifiedScript[pos] != ';' && mModifiedScript[pos] != '{' )
        {
            getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
            pos += len;
        }
        
        // Skip entire statement block
        if( pos < (int)mModifiedScript.length() && mModifiedScript[pos] == '{' )
        {
            pos += 1;
            
            // Find the end of the statement block
            int level = 1;
            while( level > 0 && pos < (int)mModifiedScript.size() )
            {
                asETokenClass t = getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                if( t == asTC_KEYWORD )
                {
                    if( mModifiedScript[pos] == '{' )
                        level++;
                    else if( mModifiedScript[pos] == '}' )
                        level--;
                }
                
                pos += len;
            }
        }
        else
            pos += 1;
        
        return pos;
    }
    
    int Script::excludeCode( int pos )
    {
        int len;
        int nested = 0;
        while( pos < (int) mModifiedScript.size() )
        {
            getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
            if( mModifiedScript[pos] == '#' )
            {
                mModifiedScript[pos] = ' ';
                pos++;
                
                // Is it an #if or #endif directive?
                getEngine()->ParseToken(&mModifiedScript[pos], mModifiedScript.size() - pos, &len);
                string token;
                token.assign(&mModifiedScript[pos], len);
                overwriteCode( pos, len);
                
                if( token == "if" )
                {
                    nested++;
                }
                else if( token == "endif" )
                {
                    if( nested-- == 0 )
                    {
                        pos += len;
                        break;
                    }
                }
            }
            else if( mModifiedScript[pos] != '\n' )
            {
                overwriteCode( pos, len);
            }
            pos += len;
        }
        
        return pos;
    }
    void Script::overwriteCode( int start, int len )
    {
        char *code = &mModifiedScript[start];
        for( int n = 0; n < len; n++ )
        {
            if( *code != '\n' )
                *code = ' ';
            code++;
        }
    }
    
    void Script::messageCallback( const asSMessageInfo *msg, void *param )
    {
    }
    
    // Implement a simple message callback function
    void MessageCallback(const asSMessageInfo *msg, void *param)
    {
        const char *type = "ERR ";
        if( msg->type == asMSGTYPE_WARNING )
            type = "WARN";
        else if( msg->type == asMSGTYPE_INFORMATION )
            type = "INFO";
        
        printf( "%s (%d, %d) : %s : %s\n", msg->section, msg->row, msg->col, type, msg->message);
    }
    
    void Script::initializeEngine()
    {
        // Create the script engine
        sEngine = asCreateScriptEngine( ANGELSCRIPT_VERSION );
        // Set the message callback to receive information on errors in human readable form.
        int r = sEngine->SetMessageCallback(asFUNCTION(MessageCallback), 0, asCALL_CDECL); assert( r >= 0 );
        
        // sEngine->SetEngineProperty( asEP_DISALLOW_GLOBAL_VARS, 1 );
        
        // Register libraries
        RegisterStdString( sEngine );
        RegisterScriptArray( sEngine, true );
        RegisterScriptDictionary( sEngine );
        RegisterScriptMath( sEngine );
    }
    
    //! outputs details about registered types to the console
    void Script::listRegisteredTypes( bool listMethods, bool listProperties )
    {
        asIScriptEngine *engine = as::Script::getEngine();
        asUINT typeCount = engine->GetObjectTypeCount();
        for( int i = 0; i < typeCount; i++ ){
            asIObjectType *type = engine->GetObjectTypeByIndex( i );
            string name     = type->GetName();
            string ns       = type->GetNamespace();
            string nsname   = ( ns.length() ? ns + "::" + name : name );
            std::cout << nsname << std::endl;
            
            // output properties
            asUINT propertyCount = type->GetPropertyCount();
            if( listProperties && propertyCount ){
                std::cout << std::endl;
                for( int j = 0; j < propertyCount; j++ ){
                    string propertyDeclaration   = type->GetPropertyDeclaration( j );
                    std::cout << '\t' << propertyDeclaration << std::endl;
                }
                std::cout << std::endl;
            }
            
            // output methods
            if( listMethods ){
                asUINT methodCount = type->GetMethodCount();
                for( int j = 0; j < methodCount; j++ ){
                    asIScriptFunction *method   = type->GetMethodByIndex( j );
                    string methodDeclaration    = method->GetDeclaration();
                    std::cout << '\t' << methodDeclaration << std::endl;
                }
                std::cout << std::endl;
            }
        }
    }
    //! outputs details about registered methods to the console
    void Script::listRegisteredMethods()
    {
        asIScriptEngine *engine = as::Script::getEngine();
        asUINT globalFunctionCount = engine->GetGlobalFunctionCount();
        for( int i = 0 ; i < globalFunctionCount; i++ ){
            asIScriptFunction *function = engine->GetGlobalFunctionByIndex( i );
            string name         = function->GetName();
            string ns           = function->GetNamespace();
            string declaration  = function->GetDeclaration();
            std::cout << ( !ns.empty() ? "(" + ns + ") " + declaration : declaration ) << std::endl;
        }
        
    }
    //! outputs details about registered properties to the console
    void Script::listRegisteredProperties()
    {
        asIScriptEngine *engine = as::Script::getEngine();
        asUINT globalPropertyCount = engine->GetGlobalPropertyCount();
        for( int i = 0 ; i < globalPropertyCount; i++ ){
            const char *name;
            const char *ns;
            int typeId;
            bool isConst;
            engine->GetGlobalPropertyByIndex( i, &name, &ns, &typeId, &isConst );
            const char* typeDeclaration = engine->GetTypeDeclaration( typeId );
            string property = ( isConst ? "const " : "" ) + string( typeDeclaration ) + " " + string( name );
            std::cout << property << std::endl;
        }
    }
    //! outputs details about registered enums to the console
    void Script::listRegisteredEnums()
    {
        asIScriptEngine *engine = as::Script::getEngine();
        asUINT enumCount = engine->GetEnumCount();
        for( int i = 0; i < enumCount; i++ ){
            int typeId;
            string typeDeclaration = engine->GetTypeDeclaration( typeId );
            string enumName = engine->GetEnumByIndex( i, &typeId );
            string enumDeclaration = typeDeclaration + " " + enumName;
            std::cout << enumDeclaration << std::endl;
        }
    }
    
    //! setArg Template Specializations
    template<> void Script::setArgValue<int>( int arg, int value ) { getContext()->SetArgDWord( arg, value ); }
    template<> void Script::setArgValue<float>( int arg, float value ) { getContext()->SetArgFloat( arg, value ); }
    template<> void Script::setArgValue<double>( int arg, double value ) { getContext()->SetArgDouble( arg, value ); }
    template<> void Script::setArgValue<bool>( int arg, bool value ) { getContext()->SetArgByte( arg, value ); }
}