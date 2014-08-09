#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Quaternion.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderQuaternionType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Quaternion<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderQuaternionImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Quaternion<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Quaternion<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,const Quaternion<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Quaternion<T>&,Quaternion<T>,Quaternion<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type

        
		//template<typename FromT>
		//  Quaternion( const Quaternion<FromT>& q ) : w( static_cast<T>( q.w ) ), v( q.v )

		// CONSTRUCTOR: Quaternion( T aW, T x, T y, T z ): w( aW ), v( x, y, z )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " aW, " + type + " x, " + type + " y, " + type + " z )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,T ,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: Quaternion( const Vec3<T> &axis, T radians )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + " &in axis, " + type + " radians )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,const Vec3<T> &,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Quaternion( const Vec3<T> &from, const Vec3<T> &to )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + " &in from, const Vec3" + suffix + " &in to )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,const Vec3<T> &,const Vec3<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: Quaternion( T xRotation, T yRotation, T zRotation )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " xRotation, " + type + " yRotation, " + type + " zRotation )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Quaternion( const Matrix33<T> &m )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Matrix33" + suffix + " &in m )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,const Matrix33<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Quaternion( const Matrix44<T> &m )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Matrix44" + suffix + " &in m )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Quaternion<T>,const Matrix44<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//template<typename Y>
		//  explicit Quaternion( const Y &v )
		//  : w( QUATCONV<Quaternion<typename Quaternion::TYPE>,Y>::getW( v ) ), v( QUATCONV<typename Quaternion::TYPE,Y>::getX( v ), QUATCONV<typename Quaternion::TYPE,Y>::getY( v ), QUATCONV<typename Quaternion::TYPE,Y>::getZ( v ) )



		// METHOD: Vec3<T> getAxis() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " getAxis()" ).c_str(),
			 asMETHODPR(Quaternion<T>,getAxis,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: T getAngle() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getAngle()" ).c_str(),
			 asMETHODPR(Quaternion<T>,getAngle,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T getPitch() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getPitch()" ).c_str(),
			 asMETHODPR(Quaternion<T>,getPitch,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T getYaw() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getYaw()" ).c_str(),
			 asMETHODPR(Quaternion<T>,getYaw,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T getRoll() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getRoll()" ).c_str(),
			 asMETHODPR(Quaternion<T>,getRoll,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T dot( const Quaternion<T> &quat ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " dot( const " + name + " &in quat )" ).c_str(),
			 asMETHODPR(Quaternion<T>,dot,(const Quaternion<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T length() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " length()" ).c_str(),
			 asMETHODPR(Quaternion<T>,length,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T lengthSquared() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " lengthSquared()" ).c_str(),
			 asMETHODPR(Quaternion<T>,lengthSquared,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Quaternion<T> inverse() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverse()" ).c_str(),
			 asMETHODPR(Quaternion<T>,inverse,()const,Quaternion<T>), asCALL_THISCALL ); assert( r >= 0 );


		// PROPERTY: */

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderQuaternionType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderQuaternionImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderQuaternionType<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderQuaternionImpl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
