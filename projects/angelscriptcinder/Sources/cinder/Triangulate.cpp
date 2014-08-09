#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Triangulate.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderTriangulatorType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Triangulator", sizeof(Triangulator), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTriangulatorImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Triangulator", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Triangulator>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Triangulator", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Triangulator>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Triangulator", asBEHAVE_CONSTRUCT,
			"void f(const Triangulator &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Triangulator,const Triangulator &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Triangulator","Triangulator& opAssign(const Triangulator &in)", asFUNCTION((as::RegistrationHelper::opAssign<Triangulator&,Triangulator,Triangulator&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef enum Winding Winding



		// CONSTRUCTOR: Triangulator( const Path2d &path, float approximationScale = 1.0f )
		r = engine->RegisterObjectBehaviour( "Triangulator", asBEHAVE_CONSTRUCT,
			"void f( const Path2d &in path, float approximationScale = 1.0f )", asFUNCTION( ( as::RegistrationHelper::constructor<Triangulator,const Path2d &,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: Triangulator( const Shape2d &shape, float approximationScale = 1.0f )
		r = engine->RegisterObjectBehaviour( "Triangulator", asBEHAVE_CONSTRUCT,
			"void f( const Shape2d &in shape, float approximationScale = 1.0f )", asFUNCTION( ( as::RegistrationHelper::constructor<Triangulator,const Shape2d &,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: Triangulator( const PolyLine2f &polyLine )
		r = engine->RegisterObjectBehaviour( "Triangulator", asBEHAVE_CONSTRUCT,
			"void f( const PolyLine2f &in polyLine )", asFUNCTION( ( as::RegistrationHelper::constructor<Triangulator,const PolyLine2f &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: void addShape( const Shape2d &path, float approximationScale = 1.0f )
		r = engine->RegisterObjectMethod( "Triangulator", "void addShape( const Shape2d &in path, float approximationScale = 1.0f )",
			 asMETHODPR(Triangulator,addShape,(const Shape2d &,float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void addPath( const Path2d &path, float approximationScale = 1.0f )
		r = engine->RegisterObjectMethod( "Triangulator", "void addPath( const Path2d &in path, float approximationScale = 1.0f )",
			 asMETHODPR(Triangulator,addPath,(const Path2d &,float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void addPolyLine( const PolyLine2f &polyLine )
		r = engine->RegisterObjectMethod( "Triangulator", "void addPolyLine( const PolyLine2f &in polyLine )",
			 asMETHODPR(Triangulator,addPolyLine,(const PolyLine2f &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: TriMesh2d calcMesh( int winding = 0 )
		r = engine->RegisterObjectMethod( "Triangulator", "TriMesh2d calcMesh( int winding = 0 )",
			 asMETHOD(Triangulator,calcMesh), asCALL_THISCALL ); assert( r >= 0 );


	}
}
