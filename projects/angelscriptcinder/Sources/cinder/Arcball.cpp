#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>
#include <angelscript.h>

#include "cinder/Arcball.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderArcballType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Arcball", sizeof(Arcball), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderArcballImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Arcball", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Arcball>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Arcball", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Arcball>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Arcball", asBEHAVE_CONSTRUCT,
			"void f(const Arcball &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Arcball,const Arcball &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Arcball","Arcball& opAssign(const Arcball &in)", asFUNCTION((as::RegistrationHelper::opAssign<Arcball&,Arcball,Arcball&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// CONSTRUCTOR: Arcball( const Vec2i &aScreenSize )
		r = engine->RegisterObjectBehaviour( "Arcball", asBEHAVE_CONSTRUCT,
			"void f( const Vec2i &in aScreenSize )", asFUNCTION( ( as::RegistrationHelper::constructor<Arcball,const Vec2i &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : mWindowSize( aScreenSize )



		// METHOD: void mouseDown( const Vec2i &mousePos )
		r = engine->RegisterObjectMethod( "Arcball", "void mouseDown( const Vec2i &in mousePos )",
			 asMETHODPR(Arcball,mouseDown,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void mouseDrag( const Vec2i &mousePos )
		r = engine->RegisterObjectMethod( "Arcball", "void mouseDrag( const Vec2i &in mousePos )",
			 asMETHODPR(Arcball,mouseDrag,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void resetQuat()
		r = engine->RegisterObjectMethod( "Arcball", "void resetQuat()",
			 asMETHODPR(Arcball,resetQuat,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Quatf getQuat()
		r = engine->RegisterObjectMethod( "Arcball", "Quatf getQuat()",
			 asMETHODPR(Arcball,getQuat,(),Quatf), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setQuat( const Quatf &quat )
		r = engine->RegisterObjectMethod( "Arcball", "void setQuat( const Quatf &in quat )",
			 asMETHODPR(Arcball,setQuat,(const Quatf &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setWindowSize( const Vec2i &aWindowSize )
		r = engine->RegisterObjectMethod( "Arcball", "void setWindowSize( const Vec2i &in aWindowSize )",
			 asMETHODPR(Arcball,setWindowSize,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCenter( const Vec2f &aCenter )
		r = engine->RegisterObjectMethod( "Arcball", "void setCenter( const Vec2f &in aCenter )",
			 asMETHODPR(Arcball,setCenter,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2f getCenter() const
		r = engine->RegisterObjectMethod( "Arcball", "Vec2f getCenter()",
			 asMETHODPR(Arcball,getCenter,()const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setRadius( float aRadius )
		r = engine->RegisterObjectMethod( "Arcball", "void setRadius( float aRadius )",
			 asMETHODPR(Arcball,setRadius,(float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getRadius() const
		r = engine->RegisterObjectMethod( "Arcball", "float getRadius()",
			 asMETHODPR(Arcball,getRadius,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setConstraintAxis( const Vec3f &aConstraintAxis )
		r = engine->RegisterObjectMethod( "Arcball", "void setConstraintAxis( const Vec3f &in aConstraintAxis )",
			 asMETHODPR(Arcball,setConstraintAxis,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setNoConstraintAxis()
		r = engine->RegisterObjectMethod( "Arcball", "void setNoConstraintAxis()",
			 asMETHODPR(Arcball,setNoConstraintAxis,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isUsingConstraint() const
		r = engine->RegisterObjectMethod( "Arcball", "bool isUsingConstraint()",
			 asMETHODPR(Arcball,isUsingConstraint,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f getConstraintAxis() const
		r = engine->RegisterObjectMethod( "Arcball", "Vec3f getConstraintAxis()",
			 asMETHODPR(Arcball,getConstraintAxis,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f mouseOnSphere( const Vec2i &point )
		r = engine->RegisterObjectMethod( "Arcball", "Vec3f mouseOnSphere( const Vec2i &in point )",
			 asMETHODPR(Arcball,mouseOnSphere,(const Vec2i &),Vec3f), asCALL_THISCALL ); assert( r >= 0 );





	}
}
