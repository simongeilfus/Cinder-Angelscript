#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Utilities.h"

#include "script.h"
#include "angelscriptcinder.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MethodAsGlobalFunctionApp : public AppNative {
public:
	void setup();
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! a basic script message interface
    void scriptMessageReceived( const std::string &message );
    
    //! our script
    as::ScriptRef mScript;
};

//! console wrapper
void print( const std::string &s )
{
    console() << s << endl;
}

//! example function
int add( int a, int b )
{
    return a + b;
}

void MethodAsGlobalFunctionApp::setup()
{
    setupScriptEngine();
    
    // load the application settings
    mScript = as::Script::create( loadAsset( "main.asc" ), "" );
    
    // always safer to wrap any script interaction in an if
    // just to be sure that we're not trying to access a script
    // that hasn't been correctly initialized.
    if( mScript ){
        
        // call the main function
        mScript->call( "void main()" );
    }
    
    // exit
    quit();
}


void MethodAsGlobalFunctionApp::scriptMessageReceived( const std::string &message )
{
    console() << "Message received: " << endl << '\t' << message << endl;
}

void MethodAsGlobalFunctionApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    int r;
    
    // register a print function so we can output to the console
    r = engine->RegisterGlobalFunction("void print( const string &in )", asFUNCTION(print), asCALL_CDECL );  assert( r >= 0 );
    
    // register ci::toString int specialization
    r = engine->RegisterGlobalFunction("string toString( const int &in )", asFUNCTION(toString<int>), asCALL_CDECL );  assert( r >= 0 );
    
    // register our amazing custom add function
    r = engine->RegisterGlobalFunction("int add( int a, int b )", asFUNCTION(add), asCALL_CDECL );  assert( r >= 0 );
    
    // register a class method as a global function in our script context.
    // the only difference with the previous method is that we have to provide the class,
    // a different asCALL flag, and the instance of the class we want to call the method
    // on... that's it, there's no way to tell the difference from the script perspective.
    r = engine->RegisterGlobalFunction("void sendMessage( const string &in )", asMETHOD(MethodAsGlobalFunctionApp,scriptMessageReceived), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
}

CINDER_APP_NATIVE( MethodAsGlobalFunctionApp, RendererGl )
