#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Shape2d.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderShape2dType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Shape2d", sizeof(Shape2d), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderShape2dImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Shape2d", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Shape2d>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Shape2d", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Shape2d>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Shape2d", asBEHAVE_CONSTRUCT,
			"void f(const Shape2d &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Shape2d,const Shape2d &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Shape2d","Shape2d& opAssign(const Shape2d &in)", asFUNCTION((as::RegistrationHelper::opAssign<Shape2d&,Shape2d,Shape2d&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// METHOD: void moveTo( const Vec2f &p )
		r = engine->RegisterObjectMethod( "Shape2d", "void moveTo( const Vec2f &in p )",
			 asMETHODPR(Shape2d,moveTo,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void moveTo( float x, float y )
		r = engine->RegisterObjectMethod( "Shape2d", "void moveTo( float x, float y )",
			 asMETHODPR(Shape2d,moveTo,(float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void lineTo( const Vec2f &p )
		r = engine->RegisterObjectMethod( "Shape2d", "void lineTo( const Vec2f &in p )",
			 asMETHODPR(Shape2d,lineTo,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void lineTo( float x, float y )
		r = engine->RegisterObjectMethod( "Shape2d", "void lineTo( float x, float y )",
			 asMETHODPR(Shape2d,lineTo,(float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void quadTo( const Vec2f &p1, const Vec2f &p2 )
		r = engine->RegisterObjectMethod( "Shape2d", "void quadTo( const Vec2f &in p1, const Vec2f &in p2 )",
			 asMETHODPR(Shape2d,quadTo,(const Vec2f &,const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void quadTo( float x1, float y1, float x2, float y2 )
		r = engine->RegisterObjectMethod( "Shape2d", "void quadTo( float x1, float y1, float x2, float y2 )",
			 asMETHODPR(Shape2d,quadTo,(float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void curveTo( const Vec2f &p1, const Vec2f &p2, const Vec2f &p3 )
		r = engine->RegisterObjectMethod( "Shape2d", "void curveTo( const Vec2f &in p1, const Vec2f &in p2, const Vec2f &in p3 )",
			 asMETHODPR(Shape2d,curveTo,(const Vec2f &,const Vec2f &,const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void curveTo( float x1, float y1, float x2, float y2, float x3, float y3 )
		r = engine->RegisterObjectMethod( "Shape2d", "void curveTo( float x1, float y1, float x2, float y2, float x3, float y3 )",
			 asMETHODPR(Shape2d,curveTo,(float ,float ,float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arc( const Vec2f &center, float radius, float startRadians, float endRadians, bool forward = true )
		r = engine->RegisterObjectMethod( "Shape2d", "void arc( const Vec2f &in center, float radius, float startRadians, float endRadians, bool forward = true )",
			 asMETHODPR(Shape2d,arc,(const Vec2f &,float ,float ,float ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arc( float centerX, float centerY, float radius, float startRadians, float endRadians, bool forward = true )
		r = engine->RegisterObjectMethod( "Shape2d", "void arc( float centerX, float centerY, float radius, float startRadians, float endRadians, bool forward = true )",
			 asMETHODPR(Shape2d,arc,(float ,float ,float ,float ,float ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arcTo( const Vec2f &p, const Vec2f &t, float radius )
		r = engine->RegisterObjectMethod( "Shape2d", "void arcTo( const Vec2f &in p, const Vec2f &in t, float radius )",
			 asMETHODPR(Shape2d,arcTo,(const Vec2f &,const Vec2f &,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arcTo( float x, float y, float tanX, float tanY, float radius)
		r = engine->RegisterObjectMethod( "Shape2d", "void arcTo( float x, float y, float tanX, float tanY, float radius)",
			 asMETHODPR(Shape2d,arcTo,(float ,float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void close()
		r = engine->RegisterObjectMethod( "Shape2d", "void close()",
			 asMETHODPR(Shape2d,close,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool empty() const
		r = engine->RegisterObjectMethod( "Shape2d", "bool empty()",
			 asMETHODPR(Shape2d,empty,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void clear()
		r = engine->RegisterObjectMethod( "Shape2d", "void clear()",
			 asMETHODPR(Shape2d,clear,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: size_t getNumContours() const
		r = engine->RegisterObjectMethod( "Shape2d", "uint getNumContours()",
			 asMETHODPR(Shape2d,getNumContours,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: const Path2d& getContour( size_t i ) const
		r = engine->RegisterObjectMethod( "Shape2d", "const Path2d& getContour( uint i )",
			 asMETHODPR(Shape2d,getContour,(size_t )const,const Path2d&), asCALL_THISCALL ); assert( r >= 0 );
/*
		// METHOD: Path2d& getContour( size_t i )
		r = engine->RegisterObjectMethod( "Shape2d", "Path2d& getContour( uint i )",
			 asMETHODPR(Shape2d,getContour,(size_t ),Path2d&), asCALL_THISCALL ); assert( r >= 0 );
*/
		// PROPERTY: */
		// METHOD: const Vec2f& getCurrentPoint() const
		r = engine->RegisterObjectMethod( "Shape2d", "const Vec2f& getCurrentPoint()",
			 asMETHODPR(Shape2d,getCurrentPoint,()const,const Vec2f&), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void append( const Shape2d &shape )
		r = engine->RegisterObjectMethod( "Shape2d", "void append( const Shape2d &in shape )",
			 asMETHODPR(Shape2d,append,(const Shape2d &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void appendContour( const Path2d &contour )
		r = engine->RegisterObjectMethod( "Shape2d", "void appendContour( const Path2d &in contour )",
			 asMETHODPR(Shape2d,appendContour,(const Path2d &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void removeContour( size_t i )
		r = engine->RegisterObjectMethod( "Shape2d", "void removeContour( uint i )",
			 asMETHODPR(Shape2d,removeContour,(size_t ),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void scale( const Vec2f &amount, Vec2f scaleCenter = Vec2f::zero() )


		// METHOD: void transform( const MatrixAffine2f &matrix )
		r = engine->RegisterObjectMethod( "Shape2d", "void transform( const MatrixAffine2f &in matrix )",
			 asMETHODPR(Shape2d,transform,(const MatrixAffine2f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Shape2d transformCopy( const MatrixAffine2f &matrix ) const
		r = engine->RegisterObjectMethod( "Shape2d", "Shape2d transformCopy( const MatrixAffine2f &in matrix )",
			 asMETHODPR(Shape2d,transformCopy,(const MatrixAffine2f &)const,Shape2d), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Rectf calcBoundingBox() const
		r = engine->RegisterObjectMethod( "Shape2d", "Rectf calcBoundingBox()",
			 asMETHODPR(Shape2d,calcBoundingBox,()const,Rectf), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Rectf calcPreciseBoundingBox() const
		r = engine->RegisterObjectMethod( "Shape2d", "Rectf calcPreciseBoundingBox()",
			 asMETHODPR(Shape2d,calcPreciseBoundingBox,()const,Rectf), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool contains( const Vec2f &pt ) const
		r = engine->RegisterObjectMethod( "Shape2d", "bool contains( const Vec2f &in pt )",
			 asMETHODPR(Shape2d,contains,(const Vec2f &)const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// PROPERTY: A \a SegmentType of type \c CLOSE receives &mPoints[0] for its \a points parameters. **/


	}
}
