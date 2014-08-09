#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Perlin.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderPerlinType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Perlin", sizeof(Perlin), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderPerlinImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Perlin", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Perlin>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Perlin", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Perlin>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Perlin", asBEHAVE_CONSTRUCT,
			"void f(const Perlin &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Perlin,const Perlin &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Perlin","Perlin& opAssign(const Perlin &in)", asFUNCTION((as::RegistrationHelper::opAssign<Perlin&,Perlin,Perlin&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Perlin( uint8_t aOctaves = 4 )
		r = engine->RegisterObjectBehaviour( "Perlin", asBEHAVE_CONSTRUCT,
			"void f( uint8 aOctaves = 4 )", asFUNCTION( ( as::RegistrationHelper::constructor<Perlin,uint8_t > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Perlin( uint8_t aOctaves, int32_t aSeed )
		r = engine->RegisterObjectBehaviour( "Perlin", asBEHAVE_CONSTRUCT,
			"void f( uint8 aOctaves, int32 aSeed )", asFUNCTION( ( as::RegistrationHelper::constructor<Perlin,uint8_t ,int32_t > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void setSeed( int32_t aSeed )
		r = engine->RegisterObjectMethod( "Perlin", "void setSeed( int32 aSeed )",
			 asMETHODPR(Perlin,setSeed,(int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: uint8_t getOctaves() const
		r = engine->RegisterObjectMethod( "Perlin", "uint8 getOctaves()",
			 asMETHODPR(Perlin,getOctaves,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setOctaves( uint8_t aOctaves )
		r = engine->RegisterObjectMethod( "Perlin", "void setOctaves( uint8 aOctaves )",
			 asMETHODPR(Perlin,setOctaves,(uint8_t ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float fBm( float v ) const
		r = engine->RegisterObjectMethod( "Perlin", "float fBm( float v )",
			 asMETHODPR(Perlin,fBm,(float )const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float fBm( const Vec2f &v ) const
		r = engine->RegisterObjectMethod( "Perlin", "float fBm( const Vec2f &in v )",
			 asMETHODPR(Perlin,fBm,(const Vec2f &)const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float fBm( float x, float y ) const
		r = engine->RegisterObjectMethod( "Perlin", "float fBm( float x, float y )",
			 asMETHODPR(Perlin,fBm,(float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float fBm( const Vec3f &v ) const
		r = engine->RegisterObjectMethod( "Perlin", "float fBm( const Vec3f &in v )",
			 asMETHODPR(Perlin,fBm,(const Vec3f &)const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float fBm( float x, float y, float z ) const
		r = engine->RegisterObjectMethod( "Perlin", "float fBm( float x, float y, float z )",
			 asMETHODPR(Perlin,fBm,(float ,float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec2f dfBm( const Vec2f &v ) const
		r = engine->RegisterObjectMethod( "Perlin", "Vec2f dfBm( const Vec2f &in v )",
			 asMETHODPR(Perlin,dfBm,(const Vec2f &)const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2f dfBm( float x, float y ) const
		r = engine->RegisterObjectMethod( "Perlin", "Vec2f dfBm( float x, float y )",
			 asMETHODPR(Perlin,dfBm,(float ,float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f dfBm( const Vec3f &v ) const
		r = engine->RegisterObjectMethod( "Perlin", "Vec3f dfBm( const Vec3f &in v )",
			 asMETHODPR(Perlin,dfBm,(const Vec3f &)const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f dfBm( float x, float y, float z ) const
		r = engine->RegisterObjectMethod( "Perlin", "Vec3f dfBm( float x, float y, float z )",
			 asMETHODPR(Perlin,dfBm,(float ,float ,float )const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float noise( float x ) const
		r = engine->RegisterObjectMethod( "Perlin", "float noise( float x )",
			 asMETHODPR(Perlin,noise,(float )const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float noise( float x, float y ) const
		r = engine->RegisterObjectMethod( "Perlin", "float noise( float x, float y )",
			 asMETHODPR(Perlin,noise,(float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float noise( float x, float y, float z ) const
		r = engine->RegisterObjectMethod( "Perlin", "float noise( float x, float y, float z )",
			 asMETHODPR(Perlin,noise,(float ,float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec2f dnoise( float x, float y ) const
		r = engine->RegisterObjectMethod( "Perlin", "Vec2f dnoise( float x, float y )",
			 asMETHODPR(Perlin,dnoise,(float ,float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f dnoise( float x, float y, float z ) const
		r = engine->RegisterObjectMethod( "Perlin", "Vec3f dnoise( float x, float y, float z )",
			 asMETHODPR(Perlin,dnoise,(float ,float ,float )const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );


	}
}
