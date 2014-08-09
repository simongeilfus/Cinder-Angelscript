#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Sphere.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderSphereType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Sphere", sizeof(Sphere), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderSphereImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Sphere", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Sphere>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Sphere", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Sphere>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Sphere", asBEHAVE_CONSTRUCT,
			"void f(const Sphere &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Sphere,const Sphere &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Sphere","Sphere& opAssign(const Sphere &in)", asFUNCTION((as::RegistrationHelper::opAssign<Sphere&,Sphere,Sphere&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Sphere( const Vec3f &aCenter, float aRadius ) : mCenter( aCenter ), mRadius( aRadius )
		r = engine->RegisterObjectBehaviour( "Sphere", asBEHAVE_CONSTRUCT,
			"void f( const Vec3f &in aCenter, float aRadius )", asFUNCTION( ( as::RegistrationHelper::constructor<Sphere,const Vec3f &,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: float getRadius() const
		r = engine->RegisterObjectMethod( "Sphere", "float getRadius()",
			 asMETHODPR(Sphere,getRadius,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setRadius( float radius )
		r = engine->RegisterObjectMethod( "Sphere", "void setRadius( float radius )",
			 asMETHODPR(Sphere,setRadius,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: const Vec3f& getCenter() const
		r = engine->RegisterObjectMethod( "Sphere", "const Vec3f& getCenter()",
			 asMETHODPR(Sphere,getCenter,()const,const Vec3f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const void setCenter( const Vec3f &center )
		r = engine->RegisterObjectMethod( "Sphere", "const void setCenter( const Vec3f &in center )",
			 asMETHODPR(Sphere,setCenter,(const Vec3f &),const void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool intersects( const Ray &ray )
		r = engine->RegisterObjectMethod( "Sphere", "bool intersects( const Ray &in ray )",
			 asMETHODPR(Sphere,intersects,(const Ray &),bool), asCALL_THISCALL ); assert( r >= 0 );

		//  int intersect( const Ray &ray, float *intersection )

		//  static Sphere calculateBoundingSphere( const std::vector<Vec3f> &points )

	}
}
