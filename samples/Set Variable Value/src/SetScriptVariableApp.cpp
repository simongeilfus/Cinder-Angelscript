#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"
#include "angelscriptcinder.h"

#include "AssetManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SetScriptVariableApp : public AppNative {
public:
	void setup();
    void update();
	void draw();
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our script file
    as::ScriptRef mScript;
};

void SetScriptVariableApp::setup()
{
    getWindow()->setAlwaysOnTop();
    
    setupScriptEngine();
    
    // watch our script for change and reloads it when needed
    AssetManager::load( "main.asc", [this]( DataSourceRef sketch ){
        mScript = as::Script::create( sketch, "" );
        
        if( mScript ){
            mScript->call( "void setup()" );
        }
    });
}

void SetScriptVariableApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function.
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(SetScriptVariableApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    
    // register cinder
    as::registerCinder( engine );
}


void SetScriptVariableApp::update()
{
    if( mScript ){
        mScript->call( "void update()" );
        
        // set the global script variable named "time"
        // Be sure to cast to the right type (getElapsedSeconds() returns
        // a float, and "time" is a float in our script. If you end up
        // providing the wrong type, it's unsure what would happen because
        // we are accessing the memory of the object to change its value.
        mScript->set( "time", 10.0f + static_cast<float>( getElapsedSeconds() ) * 5.0f );
    }
}

void SetScriptVariableApp::draw()
{
    if( mScript ){
        mScript->call( "void draw()" );
    }
}

//! console wrapper
void SetScriptVariableApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( SetScriptVariableApp, RendererGl )
