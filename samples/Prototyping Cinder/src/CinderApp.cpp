#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"
#include "angelscriptcinder.h"

#include "AssetManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderApp : public AppNative {
public:
	void setup();
    void update();
	void draw();
    
    void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseUp( MouseEvent event );
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our script file
    as::ScriptRef mScript;
};

void CinderApp::setup()
{
    getWindow()->setAlwaysOnTop();
    
    setupScriptEngine();
    
    // watch our sketch for change and reloads it when needed
    AssetManager::load( "main.asc", [this]( DataSourceRef sketch ){
        mScript = as::Script::create( sketch, "" );
        
        if( mScript ){
            mScript->call( "void setup()" );
        }
    });
}

void CinderApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function. this time we check the return value which is a good practice
    // if we want to detect errors in writing the application interface.
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(CinderApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    
    // register cinder
    as::registerCinder( engine );
    
}


void CinderApp::update()
{
    if( mScript ){
        mScript->call( "void update()" );
    }
}

void CinderApp::draw()
{
    if( mScript ){
        mScript->call( "void draw()" );
    }
}

void CinderApp::mouseDown( MouseEvent event )
{
    if( mScript ){
        mScript->call( "void mouseDown( MouseEvent event )", event );
    }
}

void CinderApp::mouseUp( MouseEvent event )
{
    if( mScript ){
        mScript->call( "void mouseUp( MouseEvent event )", event );
    }
}

void CinderApp::mouseDrag( MouseEvent event )
{
    if( mScript ){
        mScript->call( "void mouseDrag( MouseEvent event )", event );
    }
}

void CinderApp::mouseMove( MouseEvent event )
{
    if( mScript ){
        mScript->call( "void mouseMove( MouseEvent event )", event );
    }
}

//! console wrapper
void CinderApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( CinderApp, RendererGl )
