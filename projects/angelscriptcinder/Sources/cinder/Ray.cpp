#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Ray.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderRayType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Ray", sizeof(Ray), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderRayImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Ray", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Ray>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Ray", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Ray>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Ray", asBEHAVE_CONSTRUCT,
			"void f(const Ray &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Ray,const Ray &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Ray","Ray& opAssign(const Ray &in)", asFUNCTION((as::RegistrationHelper::opAssign<Ray&,Ray,Ray&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Ray( const Vec3f &aOrigin, const Vec3f &aDirection ) : mOrigin( aOrigin )
		r = engine->RegisterObjectBehaviour( "Ray", asBEHAVE_CONSTRUCT,
			"void f( const Vec3f &in aOrigin, const Vec3f &in aDirection )", asFUNCTION( ( as::RegistrationHelper::constructor<Ray,const Vec3f &,const Vec3f &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void setOrigin( const Vec3f &aOrigin )
		r = engine->RegisterObjectMethod( "Ray", "void setOrigin( const Vec3f &in aOrigin )",
			 asMETHODPR(Ray,setOrigin,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Vec3f& getOrigin() const
		r = engine->RegisterObjectMethod( "Ray", "const Vec3f& getOrigin()",
			 asMETHODPR(Ray,getOrigin,()const,const Vec3f&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setDirection( const Vec3f &aDirection )
		r = engine->RegisterObjectMethod( "Ray", "void setDirection( const Vec3f &in aDirection )",
			 asMETHODPR(Ray,setDirection,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: const Vec3f& getDirection() const
		r = engine->RegisterObjectMethod( "Ray", "const Vec3f& getDirection()",
			 asMETHODPR(Ray,getDirection,()const,const Vec3f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Vec3f& getInverseDirection() const
		r = engine->RegisterObjectMethod( "Ray", "const Vec3f& getInverseDirection()",
			 asMETHODPR(Ray,getInverseDirection,()const,const Vec3f&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: char getSignX() const
		r = engine->RegisterObjectMethod( "Ray", "int8 getSignX()",
			 asMETHODPR(Ray,getSignX,()const,char), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: char getSignY() const
		r = engine->RegisterObjectMethod( "Ray", "int8 getSignY()",
			 asMETHODPR(Ray,getSignY,()const,char), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: char getSignZ() const
		r = engine->RegisterObjectMethod( "Ray", "int8 getSignZ()",
			 asMETHODPR(Ray,getSignZ,()const,char), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f calcPosition( float t ) const
		r = engine->RegisterObjectMethod( "Ray", "Vec3f calcPosition( float t )",
			 asMETHODPR(Ray,calcPosition,(float )const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );


		//  bool calcTriangleIntersection( const Vec3f &vert0, const Vec3f &vert1, const Vec3f &vert2, float *result ) const
		//  bool calcPlaneIntersection( const Vec3f &origin, const Vec3f &normal, float *result ) const

	}
}
