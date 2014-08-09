#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Rect.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderRectTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(RectT<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderRectTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<RectT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<RectT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<RectT<T>,const RectT<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<RectT<T>&,RectT<T>,RectT<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

/*
		// CONSTRUCTOR: RectT( const std::vector<Vec2<T> > &points )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const std::vector<Vec2" + suffix + " > &in points )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<RectT<T>,const std::vector<Vec2<T> > &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/
		// CONSTRUCTOR: RectT( T aX1, T aY1, T aX2, T aY2 )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " aX1, " + type + " aY1, " + type + " aX2, " + type + " aY2 )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<RectT<T>,T ,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: RectT( const Vec2<T> &v1, const Vec2<T> &v2 )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec2" + suffix + " &in v1, const Vec2" + suffix + " &in v2 )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<RectT<T>,const Vec2<T> &,const Vec2<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: RectT( const Area &area )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Area &in area )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<RectT<T>,const Area &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void set( T aX1, T aY1, T aX2, T aY2 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " aX1, " + type + " aY1, " + type + " aX2, " + type + " aY2 )" ).c_str(),
			 asMETHODPR(RectT<T>,set,(T ,T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T getWidth() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getWidth()" ).c_str(),
			 asMETHODPR(RectT<T>,getWidth,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getHeight() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getHeight()" ).c_str(),
			 asMETHODPR(RectT<T>,getHeight,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getAspectRatio() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getAspectRatio()" ).c_str(),
			 asMETHODPR(RectT<T>,getAspectRatio,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T calcArea() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " calcArea()" ).c_str(),
			 asMETHODPR(RectT<T>,calcArea,()const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void canonicalize() // return rect w/ properly ordered coordinates
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void canonicalize()" ).c_str(),
			 asMETHODPR(RectT<T>,canonicalize,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT canonicalized() const // return rect w/ properly ordered coordinates
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " canonicalized()" ).c_str(),
			 asMETHODPR(RectT<T>,canonicalized,()const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void clipBy( const RectT &clip )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void clipBy( const " + name + " &in clip )" ).c_str(),
			 asMETHODPR(RectT<T>,clipBy,(const RectT<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT getClipBy( const RectT &clip ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " getClipBy( const " + name + " &in clip )" ).c_str(),
			 asMETHODPR(RectT<T>,getClipBy,(const RectT<T> &)const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Area getInteriorArea() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Area getInteriorArea()" ).c_str(),
			 asMETHODPR(RectT<T>,getInteriorArea,()const,Area), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void offset( const Vec2<T> &offset )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void offset( const Vec2" + suffix + " &in offset )" ).c_str(),
			 asMETHODPR(RectT<T>,offset,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT getOffset( const Vec2<T> &off ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " getOffset( const Vec2" + suffix + " &in off )" ).c_str(),
			 asMETHODPR(RectT<T>,getOffset,(const Vec2<T> &)const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void inflate( const Vec2<T> &amount )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void inflate( const Vec2" + suffix + " &in amount )" ).c_str(),
			 asMETHODPR(RectT<T>,inflate,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT inflated( const Vec2<T> &amount ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inflated( const Vec2" + suffix + " &in amount )" ).c_str(),
			 asMETHODPR(RectT<T>,inflated,(const Vec2<T> &)const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void offsetCenterTo( const Vec2<T> &center )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void offsetCenterTo( const Vec2" + suffix + " &in center )" ).c_str(),
			 asMETHODPR(RectT<T>,offsetCenterTo,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scaleCentered( const Vec2<T> &scale )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scaleCentered( const Vec2" + suffix + " &in scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scaleCentered,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scaleCentered( T scale )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scaleCentered( " + type + " scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scaleCentered,(T ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT scaledCentered( T scale ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " scaledCentered( " + type + " scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scaledCentered,(T )const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scale( T scale )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( " + type + " scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scale,(T ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scale( const Vec2<T> &scale )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( const Vec2" + suffix + " &in scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scale,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT scaled( T scale ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " scaled( " + type + " scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scaled,(T )const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: RectT scaled( const Vec2<T> &scale ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " scaled( const Vec2" + suffix + " &in scale )" ).c_str(),
			 asMETHODPR(RectT<T>,scaled,(const Vec2<T> &)const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );


/*
		// METHOD: RectT transformCopy( const class MatrixAffine2<T> &matrix ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " transformCopy( const class MatrixAffine2" + suffix + " &in matrix )" ).c_str(),
			 asMETHODPR(RectT<T>,transformCopy,(const class MatrixAffine2<T> &)const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );

*/

		//template<typename Y>
		// METHOD: bool contains( const Vec2<T> &pt ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const Vec2" + suffix + " &in pt )" ).c_str(),
			 asMETHODPR(RectT<T>,contains,(const Vec2<T> &)const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool intersects( const RectT &rect ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool intersects( const " + name + " &in rect )" ).c_str(),
			 asMETHODPR(RectT<T>,intersects,(const RectT<T> &)const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: T distance( const Vec2<T> &pt ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distance( const Vec2" + suffix + " &in pt )" ).c_str(),
			 asMETHODPR(RectT<T>,distance,(const Vec2<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T distanceSquared( const Vec2<T> &pt ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distanceSquared( const Vec2" + suffix + " &in pt )" ).c_str(),
			 asMETHODPR(RectT<T>,distanceSquared,(const Vec2<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec2<T> closestPoint( const Vec2<T> &pt ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " closestPoint( const Vec2" + suffix + " &in pt )" ).c_str(),
			 asMETHODPR(RectT<T>,closestPoint,(const Vec2<T> &)const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T getX1() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getX1()" ).c_str(),
			 asMETHODPR(RectT<T>,getX1,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getY1() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getY1()" ).c_str(),
			 asMETHODPR(RectT<T>,getY1,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getX2() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getX2()" ).c_str(),
			 asMETHODPR(RectT<T>,getX2,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getY2() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getY2()" ).c_str(),
			 asMETHODPR(RectT<T>,getY2,()const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2<T> getUpperLeft() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getUpperLeft()" ).c_str(),
			 asMETHODPR(RectT<T>,getUpperLeft,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> getUpperRight() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getUpperRight()" ).c_str(),
			 asMETHODPR(RectT<T>,getUpperRight,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> getLowerRight() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getLowerRight()" ).c_str(),
			 asMETHODPR(RectT<T>,getLowerRight,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> getLowerLeft() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getLowerLeft()" ).c_str(),
			 asMETHODPR(RectT<T>,getLowerLeft,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> getCenter() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getCenter()" ).c_str(),
			 asMETHODPR(RectT<T>,getCenter,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> getSize() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getSize()" ).c_str(),
			 asMETHODPR(RectT<T>,getSize,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: RectT getCenteredFit( const RectT &other, bool expand ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " getCenteredFit( const " + name + " &in other, bool expand )" ).c_str(),
			 asMETHODPR(RectT<T>,getCenteredFit,(const RectT<T> &,bool )const,RectT<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void include( const Vec2<T> &point )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void include( const Vec2" + suffix + " &in point )" ).c_str(),
			 asMETHODPR(RectT<T>,include,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void include( const std::vector<Vec2<T> > &points )


		// OPERATOR: const RectT<T> operator+( const Vec2<T> &o ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const Vec2" + suffix + " &in o )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const RectT<T>,RectT<T>,const Vec2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const RectT<T> operator-( const Vec2<T> &o ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const Vec2" + suffix + " &in o )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const RectT<T>,RectT<T>,const Vec2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const RectT<T> operator*( T s ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const RectT<T>,RectT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const RectT<T> operator/( T s ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const RectT<T>,RectT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const RectT<T> operator+( const RectT<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const RectT<T>,RectT<T>,const RectT<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const RectT<T> operator-( const RectT<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const RectT<T>,RectT<T>,const RectT<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: RectT<T>& operator+=( const Vec2<T> &o )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const Vec2" + suffix + " &in o )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<RectT<T>&,RectT<T>,const Vec2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: RectT<T>& operator-=( const Vec2<T> &o )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const Vec2" + suffix + " &in o )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<RectT<T>&,RectT<T>,const Vec2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: RectT<T>& operator*=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<RectT<T>&,RectT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: RectT<T>& operator/=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<RectT<T>&,RectT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// PROPERTY: T x1, y1, x2, y2

		//  friend std::ostream& operator<<( std::ostream &o, const RectT &rect )



	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderRectTType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderRectTImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderRectTType<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderRectTImpl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);

	void registerCinderRectMappingType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "RectMapping", sizeof(RectMapping), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderRectMappingImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "RectMapping", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<RectMapping>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "RectMapping", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<RectMapping>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "RectMapping", asBEHAVE_CONSTRUCT,
			"void f(const RectMapping &in )", asFUNCTION( ( as::RegistrationHelper::constructor<RectMapping,const RectMapping &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "RectMapping","RectMapping& opAssign(const RectMapping &in)", asFUNCTION((as::RegistrationHelper::opAssign<RectMapping&,RectMapping,RectMapping&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: public:
		//  : mSrcRect( 0, 0, 0, 0 ), mDstRect( 0, 0, 0, 0 )
		// CONSTRUCTOR: RectMapping( const Rectf &aSrcRect, const Rectf &aDstRect )
		r = engine->RegisterObjectBehaviour( "RectMapping", asBEHAVE_CONSTRUCT,
			"void f( const Rectf &in aSrcRect, const Rectf &in aDstRect )", asFUNCTION( ( as::RegistrationHelper::constructor<RectMapping,const Rectf &,const Rectf &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : mSrcRect( aSrcRect ), mDstRect( aDstRect )
		// CONSTRUCTOR: RectMapping( const Rectf &aSrcRect, const Rectf &aDstRect, bool preserveSrcAspect )
		r = engine->RegisterObjectBehaviour( "RectMapping", asBEHAVE_CONSTRUCT,
			"void f( const Rectf &in aSrcRect, const Rectf &in aDstRect, bool preserveSrcAspect )", asFUNCTION( ( as::RegistrationHelper::constructor<RectMapping,const Rectf &,const Rectf &,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: Vec2f map( const Vec2f &srcPoint ) const
		r = engine->RegisterObjectMethod( "RectMapping", "Vec2f map( const Vec2f &in srcPoint )",
			 asMETHODPR(RectMapping,map,(const Vec2f &)const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Rectf map( const Rectf &srcRect ) const
		r = engine->RegisterObjectMethod( "RectMapping", "Rectf map( const Rectf &in srcRect )",
			 asMETHODPR(RectMapping,map,(const Rectf &)const,Rectf), asCALL_THISCALL ); assert( r >= 0 );


	}
}
