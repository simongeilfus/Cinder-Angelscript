#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "script.h"

#include "AssetManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class GetScriptVariableApp : public AppNative {
public:
	void setup();
    
    //! our script file
    as::ScriptRef mScript;
    
    float* sTime;
};

void GetScriptVariableApp::setup()
{
    // watch our script for change and reloads it when needed
    AssetManager::load( "main.asc", [this]( DataSourceRef sketch ){
        mScript = as::Script::create( sketch, "" );
        
        if( mScript ){
            mScript->call( "void setup()" );
            
            // grab our script variable and output it to the console
            string res = mScript->get<string>( "data" );
            console() << res << endl;
        }
    });
    
    // clear out the window with black
	getWindow()->getSignalDraw().connect( [this] { gl::clear(); } );
}

CINDER_APP_NATIVE( GetScriptVariableApp, RendererGl )
