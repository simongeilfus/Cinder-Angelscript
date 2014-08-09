#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Plane.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderPlaneType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Plane<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderPlaneImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Plane<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Plane<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Plane<T>,const Plane<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Plane<T>&,Plane<T>,Plane<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Plane( const Vec3<T> &v1, const Vec3<T> &v2, const Vec3<T> &v3 )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + " &in v1, const Vec3" + suffix + " &in v2, const Vec3" + suffix + " &in v3 )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Plane<T>,const Vec3<T> &,const Vec3<T> &,const Vec3<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Plane( const Vec3<T> &point, const Vec3<T> &normal )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + " &in point, const Vec3" + suffix + " &in normal )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Plane<T>,const Vec3<T> &,const Vec3<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Plane( T a, T b, T c, T d )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " a, " + type + " b, " + type + " c, " + type + " d )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Plane<T>,T ,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: void set( const Vec3<T> &v1, const Vec3<T> &v2, const Vec3<T> &v3 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const Vec3" + suffix + " &in v1, const Vec3" + suffix + " &in v2, const Vec3" + suffix + " &in v3 )" ).c_str(),
			 asMETHODPR(Plane<T>,set,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void set( const Vec3<T> &point, const Vec3<T> &normal )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const Vec3" + suffix + " &in point, const Vec3" + suffix + " &in normal )" ).c_str(),
			 asMETHODPR(Plane<T>,set,(const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void set( T a, T b, T c, T d )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " a, " + type + " b, " + type + " c, " + type + " d )" ).c_str(),
			 asMETHODPR(Plane<T>,set,(T ,T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3<T> getPoint() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " getPoint()" ).c_str(),
			 asMETHODPR(Plane<T>,getPoint,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Vec3<T>& getNormal() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "const Vec3" + suffix + "& getNormal()" ).c_str(),
			 asMETHODPR(Plane<T>,getNormal,()const,const Vec3<T>&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getDistance() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getDistance()" ).c_str(),
			 asMETHODPR(Plane<T>,getDistance,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T distance( const Vec3<T> &p ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distance( const Vec3" + suffix + " &in p )" ).c_str(),
			 asMETHODPR(Plane<T>,distance,(const Vec3<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3<T> reflectPoint( const Vec3<T> &p ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " reflectPoint( const Vec3" + suffix + " &in p )" ).c_str(),
			 asMETHODPR(Plane<T>,reflectPoint,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3<T> reflectVector( const Vec3<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " reflectVector( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Plane<T>,reflectVector,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );


		// PROPERTY: Vec3<T> mNormal
		// PROPERTY: T mDistance
	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderPlaneType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderPlaneImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderPlaneType<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderPlaneImpl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
