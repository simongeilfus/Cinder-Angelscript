//
//  Script.h
//  AngelScript
//
//  Created by Simon Geilfus on 13/02/14.
//
//

#pragma once

#include "cinder/DataSource.h"
#include <angelscript.h>

#include <string>
#include <map>
#include <set>
#include <vector>

class CSerializer;

namespace as {
    
    typedef std::shared_ptr<class Script> ScriptRef;
    
    class Script {
    public:
        //! creates and returns a ScriptRef
        static ScriptRef create( const std::string &moduleName );
        //! creates, loads script from DataSourceRef and returns a ScriptRef
        static ScriptRef create( ci::DataSourceRef script, const std::string &moduleName );
        //! creates, loads script from std::string and returns a ScriptRef
        static ScriptRef create( const std::string &script, const std::string &moduleName );
        
        ~Script();
        
        //! loads a script section from a file on disk. Returns false on errors
        bool loadFromFile( ci::DataSourceRef script );
        //! loads a script section from memory. Returns false on errors
        bool loadFromMemory( const std::string &script );
        
        //! adds a pre-processor define for conditional compilation
        void define( const std::string &word );
        
        //! discards the script module and create a new one
        void clear();
        
        //! builds the added script sections
        bool build();
        
        //! returns wether the script has been built without errors
        bool isBuilt();
        
        //! returns the Script Context
        asIScriptContext*       getContext();
        //! returns the Script Module
        asIScriptModule*        getModule() const;
        //! returns the Script Module Name
        const std::string&      getModuleName() const;
        //! returns the global Script Engine
        static asIScriptEngine* getEngine();
        //! returns the script Serializer
        CSerializer*            getSerializer() const;
        //! returns a function by its name
        asIScriptFunction*      getFunction( const std::string &name );
        
        //! sets the address of a global variable by its signature
        template<typename T>
        static void setAddress( const std::string &signature, T* address );
        
        //! returns the address of a global variable by its name
        void* getAddress( const std::string &name );
        
        //! returns a global variable by its name
        template<typename T>
        T get( const std::string &name );
        
        //! sets the value of a global variable by name
        template<typename T>
        void set( const std::string &name, const T &t );
        
        //! calls a scripted function
        void call( const std::string &function );
        //! calls a scripted function with one argument
        template<typename T>
        void call( const std::string &function, T arg0 );
        //! calls a scripted function with 2 arguments
        template<typename T, typename U>
        void call( const std::string &function, T arg0, U arg1 );
        //! calls a scripted function with 3 arguments
        template<typename T, typename U, typename V>
        void call( const std::string &function, T arg0, U arg1, V arg2 );
        //! calls a scripted function with 4 arguments
        template<typename T, typename U, typename V, typename W>
        void call( const std::string &function, T arg0, U arg1, V arg2, W arg3 );
        //! calls a scripted function with 5 arguments
        template<typename T, typename U, typename V, typename W, typename X>
        void call( const std::string &function, T arg0, U arg1, V arg2, W arg3, X arg4 );
        
        //! calls a scripted function and returns its value
        template<typename T>
        T call( const std::string &function );
        //! calls a scripted function with one argument and returns its value
        template<typename R, typename T>
        R call( const std::string &function, T arg0 );
        //! calls a scripted function with 2 arguments and returns its value
        template<typename R, typename T, typename U>
        R call( const std::string &function, T arg0, U arg1 );
        //! calls a scripted function with 3 arguments and returns its value
        template<typename R, typename T, typename U, typename V>
        R call( const std::string &function, T arg0, U arg1, V arg2 );
        //! calls a scripted function with 4 arguments and returns its value
        template<typename R, typename T, typename U, typename V, typename W>
        R call( const std::string &function, T arg0, U arg1, V arg2, W arg3 );
        //! calls a scripted function with 5 arguments and returns its value
        template<typename R, typename T, typename U, typename V, typename W, typename X>
        R call( const std::string &function, T arg0, U arg1, V arg2, W arg3, X arg4 );
        
        void registerErrorHandler( const std::function<void(int,int,const std::string&,const std::string&)> callback );
        
        //! outputs detailed about registered types to the console
        static void listRegisteredTypes( bool listMethods = true, bool listProperties = true );
        //! outputs details about registered methods to the console
        static void listRegisteredMethods();
        //! outputs details about registered properties to the console
        static void listRegisteredProperties();
        //! outputs details about registered enums to the console
        static void listRegisteredEnums();

        
    protected:
        Script( const std::string &moduleName = "Default" );
        
        void compileScript( const std::string &script );
        bool prepareFunction( const std::string &name );
        bool executeFunction();
        
        int  processScriptSection( const std::string &script );
        int  loadScriptSection( const std::string &filename );
        bool includeIfNotAlreadyIncluded( const std::string &filename );
        
        int  skipStatement( int pos );
        
        int  excludeCode( int start );
        void overwriteCode( int start, int len );
        
        void messageCallback( const asSMessageInfo *msg, void *param );
        
        template<typename T>
        void setArgValue( int arg, T value );
        
        static void initializeEngine();
        
        bool                    mIsBuilt;
        
        asIScriptContext*       mContext;
        
        std::map<std::string,asIScriptFunction*>                            mFunctions;
        std::function<void(int,int,const std::string&,const std::string&)>  mErrorHandler;
        
        std::string             mModifiedScript;
        
        std::string             mModuleName;
        asIScriptModule*        mModule;
        
        CSerializer*            mSerializer;
        
        std::set<std::string>   mIncludedScripts;
        std::set<std::string>   mDefinedWords;
        
        static asIScriptEngine* sEngine;
        static int              sNumScripts;
    };
    
    
    
    
    
    
    // Templated implementations
    
    
    
    //! calls a scripted function with one argument
    template<typename T>
    void Script::call( const std::string &function, T arg0 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            executeFunction();
        }
    }
    //! calls a scripted function with 2 arguments
    template<typename T, typename U>
    void Script::call( const std::string &function, T arg0, U arg1 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            executeFunction();
        }
    }
    //! calls a scripted function with 3 arguments
    template<typename T, typename U, typename V>
    void Script::call( const std::string &function, T arg0, U arg1, V arg2 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            setArgValue( 2, arg2 );
            executeFunction();
        }
    }
    //! calls a scripted function with 4 arguments
    template<typename T, typename U, typename V, typename W>
    void Script::call( const std::string &function, T arg0, U arg1, V arg2, W arg3 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            setArgValue( 2, arg2 );
            setArgValue( 3, arg3 );
            executeFunction();
        }
    }
    //! calls a scripted function with 5 arguments
    template<typename T, typename U, typename V, typename W, typename X>
    void Script::call( const std::string &function, T arg0, U arg1, V arg2, W arg3, X arg4 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            setArgValue( 2, arg2 );
            setArgValue( 3, arg3 );
            setArgValue( 4, arg4 );
            executeFunction();
        }
    }
    
    //! calls a scripted function and returns its value
    template<typename T>
    T Script::call( const std::string &function )
    {
        if( !prepareFunction( function ) ){
            return T();
        }
        if( executeFunction() ){
            // Get a pointer to the returned object and copy it to our object
            T obj = *(T*) mContext->GetAddressOfReturnValue();
            return obj;
        }
        return T();
    }
    
    //! calls a scripted function with one argument and returns its value
    template<typename R, typename T>
    R Script::call( const std::string &function, T arg0 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            if( executeFunction() ){
                T obj = *(T*) mContext->GetAddressOfReturnValue();
                return obj;
            }
        }
        return T();
    }
    //! calls a scripted function with 2 arguments and returns its value
    template<typename R, typename T, typename U>
    R Script::call( const std::string &function, T arg0, U arg1 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            if( executeFunction() ){
                T obj = *(T*) mContext->GetAddressOfReturnValue();
                return obj;
            }
        }
        return T();
    }
    //! calls a scripted function with 3 arguments and returns its value
    template<typename R, typename T, typename U, typename V>
    R Script::call( const std::string &function, T arg0, U arg1, V arg2 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            setArgValue( 2, arg2 );
            if( executeFunction() ){
                T obj = *(T*) mContext->GetAddressOfReturnValue();
                return obj;
            }
        }
        return T();
    }
    //! calls a scripted function with 4 arguments and returns its value
    template<typename R, typename T, typename U, typename V, typename W>
    R Script::call( const std::string &function, T arg0, U arg1, V arg2, W arg3 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            setArgValue( 2, arg2 );
            setArgValue( 3, arg3 );
            if( executeFunction() ){
                T obj = *(T*) mContext->GetAddressOfReturnValue();
                return obj;
            }
        }
        return T();
    }
    //! calls a scripted function with 5 arguments and returns its value
    template<typename R, typename T, typename U, typename V, typename W, typename X>
    R Script::call( const std::string &function, T arg0, U arg1, V arg2, W arg3, X arg4 )
    {
        if( prepareFunction( function ) ){
            setArgValue( 0, arg0 );
            setArgValue( 1, arg1 );
            setArgValue( 2, arg2 );
            setArgValue( 3, arg3 );
            setArgValue( 4, arg4 );
            if( executeFunction() ){
                T obj = *(T*) mContext->GetAddressOfReturnValue();
                return obj;
            }
        }
        return T();
    }
    
    //! sets the address of a global variable by its signature
    template<typename T>
    void Script::setAddress( const std::string &signature, T* address ){
        int r;
        
        // Register a primitive property that can be read and written to from the script.
        r = getEngine()->RegisterGlobalProperty( signature.c_str(), static_cast<void*>( address ) ); assert( r >= 0 );
    }
    
    //! returns a global variable by name
    template<typename T>
    T Script::get( const std::string &name )
    {
        asIScriptModule *mod = getEngine()->GetModule( mModuleName.c_str() );
        int index = mod->GetGlobalVarIndexByName( name.c_str() );
        if( index >= 0 ){
            T* address = static_cast<T*>( mod->GetAddressOfGlobalVar( index ) );
            return *address;
        }
        return T();
    }
    
    //! sets the value of a global variable by name
    template<typename T>
    void Script::set( const std::string &name, const T &t )
    {
        asIScriptModule *mod = getEngine()->GetModule( mModuleName.c_str() );
        int index = mod->GetGlobalVarIndexByName( name.c_str() );
        if( index >= 0 ){
            *static_cast<T*>( mod->GetAddressOfGlobalVar( index ) ) = t;
        }
    }
    
    
    template<typename T>
    void Script::setArgValue( int arg, T value ) { getContext()->SetArgObject( arg, &value ); }
    
    
}