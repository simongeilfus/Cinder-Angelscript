#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Rand.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderRandType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Rand", sizeof(Rand), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderRandImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Rand", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Rand>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Rand", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Rand>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Rand", asBEHAVE_CONSTRUCT,
			"void f(const Rand &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Rand,const Rand &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Rand","Rand& opAssign(const Rand &in)", asFUNCTION((as::RegistrationHelper::opAssign<Rand&,Rand,Rand&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : mBase( 214u ), mHaveNextNextGaussian( false )


		// CONSTRUCTOR: Rand( unsigned long seed )
		r = engine->RegisterObjectBehaviour( "Rand", asBEHAVE_CONSTRUCT,
			"void f( uint seed )", asFUNCTION( ( as::RegistrationHelper::constructor<Rand,unsigned long > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : mBase( seed ), mHaveNextNextGaussian( false )



		// METHOD: void seed( unsigned long seedValue )
		r = engine->RegisterObjectMethod( "Rand", "void seed( uint seedValue )",
			 asMETHODPR(Rand,seed,(unsigned long ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool nextBool()
		r = engine->RegisterObjectMethod( "Rand", "bool nextBool()",
			 asMETHODPR(Rand,nextBool,(),bool), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: int32_t nextInt()
		r = engine->RegisterObjectMethod( "Rand", "int32 nextInt()",
			 asMETHODPR(Rand,nextInt,(),int32_t), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: uint32_t nextUint()
		r = engine->RegisterObjectMethod( "Rand", "uint32 nextUint()",
			 asMETHODPR(Rand,nextUint,(),uint32_t), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: int32_t nextInt( int32_t v )
		r = engine->RegisterObjectMethod( "Rand", "int32 nextInt( int32 v )",
			 asMETHODPR(Rand,nextInt,(int32_t ),int32_t), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: uint32_t nextUint( uint32_t v )
		r = engine->RegisterObjectMethod( "Rand", "uint32 nextUint( uint32 v )",
			 asMETHODPR(Rand,nextUint,(uint32_t ),uint32_t), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: int32_t nextInt( int32_t a, int32_t b )
		r = engine->RegisterObjectMethod( "Rand", "int32 nextInt( int32 a, int32 b )",
			 asMETHODPR(Rand,nextInt,(int32_t ,int32_t ),int32_t), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: float nextFloat()
		r = engine->RegisterObjectMethod( "Rand", "float nextFloat()",
			 asMETHODPR(Rand,nextFloat,(),float), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: float nextFloat( float v )
		r = engine->RegisterObjectMethod( "Rand", "float nextFloat( float v )",
			 asMETHODPR(Rand,nextFloat,(float ),float), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: float nextFloat( float a, float b )
		r = engine->RegisterObjectMethod( "Rand", "float nextFloat( float a, float b )",
			 asMETHODPR(Rand,nextFloat,(float ,float ),float), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: float posNegFloat( float a, float b )
		r = engine->RegisterObjectMethod( "Rand", "float posNegFloat( float a, float b )",
			 asMETHODPR(Rand,posNegFloat,(float ,float ),float), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: Vec3f nextVec3f()
		r = engine->RegisterObjectMethod( "Rand", "Vec3f nextVec3f()",
			 asMETHODPR(Rand,nextVec3f,(),Vec3f), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: Vec2f nextVec2f( )
		r = engine->RegisterObjectMethod( "Rand", "Vec2f nextVec2f( )",
			 asMETHODPR(Rand,nextVec2f,( ),Vec2f), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: float nextGaussian()
		r = engine->RegisterObjectMethod( "Rand", "float nextGaussian()",
			 asMETHODPR(Rand,nextGaussian,(),float), asCALL_THISCALL ); assert( r >= 0 );








		// STATIC METHOD: void randomize()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Rand" : "Rand" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "void randomize()",
			 asFUNCTIONPR(Rand::randomize,(),void), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: void randSeed( unsigned long seedValue )
		r = engine->RegisterGlobalFunction( "void randSeed( uint seedValue )",
			 asFUNCTIONPR(Rand::randSeed,(unsigned long ),void), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: bool randBool()
		r = engine->RegisterGlobalFunction( "bool randBool()",
			 asFUNCTIONPR(Rand::randBool,(),bool), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: int32_t randInt()
		r = engine->RegisterGlobalFunction( "int32 randInt()",
			 asFUNCTIONPR(Rand::randInt,(),int32_t), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: uint32_t randUint()
		r = engine->RegisterGlobalFunction( "uint32 randUint()",
			 asFUNCTIONPR(Rand::randUint,(),uint32_t), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: int32_t randInt( int32_t v )
		r = engine->RegisterGlobalFunction( "int32 randInt( int32 v )",
			 asFUNCTIONPR(Rand::randInt,(int32_t ),int32_t), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: uint32_t randUint( uint32_t v )
		r = engine->RegisterGlobalFunction( "uint32 randUint( uint32 v )",
			 asFUNCTIONPR(Rand::randUint,(uint32_t ),uint32_t), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: int32_t randInt( int32_t a, int32_t b )
		r = engine->RegisterGlobalFunction( "int32 randInt( int32 a, int32 b )",
			 asFUNCTIONPR(Rand::randInt,(int32_t ,int32_t ),int32_t), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: float randFloat()
		r = engine->RegisterGlobalFunction( "float randFloat()",
			 asFUNCTIONPR(Rand::randFloat,(),float), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: float randFloat( float v )
		r = engine->RegisterGlobalFunction( "float randFloat( float v )",
			 asFUNCTIONPR(Rand::randFloat,(float ),float), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: float randFloat( float a, float b )
		r = engine->RegisterGlobalFunction( "float randFloat( float a, float b )",
			 asFUNCTIONPR(Rand::randFloat,(float ,float ),float), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: float randPosNegFloat( float a, float b )
		r = engine->RegisterGlobalFunction( "float randPosNegFloat( float a, float b )",
			 asFUNCTIONPR(Rand::randPosNegFloat,(float ,float ),float), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: Vec3f randVec3f()
		r = engine->RegisterGlobalFunction( "Vec3f randVec3f()",
			 asFUNCTIONPR(Rand::randVec3f,(),Vec3f), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: Vec2f randVec2f()
		r = engine->RegisterGlobalFunction( "Vec2f randVec2f()",
			 asFUNCTIONPR(Rand::randVec2f,(),Vec2f), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: float randGaussian()
		r = engine->RegisterGlobalFunction( "float randGaussian()",
			 asFUNCTIONPR(Rand::randGaussian,(),float), asCALL_CDECL ); assert( r >= 0 );






		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
