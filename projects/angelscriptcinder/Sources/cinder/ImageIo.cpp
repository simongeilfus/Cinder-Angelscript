#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/ImageIo.h"


using namespace std;
using namespace ci;

namespace as {
    
	void registerCinderImageIoType( asIScriptEngine* engine, bool useNamespaces )
	{
		/*int r;
        
		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        
		// Register the ObjectType
		r = engine->RegisterObjectType( "KeyEvent", sizeof(KeyEvent), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_POD ); assert( r >= 0 );
        
        
		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}*/
        
	}
    
    
    ImageSourceRef	wrapped_loadImage( const string &path )
    {
        ImageSourceRef image;
        cout << "loadimage " << path << endl;
        try {
            image = loadImage( path );
        }
        catch( ... ){
            
        }
        
        return image;
    }
    
	void registerCinderImageIoImpl( asIScriptEngine* engine, bool useNamespaces )
	{
        
        int r;
        
        /*
		r = engine->RegisterObjectType( "ImageSourceRef", sizeof(ImageSourceRef), asOBJ_POD ); assert( r >= 0 );
        
        r = engine->RegisterGlobalFunction("void loadImage(const string &in path)", asFUNCTION( wrapped_loadImage ), asCALL_CDECL ); assert( r >= 0 );
        */
		/*int r;
        
		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        
        
		// METHOD: char getChar() const
		r = engine->RegisterObjectMethod( "KeyEvent", "int8 getChar()",
                                         asMETHODPR(KeyEvent,getChar,()const,char), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: uint32_t getCharUtf32() const
		r = engine->RegisterObjectMethod( "KeyEvent", "uint32 getCharUtf32()",
                                         asMETHODPR(KeyEvent,getCharUtf32,()const,uint32_t), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: int getCode() const
		r = engine->RegisterObjectMethod( "KeyEvent", "int getCode()",
                                         asMETHODPR(KeyEvent,getCode,()const,int), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: bool isShiftDown() const
		r = engine->RegisterObjectMethod( "KeyEvent", "bool isShiftDown()",
                                         asMETHODPR(KeyEvent,isShiftDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: bool isAltDown() const
		r = engine->RegisterObjectMethod( "KeyEvent", "bool isAltDown()",
                                         asMETHODPR(KeyEvent,isAltDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: bool isControlDown() const
		r = engine->RegisterObjectMethod( "KeyEvent", "bool isControlDown()",
                                         asMETHODPR(KeyEvent,isControlDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: bool isMetaDown() const
		r = engine->RegisterObjectMethod( "KeyEvent", "bool isMetaDown()",
                                         asMETHODPR(KeyEvent,isMetaDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: bool isAccelDown() const
		r = engine->RegisterObjectMethod( "KeyEvent", "bool isAccelDown()",
                                         asMETHODPR(KeyEvent,isAccelDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: int getNativeKeyCode() const
		r = engine->RegisterObjectMethod( "KeyEvent", "int getNativeKeyCode()",
                                         asMETHODPR(KeyEvent,getNativeKeyCode,()const,int), asCALL_THISCALL ); assert( r >= 0 );
        
        */
	}
}
