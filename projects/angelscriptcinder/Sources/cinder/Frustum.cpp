#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Frustum.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderFrustumType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Frustum<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderFrustumImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Frustum<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Frustum<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Frustum<T>,const Frustum<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Frustum<T>&,Frustum<T>,Frustum<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: enum

		// PROPERTY: public:
		// CONSTRUCTOR: Frustum( const Camera &cam )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Camera &in cam )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Frustum<T>,const Camera &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: void set( const Camera &cam )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const Camera &in cam )" ).c_str(),
			 asMETHODPR(Frustum<T>,set,(const Camera &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void set( const Camera &cam, const Vec3<T> &ntl, const Vec3<T> &ntr, const Vec3<T> &nbl, const Vec3<T> &nbr )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const Camera &in cam, const Vec3" + suffix + " &in ntl, const Vec3" + suffix + " &in ntr, const Vec3" + suffix + " &in nbl, const Vec3" + suffix + " &in nbr )" ).c_str(),
			 asMETHODPR(Frustum<T>,set,(const Camera &,const Vec3<T> &,const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool contains( const Vec3<T> &loc ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const Vec3" + suffix + " &in loc )" ).c_str(),
			 asMETHODPR(Frustum<T>,contains,(const Vec3<T> &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool contains( const Sphere &sphere ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const Sphere &in sphere )" ).c_str(),
			 asMETHODPR(Frustum<T>,contains,(const Sphere &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool contains( const Vec3<T> &center, T radius ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const Vec3" + suffix + " &in center, " + type + " radius )" ).c_str(),
			 asMETHODPR(Frustum<T>,contains,(const Vec3<T> &,T )const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool contains( const AxisAlignedBox3f &box ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const AxisAlignedBox3f &in box )" ).c_str(),
			 asMETHODPR(Frustum<T>,contains,(const AxisAlignedBox3f &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool contains( const Vec3<T> &center, const Vec3<T> &size ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const Vec3" + suffix + " &in center, const Vec3" + suffix + " &in size )" ).c_str(),
			 asMETHODPR(Frustum<T>,contains,(const Vec3<T> &,const Vec3<T> &)const,bool), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: bool intersects( const Vec3<T> &loc ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool intersects( const Vec3" + suffix + " &in loc )" ).c_str(),
			 asMETHODPR(Frustum<T>,intersects,(const Vec3<T> &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool intersects( const Sphere &sphere ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool intersects( const Sphere &in sphere )" ).c_str(),
			 asMETHODPR(Frustum<T>,intersects,(const Sphere &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool intersects( const Vec3<T> &center, T radius ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool intersects( const Vec3" + suffix + " &in center, " + type + " radius )" ).c_str(),
			 asMETHODPR(Frustum<T>,intersects,(const Vec3<T> &,T )const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool intersects( const AxisAlignedBox3f &box ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool intersects( const AxisAlignedBox3f &in box )" ).c_str(),
			 asMETHODPR(Frustum<T>,intersects,(const AxisAlignedBox3f &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool intersects( const Vec3<T> &center, const Vec3<T> &size ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool intersects( const Vec3" + suffix + " &in center, const Vec3" + suffix + " &in size )" ).c_str(),
			 asMETHODPR(Frustum<T>,intersects,(const Vec3<T> &,const Vec3<T> &)const,bool), asCALL_THISCALL ); assert( r >= 0 );



	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderFrustumType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderFrustumImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderFrustumType<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderFrustumImpl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
