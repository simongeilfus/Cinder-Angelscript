#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"
#include "angelscriptcinder.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class TypedSettingsApp : public AppNative {
public:
	void setup();
	void draw();
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our settings file
    as::ScriptRef mSettings;
};

void TypedSettingsApp::setup()
{
    setupScriptEngine();
    
    // load the application settings
    mSettings = as::Script::create( loadAsset( "Settings.asc" ), "Settings" );
    
    // if the script got loaded and compiled correctly
    if( mSettings ){
        
        // extract the settings to setup the app window
        setWindowSize( mSettings->get<Vec2i>( "windowSize" ) );
        setWindowPos( mSettings->get<Vec2i>( "windowPos" ) );
        
        // check if we need to go fullscreen
        setFullScreen( mSettings->get<bool>( "fullscreen" ) );
    }
}

void TypedSettingsApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function. this time we check the return value which is a good practice
    // if we want to detect errors in writing the application interface.
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(TypedSettingsApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    
    // register the interface to use ci::Vec2i in our settings
    as::registerCinderVec2Type<int>( engine, "Vec2i", "int" );
    as::registerCinderVec2Impl<int>( engine, "Vec2i", "int" );
    
}


void TypedSettingsApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
}

//! console wrapper
void TypedSettingsApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( TypedSettingsApp, RendererGl )
