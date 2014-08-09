#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/BSpline.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderBSplineType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(BSpline<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderBSplineImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<BSpline<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<BSpline<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<BSpline<T>,const BSpline<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<BSpline<T>&,BSpline<T>,BSpline<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );






















		// CONSTRUCTOR: BSpline( const std::vector<T> &points, int degree, bool loop, bool open )
		/*r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const std::vector" + suffix + " &in points, int degree, bool loop, bool open )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<BSpline<T>,const std::vector<T> &,int ,bool ,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


*/

		//  BSpline( int numControlPoints, const T *controlPoints, int degree, bool loop, const float *knots )
		// OPERATOR NOT SUPPORTED: BSpline& operator=( const BSpline &bspline )


		// METHOD: int getNumControlPoints() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int getNumControlPoints()" ).c_str(),
			 asMETHODPR(BSpline<T>,getNumControlPoints,()const,int), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int getDegree() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int getDegree()" ).c_str(),
			 asMETHODPR(BSpline<T>,getDegree,()const,int), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int getNumSpans() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int getNumSpans()" ).c_str(),
			 asMETHODPR(BSpline<T>,getNumSpans,()const,int), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isOpen() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isOpen()" ).c_str(),
			 asMETHODPR(BSpline<T>,isOpen,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isUniform() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isUniform()" ).c_str(),
			 asMETHODPR(BSpline<T>,isUniform,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isLoop() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isLoop()" ).c_str(),
			 asMETHODPR(BSpline<T>,isLoop,()const,bool), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void setControlPoint( int i, const T &rkCtrl )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setControlPoint( int i, const " + type + " &in rkCtrl )" ).c_str(),
			 asMETHODPR(BSpline<T>,setControlPoint,(int ,const T &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getControlPoint( int i ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getControlPoint( int i )" ).c_str(),
			 asMETHODPR(BSpline<T>,getControlPoint,(int )const,T), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void setKnot( int i, float fKnot )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setKnot( int i, float fKnot )" ).c_str(),
			 asMETHODPR(BSpline<T>,setKnot,(int ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getKnot( int i ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float getKnot( int i )" ).c_str(),
			 asMETHODPR(BSpline<T>,getKnot,(int )const,float), asCALL_THISCALL ); assert( r >= 0 );






		// METHOD: T getPosition( float t ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getPosition( float t )" ).c_str(),
			 asMETHODPR(BSpline<T>,getPosition,(float )const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getDerivative( float t ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getDerivative( float t )" ).c_str(),
			 asMETHODPR(BSpline<T>,getDerivative,(float )const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getSecondDerivative( float t ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getSecondDerivative( float t )" ).c_str(),
			 asMETHODPR(BSpline<T>,getSecondDerivative,(float )const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getThirdDerivative( float t ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getThirdDerivative( float t )" ).c_str(),
			 asMETHODPR(BSpline<T>,getThirdDerivative,(float )const,T), asCALL_THISCALL ); assert( r >= 0 );

		//  typename T::TYPE getSpeed( float t ) const

		// METHOD: float getLength( float fT0, float fT1 ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float getLength( float fT0, float fT1 )" ).c_str(),
			 asMETHODPR(BSpline<T>,getLength,(float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );






		//  void get( float t, T *position, T *firstDerivative = NULL, T *secondDerivative = NULL, T *thirdDerivative = NULL ) const

		// METHOD: float getTime( float length ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float getTime( float length )" ).c_str(),
			 asMETHODPR(BSpline<T>,getTime,(float )const,float), asCALL_THISCALL ); assert( r >= 0 );




	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderBSplineType<Vec2f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderBSplineImpl<Vec2f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderBSplineType<Vec3f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderBSplineImpl<Vec3f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
