#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Path2d.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderPath2dType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Path2d", sizeof(Path2d), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderPath2dImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Path2d", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Path2d>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Path2d", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Path2d>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Path2d", asBEHAVE_CONSTRUCT,
			"void f(const Path2d &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Path2d,const Path2d &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Path2d","Path2d& opAssign(const Path2d &in)", asFUNCTION((as::RegistrationHelper::opAssign<Path2d&,Path2d,Path2d&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: void moveTo( const Vec2f &p )
		r = engine->RegisterObjectMethod( "Path2d", "void moveTo( const Vec2f &in p )",
			 asMETHODPR(Path2d,moveTo,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void moveTo( float x, float y )
		r = engine->RegisterObjectMethod( "Path2d", "void moveTo( float x, float y )",
			 asMETHODPR(Path2d,moveTo,(float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void lineTo( const Vec2f &p )
		r = engine->RegisterObjectMethod( "Path2d", "void lineTo( const Vec2f &in p )",
			 asMETHODPR(Path2d,lineTo,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void lineTo( float x, float y )
		r = engine->RegisterObjectMethod( "Path2d", "void lineTo( float x, float y )",
			 asMETHODPR(Path2d,lineTo,(float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void quadTo( const Vec2f &p1, const Vec2f &p2 )
		r = engine->RegisterObjectMethod( "Path2d", "void quadTo( const Vec2f &in p1, const Vec2f &in p2 )",
			 asMETHODPR(Path2d,quadTo,(const Vec2f &,const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void quadTo( float x1, float y1, float x2, float y2 )
		r = engine->RegisterObjectMethod( "Path2d", "void quadTo( float x1, float y1, float x2, float y2 )",
			 asMETHODPR(Path2d,quadTo,(float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void curveTo( const Vec2f &p1, const Vec2f &p2, const Vec2f &p3 )
		r = engine->RegisterObjectMethod( "Path2d", "void curveTo( const Vec2f &in p1, const Vec2f &in p2, const Vec2f &in p3 )",
			 asMETHODPR(Path2d,curveTo,(const Vec2f &,const Vec2f &,const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void curveTo( float x1, float y1, float x2, float y2, float x3, float y3 )
		r = engine->RegisterObjectMethod( "Path2d", "void curveTo( float x1, float y1, float x2, float y2, float x3, float y3 )",
			 asMETHODPR(Path2d,curveTo,(float ,float ,float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arc( const Vec2f &center, float radius, float startRadians, float endRadians, bool forward = true )
		r = engine->RegisterObjectMethod( "Path2d", "void arc( const Vec2f &in center, float radius, float startRadians, float endRadians, bool forward = true )",
			 asMETHODPR(Path2d,arc,(const Vec2f &,float ,float ,float ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arc( float centerX, float centerY, float radius, float startRadians, float endRadians, bool forward = true )
		r = engine->RegisterObjectMethod( "Path2d", "void arc( float centerX, float centerY, float radius, float startRadians, float endRadians, bool forward = true )",
			 asMETHODPR(Path2d,arc,(float ,float ,float ,float ,float ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arcTo( const Vec2f &p, const Vec2f &t, float radius )
		r = engine->RegisterObjectMethod( "Path2d", "void arcTo( const Vec2f &in p, const Vec2f &in t, float radius )",
			 asMETHODPR(Path2d,arcTo,(const Vec2f &,const Vec2f &,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void arcTo( float x, float y, float tanX, float tanY, float radius)
		r = engine->RegisterObjectMethod( "Path2d", "void arcTo( float x, float y, float tanX, float tanY, float radius)",
			 asMETHODPR(Path2d,arcTo,(float ,float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void close()
		r = engine->RegisterObjectMethod( "Path2d", "void close()",
			 asMETHODPR(Path2d,close,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isClosed() const
		r = engine->RegisterObjectMethod( "Path2d", "bool isClosed()",
			 asMETHODPR(Path2d,isClosed,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void reverse()
		r = engine->RegisterObjectMethod( "Path2d", "void reverse()",
			 asMETHODPR(Path2d,reverse,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool empty() const
		r = engine->RegisterObjectMethod( "Path2d", "bool empty()",
			 asMETHODPR(Path2d,empty,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void clear()
		r = engine->RegisterObjectMethod( "Path2d", "void clear()",
			 asMETHODPR(Path2d,clear,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: size_t getNumSegments() const
		r = engine->RegisterObjectMethod( "Path2d", "uint getNumSegments()",
			 asMETHODPR(Path2d,getNumSegments,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: size_t getNumPoints() const
		r = engine->RegisterObjectMethod( "Path2d", "uint getNumPoints()",
			 asMETHODPR(Path2d,getNumPoints,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec2f getPosition( float t ) const
		r = engine->RegisterObjectMethod( "Path2d", "Vec2f getPosition( float t )",
			 asMETHODPR(Path2d,getPosition,(float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2f getSegmentPosition( size_t segment, float t ) const
		r = engine->RegisterObjectMethod( "Path2d", "Vec2f getSegmentPosition( uint segment, float t )",
			 asMETHODPR(Path2d,getSegmentPosition,(size_t ,float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2f getTangent( float t ) const
		r = engine->RegisterObjectMethod( "Path2d", "Vec2f getTangent( float t )",
			 asMETHODPR(Path2d,getTangent,(float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2f getSegmentTangent( size_t segment, float t ) const
		r = engine->RegisterObjectMethod( "Path2d", "Vec2f getSegmentTangent( uint segment, float t )",
			 asMETHODPR(Path2d,getSegmentTangent,(size_t ,float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );



		//  void getSegmentRelativeT( float t, size_t *segment, float *relativeT ) const

		//  std::vector<Vec2f> subdivide( float approximationScale = 1.0f ) const


		//  void scale( const Vec2f &amount, Vec2f scaleCenter = Vec2f::zero() )

		// METHOD: void transform( const MatrixAffine2f &matrix )
		r = engine->RegisterObjectMethod( "Path2d", "void transform( const MatrixAffine2f &in matrix )",
			 asMETHODPR(Path2d,transform,(const MatrixAffine2f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Path2d transformCopy( const MatrixAffine2f &matrix ) const
		r = engine->RegisterObjectMethod( "Path2d", "Path2d transformCopy( const MatrixAffine2f &in matrix )",
			 asMETHODPR(Path2d,transformCopy,(const MatrixAffine2f &)const,Path2d), asCALL_THISCALL ); assert( r >= 0 );

		//  std::vector<Vec2f>& getPoints() */
		// METHOD: const Vec2f& getPoint( size_t point ) const
		r = engine->RegisterObjectMethod( "Path2d", "const Vec2f& getPoint( uint point )",
			 asMETHODPR(Path2d,getPoint,(size_t )const,const Vec2f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Vec2f& getCurrentPoint() const
		r = engine->RegisterObjectMethod( "Path2d", "const Vec2f& getCurrentPoint()",
			 asMETHODPR(Path2d,getCurrentPoint,()const,const Vec2f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setPoint( size_t index, const Vec2f &p )
		r = engine->RegisterObjectMethod( "Path2d", "void setPoint( uint index, const Vec2f &in p )",
			 asMETHODPR(Path2d,setPoint,(size_t ,const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  SegmentType getSegmentType( size_t segment ) const */

		//  std::vector<SegmentType>& getSegments() */

		// METHOD: void removeSegment( size_t segment )
		r = engine->RegisterObjectMethod( "Path2d", "void removeSegment( uint segment )",
			 asMETHODPR(Path2d,removeSegment,(size_t ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Rectf calcBoundingBox() const
		r = engine->RegisterObjectMethod( "Path2d", "Rectf calcBoundingBox()",
			 asMETHODPR(Path2d,calcBoundingBox,()const,Rectf), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Rectf calcPreciseBoundingBox() const
		r = engine->RegisterObjectMethod( "Path2d", "Rectf calcPreciseBoundingBox()",
			 asMETHODPR(Path2d,calcPreciseBoundingBox,()const,Rectf), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool contains( const Vec2f &pt ) const
		r = engine->RegisterObjectMethod( "Path2d", "bool contains( const Vec2f &in pt )",
			 asMETHODPR(Path2d,contains,(const Vec2f &)const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float calcLength() const
		r = engine->RegisterObjectMethod( "Path2d", "float calcLength()",
			 asMETHODPR(Path2d,calcLength,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float calcSegmentLength( size_t segment, float minT = 0, float maxT = 1 ) const
		r = engine->RegisterObjectMethod( "Path2d", "float calcSegmentLength( uint segment, float minT = 0, float maxT = 1 )",
			 asMETHODPR(Path2d,calcSegmentLength,(size_t ,float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float calcNormalizedTime( float relativeTime, bool wrap = true, float tolerance = 1.0e-03f, int maxIterations = 16 ) const
		r = engine->RegisterObjectMethod( "Path2d", "float calcNormalizedTime( float relativeTime, bool wrap = true, float tolerance = 1.0e-03f, int maxIterations = 16 )",
			 asMETHODPR(Path2d,calcNormalizedTime,(float ,bool ,float ,int )const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float calcTimeForDistance( float distance, bool wrap = true, float tolerance = 1.0e-03f, int maxIterations = 16 ) const
		r = engine->RegisterObjectMethod( "Path2d", "float calcTimeForDistance( float distance, bool wrap = true, float tolerance = 1.0e-03f, int maxIterations = 16 )",
			 asMETHODPR(Path2d,calcTimeForDistance,(float ,bool ,float ,int )const,float), asCALL_THISCALL ); assert( r >= 0 );


		//  static Vec2f calcCubicBezierDerivative( const Vec2f p[4], float t )*/


		// METHOD: float segmentSolveTimeForDistance( size_t segment, float segmentLength, float segmentRelativeDistance, float tolerance, int maxIterations ) const
		r = engine->RegisterObjectMethod( "Path2d", "float segmentSolveTimeForDistance( uint segment, float segmentLength, float segmentRelativeDistance, float tolerance, int maxIterations )",
			 asMETHODPR(Path2d,segmentSolveTimeForDistance,(size_t ,float ,float ,float ,int )const,float), asCALL_THISCALL ); assert( r >= 0 );


		// PROPERTY: friend class Shape2d
		// PROPERTY: friend class Path2dCalcCache


	}
}
