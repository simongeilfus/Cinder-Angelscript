#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/app/MouseEvent.h"


using namespace std;
using namespace ci;
using namespace ci::app;

namespace as {

	void registerCinderMouseEventType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "MouseEvent", sizeof(MouseEvent), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_POD ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderMouseEventImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// METHOD: int getX() const
		r = engine->RegisterObjectMethod( "MouseEvent", "int getX()",
			 asMETHODPR(MouseEvent,getX,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getY() const
		r = engine->RegisterObjectMethod( "MouseEvent", "int getY()",
			 asMETHODPR(MouseEvent,getY,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getPos() const
		r = engine->RegisterObjectMethod( "MouseEvent", "Vec2i getPos()",
			 asMETHODPR(MouseEvent,getPos,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isLeft() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isLeft()",
			 asMETHODPR(MouseEvent,isLeft,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isRight() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isRight()",
			 asMETHODPR(MouseEvent,isRight,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isMiddle() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isMiddle()",
			 asMETHODPR(MouseEvent,isMiddle,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isLeftDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isLeftDown()",
			 asMETHODPR(MouseEvent,isLeftDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isRightDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isRightDown()",
			 asMETHODPR(MouseEvent,isRightDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isMiddleDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isMiddleDown()",
			 asMETHODPR(MouseEvent,isMiddleDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isShiftDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isShiftDown()",
			 asMETHODPR(MouseEvent,isShiftDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isAltDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isAltDown()",
			 asMETHODPR(MouseEvent,isAltDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isControlDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isControlDown()",
			 asMETHODPR(MouseEvent,isControlDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isMetaDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isMetaDown()",
			 asMETHODPR(MouseEvent,isMetaDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isAccelDown() const
		r = engine->RegisterObjectMethod( "MouseEvent", "bool isAccelDown()",
			 asMETHODPR(MouseEvent,isAccelDown,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getWheelIncrement() const
		r = engine->RegisterObjectMethod( "MouseEvent", "float getWheelIncrement()",
			 asMETHODPR(MouseEvent,getWheelIncrement,()const,float), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: uint32_t getNativeModifiers() const
		r = engine->RegisterObjectMethod( "MouseEvent", "uint32 getNativeModifiers()",
			 asMETHODPR(MouseEvent,getNativeModifiers,()const,uint32_t), asCALL_THISCALL ); assert( r >= 0 );


	}
}
