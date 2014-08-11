#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"

#include "AssetManager.h"

#include "script.h"
#include "angelscriptcinder.h"

// angelscript serializer addon
#include <serializer/serializer.h>


using namespace ci;
using namespace ci::app;
using namespace std;

// serializing helper class
template<typename T>
struct SerializedT : public CUserType
{
    void Store(CSerializedValue *val, void *ptr)
    {
        val->SetUserData( new T(*(T*)ptr) );
    }
    void Restore(CSerializedValue *val, void *ptr)
    {
        T *buffer = (T*)val->GetUserData();
        *(T*)ptr = *buffer;
    }
    void CleanupUserData(CSerializedValue *val)
    {
        T *buffer = (T*)val->GetUserData();
        delete buffer;
    }
};

class SaveScriptStateApp : public AppNative {
  public:
	void setup();
	void draw();
    
    //! setup the engine, registers the app interface and load scripts
	void setupScriptEngine();
    
    //! console wrapper
    void print( const std::string &s );
    
    //! our script file
    as::ScriptRef mScript;
    
    //! save state flag
    bool mSaveState;
};

void SaveScriptStateApp::setup()
{
    mSaveState = true;
    
    getWindow()->setAlwaysOnTop();
    
    setupScriptEngine();
    
    // watch our sketch for change and reloads it when needed
    AssetManager::load( "main.asc", [this]( DataSourceRef script ){
        
        // if it is the first time just create the script
        if( !mScript ){
            mScript = as::Script::create( script, "Main" );
        }
        // if not, start by test compiling the script
        else if( as::Script::create( script, "TEST" ) ){
            
            // save some global variable states
            // CSerializer doesn't save all types by default
            // instead the user has to provide a Serializer class
            // useful if you want to control types that has a more
            // complicated initialization.
            CSerializer serializer;
            if( mSaveState ){
                serializer.AddUserType( new SerializedT<float>, "float" );
                serializer.AddUserType( new SerializedT<int>, "int" );
                serializer.AddUserType( new SerializedT<Vec2f>, "Vec2f" );
                serializer.AddUserType( new SerializedT<Perlin>, "Perlin" );
                serializer.Store( mScript->getModule() );
            }
            
            // clear the script module
            mScript->clear();
            
            // load the script from the DataSourceRef we got from AssetManager
            mScript->loadFromFile( script );
            
            // build/compile the script
            mScript->build();
            
            // restore the state we saved before building the new script
            if( mSaveState ){
                serializer.Restore( mScript->getModule() );
            }
        }
    });
    
    // get our rendering right
    gl::enableAlphaBlending();
    
    // invert save state flag when pressing space
    getWindow()->getSignalKeyDown().connect( [this](KeyEvent event){ if( event.getCode() == KeyEvent::KEY_SPACE ) mSaveState = !mSaveState; } );
    
    // send mousedrag to the script
    getWindow()->getSignalMouseDrag().connect( [this](MouseEvent event){ if( mScript ) mScript->call( "void mouseDragged(MouseEvent event)", event ); } );
}


void SaveScriptStateApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    
    if( mScript ){
        mScript->call( "void draw()" );
    }
    
    if( mSaveState ){
        gl::drawString( "State saving between builds: ENABLED", Vec2f( 20, 20 ), ColorA::gray( 0.6f ) );
    }
    else {
        gl::drawString( "State saving between builds: DISABLED", Vec2f( 20, 20 ), ColorA::gray( 0.6f ) );
    }
}

void SaveScriptStateApp::setupScriptEngine()
{
    // get a reference to our global engine.
    asIScriptEngine* engine = as::Script::getEngine();
    
    int r = engine->RegisterGlobalFunction("void print( const string &in )", asMETHOD(SaveScriptStateApp,print), asCALL_THISCALL_ASGLOBAL, this );  assert( r >= 0 );
    r = engine->RegisterGlobalFunction("float min( float a, float b )", asFUNCTION(math<float>::min), asCALL_CDECL );  assert( r >= 0 );
    
    as::registerCinder( engine );
}

//! console wrapper
void SaveScriptStateApp::print( const std::string &s )
{
    console() << s << endl;
}

CINDER_APP_NATIVE( SaveScriptStateApp, RendererGl )
