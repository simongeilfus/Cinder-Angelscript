#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Clipboard.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderClipboardType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Clipboard", sizeof(Clipboard), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderClipboardImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Clipboard", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Clipboard>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Clipboard", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Clipboard>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Clipboard", asBEHAVE_CONSTRUCT,
			"void f(const Clipboard &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Clipboard,const Clipboard &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Clipboard","Clipboard& opAssign(const Clipboard &in)", asFUNCTION((as::RegistrationHelper::opAssign<Clipboard&,Clipboard,Clipboard&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// STATIC METHOD: bool hasString()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Clipboard" : "Clipboard" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "bool hasString()",
			 asFUNCTIONPR(Clipboard::hasString,(),bool), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: bool hasImage()
		r = engine->RegisterGlobalFunction( "bool hasImage()",
			 asFUNCTIONPR(Clipboard::hasImage,(),bool), asCALL_CDECL ); assert( r >= 0 );



		//  static std::string getString()

		// STATIC METHOD: ImageSourceRef getImage()
/*		r = engine->RegisterGlobalFunction( "ImageSourceRef getImage()",
			 asFUNCTIONPR(Clipboard::getImage,(),ImageSourceRef), asCALL_CDECL ); assert( r >= 0 );

*/

		//  static void setString( const std::string &str )

		//  static void setImage( ImageSourceRef image, ImageTarget::Options options = ImageTarget::Options() )
		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
