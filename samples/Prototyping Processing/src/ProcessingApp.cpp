#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"

#include "AssetManager.h"

#include "Processing.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ProcessingApp : public AppNative {
public:
	void setup();
	void draw();
    
    void mouseDown( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseUp( MouseEvent event );
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our processing file
    as::ScriptRef mProcessing;
};

void ProcessingApp::setup()
{
    getWindow()->setAlwaysOnTop();
    
    setupScriptEngine();
    
    // watch our sketch for change and reloads it when needed
    AssetManager::load( "sketch.pde", [this]( DataSourceRef sketch ){
        mProcessing = as::Script::create( sketch, "" );
        
        if( mProcessing ){
            mProcessing->call( "void setup()" );
        }
    });
}

void ProcessingApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(ProcessingApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    
    // register processing interface
    processing::registerProcessing( engine );
    
}


void ProcessingApp::draw()
{
    if( mProcessing ){
        mProcessing->call( "void draw()" );
    }
}

void ProcessingApp::mouseDown( MouseEvent event )
{
    if( mProcessing ){
        mProcessing->call( "void mousePressed( int x, int y, int button)", event.getX(), event.getY(), event.isLeft() ? 1 : event.isRight() ? 2 : 3 );
    }
}

void ProcessingApp::mouseUp( MouseEvent event )
{
    if( mProcessing ){
        mProcessing->call( "void mouseReleased( int x, int y, int button)", event.getX(), event.getY(), event.isLeft() ? 1 : event.isRight() ? 2 : 3 );
    }
}

void ProcessingApp::mouseDrag( MouseEvent event )
{
    if( mProcessing ){
        mProcessing->call( "void mouseDragged( int x, int y, int button)", event.getX(), event.getY(), event.isLeft() ? 1 : event.isRight() ? 2 : 3 );
    }
}

void ProcessingApp::mouseMove( MouseEvent event )
{
    if( mProcessing ){
        mProcessing->call( "void mouseMoved( int x, int y )", event.getX(), event.getY() );
    }
}

//! console wrapper
void ProcessingApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( ProcessingApp, RendererGl )
