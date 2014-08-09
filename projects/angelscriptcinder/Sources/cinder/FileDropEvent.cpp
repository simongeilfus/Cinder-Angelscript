#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Vector.h"
#include "cinder/app/FileDropEvent.h"


using namespace std;
using namespace ci;
using namespace ci::app;

namespace as {

	void registerCinderFileDropEventType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "FileDropEvent", sizeof(FileDropEvent), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_POD ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderFileDropEventImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// METHOD: int getX() const
		r = engine->RegisterObjectMethod( "FileDropEvent", "int getX()",
			 asMETHODPR(FileDropEvent,getX,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getY() const
		r = engine->RegisterObjectMethod( "FileDropEvent", "int getY()",
			 asMETHODPR(FileDropEvent,getY,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getPos() const
		r = engine->RegisterObjectMethod( "FileDropEvent", "Vec2i getPos()",
			 asMETHODPR(FileDropEvent,getPos,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );



		//  const std::vector<fs::path>& getFiles() const

		// METHOD: size_t getNumFiles() const
		r = engine->RegisterObjectMethod( "FileDropEvent", "uint getNumFiles()",
			 asMETHODPR(FileDropEvent,getNumFiles,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		//  const fs::path& getFile( size_t index ) const

	}
}
