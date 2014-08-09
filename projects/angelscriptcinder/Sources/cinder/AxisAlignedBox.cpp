#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/AxisAlignedBox.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderAxisAlignedBox3fType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "AxisAlignedBox3f", sizeof(AxisAlignedBox3f), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderAxisAlignedBox3fImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "AxisAlignedBox3f", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<AxisAlignedBox3f>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "AxisAlignedBox3f", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<AxisAlignedBox3f>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "AxisAlignedBox3f", asBEHAVE_CONSTRUCT,
			"void f(const AxisAlignedBox3f &in )", asFUNCTION( ( as::RegistrationHelper::constructor<AxisAlignedBox3f,const AxisAlignedBox3f &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f","AxisAlignedBox3f& opAssign(const AxisAlignedBox3f &in)", asFUNCTION((as::RegistrationHelper::opAssign<AxisAlignedBox3f&,AxisAlignedBox3f,AxisAlignedBox3f&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: AxisAlignedBox3f( const Vec3f &aMin, const Vec3f &aMax )
		r = engine->RegisterObjectBehaviour( "AxisAlignedBox3f", asBEHAVE_CONSTRUCT,
			"void f( const Vec3f &in aMin, const Vec3f &in aMax )", asFUNCTION( ( as::RegistrationHelper::constructor<AxisAlignedBox3f,const Vec3f &,const Vec3f &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: bool intersects( const Ray &ray )
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "bool intersects( const Ray &in ray )",
			 asMETHODPR(AxisAlignedBox3f,intersects,(const Ray &),bool), asCALL_THISCALL ); assert( r >= 0 );

		//  int intersect( const Ray &ray, float intersections[2] )

		// METHOD: Vec3f getCenter() const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "Vec3f getCenter()",
			 asMETHODPR(AxisAlignedBox3f,getCenter,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f getSize() const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "Vec3f getSize()",
			 asMETHODPR(AxisAlignedBox3f,getSize,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void include( const AxisAlignedBox3f &box )
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "void include( const AxisAlignedBox3f &in box )",
			 asMETHODPR(AxisAlignedBox3f,include,(const AxisAlignedBox3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: const Vec3f& getMin() const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "const Vec3f& getMin()",
			 asMETHODPR(AxisAlignedBox3f,getMin,()const,const Vec3f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Vec3f& getMax() const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "const Vec3f& getMax()",
			 asMETHODPR(AxisAlignedBox3f,getMax,()const,const Vec3f&), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3f getNegative( const Vec3f &normal ) const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "Vec3f getNegative( const Vec3f &in normal )",
			 asMETHODPR(AxisAlignedBox3f,getNegative,(const Vec3f &)const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f getPositive( const Vec3f &normal ) const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "Vec3f getPositive( const Vec3f &in normal )",
			 asMETHODPR(AxisAlignedBox3f,getPositive,(const Vec3f &)const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: AxisAlignedBox3f transformed( const Matrix44f &transform ) const
		r = engine->RegisterObjectMethod( "AxisAlignedBox3f", "AxisAlignedBox3f transformed( const Matrix44f &in transform )",
			 asMETHODPR(AxisAlignedBox3f,transformed,(const Matrix44f &)const,AxisAlignedBox3f), asCALL_THISCALL ); assert( r >= 0 );


		//  static bool calcTriangleIntersection( const Ray &ray, const Vec3f &vert0, const Vec3f &vert1, const Vec3f &vert2, float *result )

	}
}
