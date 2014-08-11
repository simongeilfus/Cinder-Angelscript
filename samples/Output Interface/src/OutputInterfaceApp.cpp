#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"

#include "script.h"
#include "angelscriptcinder.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class OutputInterfaceApp : public AppNative {
  public:
	void setup();
	void draw();
    
    //! antweakbar panels to display the script interface
    params::InterfaceGlRef mTypes, mGlobalFunctions, mGlobalProperties, mEnums;
    
    //! dummy variables
    float mTest;
    Vec2f mPosition;
};

void OutputInterfaceApp::setup()
{
    setWindowSize( 320 * 3 + 20, 600 );
    
    // register cinder and some dummy variables
    as::registerCinder( as::Script::getEngine() );
    as::Script::setAddress( "float mTest", &mTest );
    as::Script::setAddress( "Vec2f mPosition", &mPosition );
    
    // convenient methods to output the same information to the console
    as::Script::listRegisteredTypes();
    as::Script::listRegisteredProperties();
    as::Script::listRegisteredMethods();
    as::Script::listRegisteredEnums();
    
    // create a few panels to display the output
    mTypes              = params::InterfaceGl::create( "Registered Types", Vec2i( 300, getWindowHeight() - 50 ) );
    mGlobalFunctions    = params::InterfaceGl::create( "Globals and Static Functions", Vec2i( 300, getWindowHeight() - 50 ) );
    mGlobalProperties   = params::InterfaceGl::create( "Globals Properties", Vec2i( 300, ( getWindowHeight() - 50 ) / 2 - 20 ) );
    mEnums              = params::InterfaceGl::create( "Enums", Vec2i( 300, ( getWindowHeight() - 50 ) / 2 ) );
    
    // layout
    mTypes->setPosition( Vec2i( 20, 20 ) );
    mGlobalFunctions->setPosition( Vec2i( 340, 20 ) );
    mGlobalProperties->setPosition( Vec2i( 660, 20 ) );
    mEnums->setPosition( Vec2i( 660, ( getWindowHeight() - 50 ) / 2 + 20 ) );
    
    // get object type informations
    asIScriptEngine *engine = as::Script::getEngine();
    asUINT typeCount = engine->GetObjectTypeCount();
    for( int i = 0; i < typeCount; i++ ){
        asIObjectType *type = engine->GetObjectTypeByIndex( i );
        string name     = type->GetName();
        string ns       = type->GetNamespace();
        string nsname   = ( ns.length() ? ns + "::" + name : name );
        mTypes->addButton( nsname, []{} );
        asUINT propertyCount = type->GetPropertyCount();
        if( propertyCount ) mTypes->addSeparator();
        for( int j = 0; j < propertyCount; j++ ){
            string propertyDeclaration   = type->GetPropertyDeclaration( j );
            mTypes->addText( nsname+propertyDeclaration, "label='"+propertyDeclaration+"'" );
        }
        mTypes->addSeparator();
        asUINT methodCount = type->GetMethodCount();
        for( int j = 0; j < methodCount; j++ ){
            asIScriptFunction *method   = type->GetMethodByIndex( j );
            string methodDeclaration    = method->GetDeclaration();
            mTypes->addText( nsname+methodDeclaration, "label='"+methodDeclaration+"'" );
        }
        mTypes->addSeparator();
    }
    
    // get global function informations
    asUINT globalFunctionCount = engine->GetGlobalFunctionCount();
    for( int i = 0 ; i < globalFunctionCount; i++ ){
        asIScriptFunction *function = engine->GetGlobalFunctionByIndex( i );
        string name         = function->GetName();
        string ns           = function->GetNamespace();
        string declaration  = function->GetDeclaration();
        mGlobalFunctions->addText( !ns.empty() ? "(" + ns + ") " + declaration : declaration );
    }
    
    // get global properties informations
    asUINT globalPropertyCount = engine->GetGlobalPropertyCount();
    for( int i = 0 ; i < globalPropertyCount; i++ ){
        const char *name;
        const char *ns;
        int typeId;
        bool isConst;
        engine->GetGlobalPropertyByIndex( i, &name, &ns, &typeId, &isConst );
        const char* typeDeclaration = engine->GetTypeDeclaration( typeId );
        string property = ( isConst ? "const " : "" ) + string( typeDeclaration ) + " " + string( name );
        mGlobalProperties->addText( property );
    }
    
    // get enums
    asUINT enumCount = engine->GetEnumCount();
    for( int i = 0; i < enumCount; i++ ){
        int typeId;
        string typeDeclaration = engine->GetTypeDeclaration( typeId );
        string enumName = engine->GetEnumByIndex( i, &typeId );
        string enumDeclaration = typeDeclaration + " " + enumName;
        mEnums->addText( enumDeclaration );
    }
}

void OutputInterfaceApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    // this apparently still draw all the panels
    mTypes->draw();
}

CINDER_APP_NATIVE( OutputInterfaceApp, RendererGl )
