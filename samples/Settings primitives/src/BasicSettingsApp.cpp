#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicSettingsApp : public AppNative {
public:
	void setup();
	void draw();
    
    //! setup the engine, registers the app interface
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our settings file
    as::ScriptRef mSettings;
};

void BasicSettingsApp::setup()
{
    // registers the app interface
    setupScriptEngine();
    
    // load the application settings
    mSettings = as::Script::create( loadAsset( "Settings.asc" ), "Settings" );
    
    // if the script got loaded and compiled correctly
    if( mSettings ){
        
        // extract the settings to setup the app window
        setWindowSize( mSettings->get<int>( "windowWidth" ), mSettings->get<int>( "windowHeight" ) );
        setWindowPos( mSettings->get<int>( "windowX" ), mSettings->get<int>( "windowY" ) );
        
        // check if we need to go fullscreen
        setFullScreen( mSettings->get<bool>( "fullscreen" ) );
    }
}

void BasicSettingsApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function. this time we check the return value which is a good practice
    // if we want to detect errors in writing the application interface.
    // the first macro is a way to point to the right method and the following flag basically
    // states that the call will occur on this object but act in the script as a global function
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(BasicSettingsApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
}


void BasicSettingsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
}

//! console wrapper
void BasicSettingsApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( BasicSettingsApp, RendererGl )
