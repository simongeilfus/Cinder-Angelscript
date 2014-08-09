#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Area.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderAreaType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Area", sizeof(Area), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderAreaImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Area", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Area>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Area", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Area>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Area", asBEHAVE_CONSTRUCT,
			"void f(const Area &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Area,const Area &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Area","Area& opAssign(const Area &in)", asFUNCTION((as::RegistrationHelper::opAssign<Area&,Area,Area&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Area( const Vec2i &UL, const Vec2i &LR )
		r = engine->RegisterObjectBehaviour( "Area", asBEHAVE_CONSTRUCT,
			"void f( const Vec2i &in UL, const Vec2i &in LR )", asFUNCTION( ( as::RegistrationHelper::constructor<Area,const Vec2i &,const Vec2i &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Area( int32_t aX1, int32_t aY1, int32_t aX2, int32_t aY2 )
		r = engine->RegisterObjectBehaviour( "Area", asBEHAVE_CONSTRUCT,
			"void f( int32 aX1, int32 aY1, int32 aX2, int32 aY2 )", asFUNCTION( ( as::RegistrationHelper::constructor<Area,int32_t ,int32_t ,int32_t ,int32_t > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//  explicit Area( const RectT<float> &r )

		// METHOD: void set( int32_t aX1, int32_t aY1, int32_t aX2, int32_t aY2 )
		r = engine->RegisterObjectMethod( "Area", "void set( int32 aX1, int32 aY1, int32 aX2, int32 aY2 )",
			 asMETHODPR(Area,set,(int32_t ,int32_t ,int32_t ,int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int32_t getWidth() const
		r = engine->RegisterObjectMethod( "Area", "int32 getWidth()",
			 asMETHODPR(Area,getWidth,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int32_t getHeight() const
		r = engine->RegisterObjectMethod( "Area", "int32 getHeight()",
			 asMETHODPR(Area,getHeight,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( "Area", "Vec2i getSize()",
			 asMETHODPR(Area,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2f getCenter() const
		r = engine->RegisterObjectMethod( "Area", "Vec2f getCenter()",
			 asMETHODPR(Area,getCenter,()const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int32_t calcArea() const
		r = engine->RegisterObjectMethod( "Area", "int32 calcArea()",
			 asMETHODPR(Area,calcArea,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void clipBy( const Area &clip )
		r = engine->RegisterObjectMethod( "Area", "void clipBy( const Area &in clip )",
			 asMETHODPR(Area,clipBy,(const Area &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Area getClipBy( const Area &clip ) const
		r = engine->RegisterObjectMethod( "Area", "Area getClipBy( const Area &in clip )",
			 asMETHODPR(Area,getClipBy,(const Area &)const,Area), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void offset( const Vec2i &off )
		r = engine->RegisterObjectMethod( "Area", "void offset( const Vec2i &in off )",
			 asMETHODPR(Area,offset,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getOffset( const Vec2i &off ) const
		r = engine->RegisterObjectMethod( "Area", "Area getOffset( const Vec2i &in off )",
			 asMETHODPR(Area,getOffset,(const Vec2i &)const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void moveULTo( const Vec2i &newUL )
		r = engine->RegisterObjectMethod( "Area", "void moveULTo( const Vec2i &in newUL )",
			 asMETHODPR(Area,moveULTo,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getMoveULTo( const Vec2i &newUL ) const
		r = engine->RegisterObjectMethod( "Area", "Area getMoveULTo( const Vec2i &in newUL )",
			 asMETHODPR(Area,getMoveULTo,(const Vec2i &)const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void expand( int32_t expandX, int32_t expandY )
		r = engine->RegisterObjectMethod( "Area", "void expand( int32 expandX, int32 expandY )",
			 asMETHODPR(Area,expand,(int32_t ,int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int32_t getX1() const
		r = engine->RegisterObjectMethod( "Area", "int32 getX1()",
			 asMETHODPR(Area,getX1,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setX1( int32_t aX1 )
		r = engine->RegisterObjectMethod( "Area", "void setX1( int32 aX1 )",
			 asMETHODPR(Area,setX1,(int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int32_t getY1() const
		r = engine->RegisterObjectMethod( "Area", "int32 getY1()",
			 asMETHODPR(Area,getY1,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setY1( int32_t aY1 )
		r = engine->RegisterObjectMethod( "Area", "void setY1( int32 aY1 )",
			 asMETHODPR(Area,setY1,(int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int32_t getX2() const
		r = engine->RegisterObjectMethod( "Area", "int32 getX2()",
			 asMETHODPR(Area,getX2,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setX2( int32_t aX2 )
		r = engine->RegisterObjectMethod( "Area", "void setX2( int32 aX2 )",
			 asMETHODPR(Area,setX2,(int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int32_t getY2() const
		r = engine->RegisterObjectMethod( "Area", "int32 getY2()",
			 asMETHODPR(Area,getY2,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setY2( int32_t aY2 )
		r = engine->RegisterObjectMethod( "Area", "void setY2( int32 aY2 )",
			 asMETHODPR(Area,setY2,(int32_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2i getUL() const // left-top offset
		r = engine->RegisterObjectMethod( "Area", "Vec2i getUL()",
			 asMETHODPR(Area,getUL,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2i getLR() const // right-bottom offset
		r = engine->RegisterObjectMethod( "Area", "Vec2i getLR()",
			 asMETHODPR(Area,getLR,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool contains( const Vec2i &offset ) const
		r = engine->RegisterObjectMethod( "Area", "bool contains( const Vec2i &in offset )",
			 asMETHODPR(Area,contains,(const Vec2i &)const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool contains( const Vec2f &offset ) const
		r = engine->RegisterObjectMethod( "Area", "bool contains( const Vec2f &in offset )",
			 asMETHODPR(Area,contains,(const Vec2f &)const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool intersects( const Area &area ) const
		r = engine->RegisterObjectMethod( "Area", "bool intersects( const Area &in area )",
			 asMETHODPR(Area,intersects,(const Area &)const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void include( const Vec2i &point )
		r = engine->RegisterObjectMethod( "Area", "void include( const Vec2i &in point )",
			 asMETHODPR(Area,include,(const Vec2i &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void include( const std::vector<Vec2i > &points )

		// METHOD: void include( const Area &area )
		r = engine->RegisterObjectMethod( "Area", "void include( const Area &in area )",
			 asMETHODPR(Area,include,(const Area &),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float distance( const Vec2f &pt ) const
		r = engine->RegisterObjectMethod( "Area", "float distance( const Vec2f &in pt )",
			 asMETHODPR(Area,distance,(const Vec2f &)const,float), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float distanceSquared( const Vec2f &pt ) const
		r = engine->RegisterObjectMethod( "Area", "float distanceSquared( const Vec2f &in pt )",
			 asMETHODPR(Area,distanceSquared,(const Vec2f &)const,float), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec2f closestPoint( const Vec2f &pt ) const
		r = engine->RegisterObjectMethod( "Area", "Vec2f closestPoint( const Vec2f &in pt )",
			 asMETHODPR(Area,closestPoint,(const Vec2f &)const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );


		// PROPERTY: int32_t x1, y1, x2, y2

		// OPERATOR NOT SUPPORTED: bool operator==( const Area &aArea ) const
		// OPERATOR NOT SUPPORTED: bool operator<( const Area &aArea ) const

		// OPERATOR: const Area operator+( const Vec2i &o ) const
		r = engine->RegisterObjectMethod("Area", "const Area opAdd( const Vec2i &in o )", asFUNCTION((as::RegistrationHelper::opAdd<const Area,Area,const Vec2i &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Area operator-( const Vec2i &o ) const
		r = engine->RegisterObjectMethod("Area", "const Area opSub( const Vec2i &in o )", asFUNCTION((as::RegistrationHelper::opSub<const Area,Area,const Vec2i &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Area operator+( const Area& rhs ) const
		r = engine->RegisterObjectMethod("Area", "const Area opAdd( const Area&in  rhs )", asFUNCTION((as::RegistrationHelper::opAdd<const Area,Area,const Area& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Area operator-( const Area& rhs ) const
		r = engine->RegisterObjectMethod("Area", "const Area opSub( const Area&in  rhs )", asFUNCTION((as::RegistrationHelper::opSub<const Area,Area,const Area& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: Area& operator+=( const Vec2i &o )
		r = engine->RegisterObjectMethod("Area", "Area& opAddAssign( const Vec2i &in o )", asFUNCTION((as::RegistrationHelper::opAddAssign<Area&,Area,const Vec2i &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Area& operator-=( const Vec2i &o )
		r = engine->RegisterObjectMethod("Area", "Area& opSubAssign( const Vec2i &in o )", asFUNCTION((as::RegistrationHelper::opSubAssign<Area&,Area,const Vec2i &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// STATIC METHOD: Area proportionalFit( const Area &srcArea, const Area &dstArea, bool center, bool expand = false )
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Area" : "Area" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "Area proportionalFit( const Area &in srcArea, const Area &in dstArea, bool center, bool expand = false )",
			 asFUNCTIONPR(Area::proportionalFit,(const Area &,const Area &,bool ,bool ),Area), asCALL_CDECL ); assert( r >= 0 );


		//  friend std::ostream& operator<<( std::ostream &o, const Area &area )


		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
