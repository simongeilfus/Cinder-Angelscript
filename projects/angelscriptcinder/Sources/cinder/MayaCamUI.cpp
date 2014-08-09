#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/MayaCamUI.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderMayaCamUIType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "MayaCamUI", sizeof(MayaCamUI), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderMayaCamUIImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "MayaCamUI", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<MayaCamUI>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "MayaCamUI", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<MayaCamUI>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "MayaCamUI", asBEHAVE_CONSTRUCT,
			"void f(const MayaCamUI &in )", asFUNCTION( ( as::RegistrationHelper::constructor<MayaCamUI,const MayaCamUI &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "MayaCamUI","MayaCamUI& opAssign(const MayaCamUI &in)", asFUNCTION((as::RegistrationHelper::opAssign<MayaCamUI&,MayaCamUI,MayaCamUI&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: MayaCamUI( const CameraPersp &aInitialCam )
		r = engine->RegisterObjectBehaviour( "MayaCamUI", asBEHAVE_CONSTRUCT,
			"void f( const CameraPersp &in aInitialCam )", asFUNCTION( ( as::RegistrationHelper::constructor<MayaCamUI,const CameraPersp &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void mouseDown( const Vec2i &mousePos )
		r = engine->RegisterObjectMethod( "MayaCamUI", "void mouseDown( const Vec2i &in mousePos )",
			 asMETHODPR(MayaCamUI,mouseDown,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void mouseDrag( const Vec2i &mousePos, bool leftDown, bool middleDown, bool rightDown )
		r = engine->RegisterObjectMethod( "MayaCamUI", "void mouseDrag( const Vec2i &in mousePos, bool leftDown, bool middleDown, bool rightDown )",
			 asMETHODPR(MayaCamUI,mouseDrag,(const Vec2i &,bool ,bool ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );








		// METHOD: const CameraPersp& getCamera() const
		r = engine->RegisterObjectMethod( "MayaCamUI", "const CameraPersp& getCamera()",
			 asMETHODPR(MayaCamUI,getCamera,()const,const CameraPersp&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCurrentCam( const CameraPersp &aCurrentCam )
		r = engine->RegisterObjectMethod( "MayaCamUI", "void setCurrentCam( const CameraPersp &in aCurrentCam )",
			 asMETHODPR(MayaCamUI,setCurrentCam,(const CameraPersp &),void), asCALL_THISCALL ); assert( r >= 0 );


	}
}
