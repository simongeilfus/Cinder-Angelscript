#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Script.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HelloFromStringApp : public AppNative {
public:
	void setup();
};

void HelloFromStringApp::setup()
{
    // create a script that represents a function named "hello"
    // by default this angelscript wrapper doesn't execute the code loaded.
    as::ScriptRef script = as::Script::create( "string who(){\
                                              return \"Angelscript\";\
                                              }", "" );

    // you have to call the function and cast what the function returns to
    // a string. You also have to specify the full function signature and
    // not only its name.
    console() << "Hello " << script->call<string>( "string who()" ) << endl;
    
    // exit
    quit();
}

CINDER_APP_NATIVE( HelloFromStringApp, RendererGl )
