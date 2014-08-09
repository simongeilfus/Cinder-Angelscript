#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "script.h"
#include "angelscriptcinder.h"

#include "AssetManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ScriptApp : public AppNative {
public:
	void setup();
	void draw();
    
    void renderUI();
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our script file
    as::ScriptRef mScript;
    
    //! Variables that are read/write accessible in scripts
    MouseEvent mMouse;
    MouseEvent mPrevMouse;
    
    //! Button callbacks
    vector<function<void()>>    mButtonCallbacks;
    
    //! Sliders values
    ColorA                      mColor;
    
    vector<Vec3f>               mCircles;
};

void ScriptApp::setup()
{
    getWindow()->setAlwaysOnTop();
    
    setupScriptEngine();
    
    // store the MouseEvents to be shared with the script
    // and connect the different signals
	getWindow()->getSignalMouseUp().connect( [this]( MouseEvent event ){ mMouse = MouseEvent(); } );
	getWindow()->getSignalMouseMove().connect( [this]( MouseEvent event ){ mMouse = event; } );
	getWindow()->getSignalMouseDown().connect( [this]( MouseEvent event ){ mMouse = event; } );
	getWindow()->getSignalMouseDrag().connect( [this]( MouseEvent event ){ mMouse = event; } );
    getWindow()->getSignalPostDraw().connect( [this]{ mPrevMouse = mMouse; } );
    
    // prepare some callbacks to be shared with our script
    mButtonCallbacks.push_back( [this](){
        for( int i = 0 ; i < 15; i++ ){
            mCircles.push_back( Vec3f( randFloat() * getWindowWidth(), randFloat() * getWindowHeight(), randFloat() * 250.0f ) );
        }
    } );
    mButtonCallbacks.push_back( [this](){
        for( int i = 0 ; i < 1250; i++ ){
            mCircles.push_back( Vec3f( randFloat() * getWindowWidth(), randFloat() * getWindowHeight(), randFloat() * 15.0f ) );
        }
    } );
    mButtonCallbacks.push_back( [this](){
        for( int i = 0 ; i < 150; i++ ){
            mCircles.push_back( Vec3f( randFloat() * getWindowWidth(), randFloat() * getWindowHeight(), randFloat() * 50.0f ) );
        }
    } );
    
    // register script variables
    as::Script::setAddress( "MouseEvent mMouse", &mMouse );
    as::Script::setAddress( "MouseEvent mPrevMouse", &mPrevMouse );
    as::Script::setAddress( "function callback0", &mButtonCallbacks[0] );
    as::Script::setAddress( "function callback1", &mButtonCallbacks[1] );
    as::Script::setAddress( "function callback2", &mButtonCallbacks[2] );
    as::Script::setAddress( "float value0", &mColor.r );
    as::Script::setAddress( "float value1", &mColor.g );
    as::Script::setAddress( "float value2", &mColor.b );
    
    // watch our script for change and reloads it when needed
    AssetManager::load( "main.asc", [this]( DataSourceRef sketch ){
        mScript = as::Script::create( sketch, "" );
        
        if( mScript ){
            mScript->call( "void setup()" );
        }
    });
    
    // set initial color
    mColor = ColorA( 0.85f, 0.15f, 0.05f, 0.3f );
}

void ScriptApp::renderUI()
{
    if( mScript ){
        mScript->call( "void renderUI()" );
    }
}

void ScriptApp::draw()
{
    gl::clear( ColorA::gray( 0.75f ) );
    
    gl::enableAdditiveBlending();
    
    // iterate the circle list, render them and remove
    // the one that have a size below zero
    gl::color( mColor );
    for( vector<Vec3f>::iterator it = mCircles.begin(); it != mCircles.end(); ){
        auto &circle = *it;
        
        // render
        gl::drawSolidCircle( circle.xy(), circle.z );
        
        // shrink
        circle.z *= 0.985f;
        
        // erase
        if( circle.z < 0 ){
            it = mCircles.erase( it );
        }
        else ++it;
    }
    
    // render our scripted ui
    renderUI();
    
    // blend a fullscreen colored quad on top of everything
    gl::enableAdditiveBlending();
    gl::color( mColor );
    gl::drawSolidRect( getWindowBounds() );
    gl::disableAlphaBlending();
}


void ScriptApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    // register a print function.
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(ScriptApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    
    // register function<void()> for our button callbacks
    r = engine->RegisterObjectType( "function",  sizeof(std::function<void()>), asOBJ_VALUE | asOBJ_POD ); assert( r >= 0 );
    r = engine->RegisterObjectMethod( "function", "void opCall()", asMETHOD( function<void()>, operator() ), asCALL_THISCALL ); assert( r >= 0 );
    
    // register cinder
    as::registerCinder( engine );
    
}

//! console wrapper
void ScriptApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( ScriptApp, RendererGl )
