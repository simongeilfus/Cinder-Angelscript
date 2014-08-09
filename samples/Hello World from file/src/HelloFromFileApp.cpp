#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Script.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HelloFromFileApp : public AppNative {
public:
	void setup();
};

void HelloFromFileApp::setup()
{
    // same as previous example, exept we are loading the script from disk
    // and not from memory.
    as::ScriptRef script = as::Script::create( loadAsset( "Hello.asc" ), "" );
    
    // call the "who" method and output what it returns.
    console() << "Hello " << script->call<string>( "string who()" ) << script->call<string>( "string test()" ) << endl;
    
    // exit
    quit();
}

CINDER_APP_NATIVE( HelloFromFileApp, RendererGl )
