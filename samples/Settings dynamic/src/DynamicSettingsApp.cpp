#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"
#include "angelscriptcinder.h"

#include "AssetManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DynamicSettingsApp : public AppNative {
public:
	void setup();
	void draw();
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our settings file
    as::ScriptRef mSettings;
    
    Color mBackgroundColor;
};

void DynamicSettingsApp::setup()
{
    setupScriptEngine();
    
    AssetManager::load( "Settings.asc", [this]( DataSourceRef script ){
        // load the application settings
        mSettings = as::Script::create( script, "" );
        
        
        // if the script got loaded and compiled correctly
        if( mSettings ){
            
            // extract the settings to setup the app window
            setWindowSize( mSettings->get<Vec2i>( "windowSize" ) );
            setWindowPos( mSettings->get<Vec2i>( "windowPos" ) );
            
            // check if we need to go fullscreen
            setFullScreen( mSettings->get<bool>( "fullscreen" ) );
            
            mBackgroundColor = mSettings->get<Color>( "background" );
        }
    } );
}

void DynamicSettingsApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function. this time we check the return value which is a good practice
    // if we want to detect errors in writing the application interface.
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(DynamicSettingsApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    
    // register the interface to be able to use ci::Vec2i and ci::Color in our settings
    as::registerCinderVec2Type<int>( engine, "Vec2i", "int" );
    as::registerCinderVec2Impl<int>( engine, "Vec2i", "int" );
    as::registerCinderColorTType<float>( engine, "Color", "float" );
    as::registerCinderColorTImpl<float>( engine, "Color", "float" );
    
}


void DynamicSettingsApp::draw()
{
	gl::clear( mBackgroundColor );
}

//! console wrapper
void DynamicSettingsApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( DynamicSettingsApp, RendererGl )
