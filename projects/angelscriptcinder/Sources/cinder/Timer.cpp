#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Timer.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderTimerType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Timer", sizeof(Timer), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTimerImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Timer", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Timer>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Timer", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Timer>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Timer", asBEHAVE_CONSTRUCT,
			"void f(const Timer &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Timer,const Timer &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Timer","Timer& opAssign(const Timer &in)", asFUNCTION((as::RegistrationHelper::opAssign<Timer&,Timer,Timer&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// CONSTRUCTOR: Timer( bool startOnConstruction )
		r = engine->RegisterObjectBehaviour( "Timer", asBEHAVE_CONSTRUCT,
			"void f( bool startOnConstruction )", asFUNCTION( ( as::RegistrationHelper::constructor<Timer,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: void start()
		r = engine->RegisterObjectMethod( "Timer", "void start()",
			 asMETHODPR(Timer,start,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: double getSeconds() const
		r = engine->RegisterObjectMethod( "Timer", "double getSeconds()",
			 asMETHODPR(Timer,getSeconds,()const,double), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void stop()
		r = engine->RegisterObjectMethod( "Timer", "void stop()",
			 asMETHODPR(Timer,stop,(),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool isStopped() const
		r = engine->RegisterObjectMethod( "Timer", "bool isStopped()",
			 asMETHODPR(Timer,isStopped,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


	}
}
