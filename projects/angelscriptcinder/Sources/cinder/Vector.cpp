#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Vector.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderVec2Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Vec2<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderVec2Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Vec2<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Vec2<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec2<T>,const Vec2<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Vec2<T>&,Vec2<T>,Vec2<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: T x,y
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " x" ).c_str(),
                                           asOFFSET(Vec2<T>,x)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " y" ).c_str(),
                                           asOFFSET(Vec2<T>,y)); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type
		// PROPERTY: typedef typename VECTRAIT<T>::DIST DIST
		// PROPERTY: static const int DIM = 2

		// CONSTRUCTOR: Vec2( T nx, T ny ) : x( nx ), y( ny )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " nx, " + type + " ny )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec2<T>,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  explicit Vec2( const T *d ) : x( d[0] ), y( d[1] )

		//template<typename FromT>
		//  Vec2( const Vec2<FromT>& src )
		//  : x( static_cast<T>( src.x ) ),y( static_cast<T>( src.y ) )


		// METHOD: void set( T ax, T ay )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " ax, " + type + " ay )" ).c_str(),
			 asMETHODPR(Vec2<T>,set,(T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void set( const Vec2<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec2<T>,set,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );





		//template<typename FromT>
		// OPERATOR NOT SUPPORTED: Vec2<T>& operator=( const Vec2<FromT>& rhs )



		// OPERATOR NOT SUPPORTED: Vec2<T>& operator=( const Vec2<T>& rhs )



		// OPERATOR NOT SUPPORTED: T& operator[]( int n )



		// OPERATOR NOT SUPPORTED: const T& operator[]( int n ) const



		//  T* ptr() const

		// OPERATOR: const Vec2<T> operator+( const Vec2<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Vec2<T>,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec2<T> operator-( const Vec2<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Vec2<T>,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec2<T> operator*( const Vec2<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec2<T>,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec2<T> operator/( const Vec2<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Vec2<T>,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator+=( const Vec2<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Vec2<T>&,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator-=( const Vec2<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Vec2<T>&,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator*=( const Vec2<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Vec2<T>&,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator/=( const Vec2<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Vec2<T>&,Vec2<T>,const Vec2<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec2<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Vec2<T>,Vec2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator+=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Vec2<T>&,Vec2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator-=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Vec2<T>&,Vec2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator*=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Vec2<T>&,Vec2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec2<T>& operator/=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Vec2<T>&,Vec2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR NOT SUPPORTED: bool operator==( const Vec2<T> &rhs ) const



		// OPERATOR NOT SUPPORTED: bool operator!=( const Vec2<T> &rhs ) const



		// METHOD: T dot( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " dot( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec2<T>,dot,(const Vec2<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: T cross( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " cross( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec2<T>,cross,(const Vec2<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float distance( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float distance( const " + name + " &in rhs )" ).c_str(),
			 asMETHOD(Vec2<T>,distance), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T distanceSquared( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distanceSquared( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec2<T>,distanceSquared,(const Vec2<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float length() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float length()" ).c_str(),
			 asMETHOD(Vec2<T>,length), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void normalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void normalize()" ).c_str(),
			 asMETHODPR(Vec2<T>,normalize,(),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec2<T> normalized() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " normalized()" ).c_str(),
			 asMETHODPR(Vec2<T>,normalized,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void safeNormalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void safeNormalize()" ).c_str(),
			 asMETHODPR(Vec2<T>,safeNormalize,(),void), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: Vec2<T> safeNormalized() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " safeNormalized()" ).c_str(),
			 asMETHODPR(Vec2<T>,safeNormalized,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void rotate( float radians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( float radians )" ).c_str(),
			 asMETHOD(Vec2<T>,rotate), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T lengthSquared() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " lengthSquared()" ).c_str(),
			 asMETHODPR(Vec2<T>,lengthSquared,()const,T), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void limit( float maxLength )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void limit( float maxLength )" ).c_str(),
			 asMETHOD(Vec2<T>,limit), asCALL_THISCALL ); assert( r >= 0 );






		// METHOD: Vec2<T> limited( T maxLength ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " limited( " + type + " maxLength )" ).c_str(),
			 asMETHODPR(Vec2<T>,limited,(T )const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void invert()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void invert()" ).c_str(),
			 asMETHODPR(Vec2<T>,invert,(),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec2<T> inverse() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverse()" ).c_str(),
			 asMETHODPR(Vec2<T>,inverse,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec2<T> lerp( T fact, const Vec2<T>& r ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lerp( " + type + " fact, const " + name + "&in  r )" ).c_str(),
			 asMETHODPR(Vec2<T>,lerp,(T ,const Vec2<T>& )const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void lerpEq( T fact, const Vec2<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void lerpEq( " + type + " fact, const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec2<T>,lerpEq,(T ,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: Vec2<T> xx() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " xx()" ).c_str(),
			 asMETHODPR(Vec2<T>,xx,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> xy() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " xy()" ).c_str(),
			 asMETHODPR(Vec2<T>,xy,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> yx() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " yx()" ).c_str(),
			 asMETHODPR(Vec2<T>,yx,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2<T> yy() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " yy()" ).c_str(),
			 asMETHODPR(Vec2<T>,yy,()const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

        if( engine->GetObjectTypeByName( ( "Vec3" + suffix ).c_str() ) != NULL ){
            
            // METHOD: Vec3<T> xxx() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " xxx()" ).c_str(),
                                             asMETHODPR(Vec2<T>,xxx,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> xxy() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " xxy()" ).c_str(),
                                             asMETHODPR(Vec2<T>,xxy,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> xyx() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " xyx()" ).c_str(),
                                             asMETHODPR(Vec2<T>,xyx,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> xyy() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " xyy()" ).c_str(),
                                             asMETHODPR(Vec2<T>,xyy,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> yxx() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " yxx()" ).c_str(),
                                             asMETHODPR(Vec2<T>,yxx,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> yxy() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " yxy()" ).c_str(),
                                             asMETHODPR(Vec2<T>,yxy,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> yyx() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " yyx()" ).c_str(),
                                             asMETHODPR(Vec2<T>,yyx,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
            
            // METHOD: Vec3<T> yyy() const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " yyy()" ).c_str(),
                                             asMETHODPR(Vec2<T>,yyy,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );
        }


		// STATIC METHOD: Vec2<T> max()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " max()" ).c_str(),
			 asFUNCTIONPR(Vec2<T>::max,(),Vec2<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: Vec2<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(Vec2<T>::zero,(),Vec2<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: Vec2<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(Vec2<T>::one,(),Vec2<T>), asCALL_CDECL ); assert( r >= 0 );




		//  friend std::ostream& operator<<( std::ostream& lhs, const Vec2<T>& rhs )



		// STATIC METHOD: Vec2<T> xAxis()
		r = engine->RegisterGlobalFunction( std::string( name + " xAxis()" ).c_str(),
			 asFUNCTIONPR(Vec2<T>::xAxis,(),Vec2<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Vec2<T> yAxis()
		r = engine->RegisterGlobalFunction( std::string( name + " yAxis()" ).c_str(),
			 asFUNCTIONPR(Vec2<T>::yAxis,(),Vec2<T>), asCALL_CDECL ); assert( r >= 0 );


		//  static Vec2<T> NaN()
		r = engine->SetDefaultNamespace(""); assert( r >= 0 );
        

	}
		// PROPERTY: class Vec3
	template<typename T>
	void registerCinderVec3Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Vec3<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderVec3Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Vec3<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Vec3<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec3<T>,const Vec3<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Vec3<T>&,Vec3<T>,Vec3<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: public:
		// PROPERTY: T x,y,z
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " x" ).c_str(),
                                           asOFFSET(Vec3<T>,x)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " y" ).c_str(),
                                           asOFFSET(Vec3<T>,y)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " z" ).c_str(),
                                           asOFFSET(Vec3<T>,z)); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type
		// PROPERTY: static const int DIM = 3

		// CONSTRUCTOR: Vec3( T nx, T ny, T nz )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " nx, " + type + " ny, " + type + " nz )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec3<T>,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : x( nx ), y( ny ), z( nz )

		//  : x( src.x ), y( src.y ), z( src.z )

		// CONSTRUCTOR: Vec3( const Vec2<T> &v2, T aZ )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec2" + suffix + " &in v2, " + type + " aZ )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec3<T>,const Vec2<T> &,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : x( v2.x ), y( v2.y ), z( aZ )

		//  explicit Vec3( const Vec2<T> &v2 )
		//  : x( v2.x ), y( v2.y ), z( 0 )

		//  explicit Vec3( const T *d ) : x( d[0] ), y( d[1] ), z( d[2] )
		//template<typename FromT>
		//  Vec3( const Vec3<FromT> &src )
		//  : x( static_cast<T>( src.x ) ), y( static_cast<T>( src.y ) ), z( static_cast<T>( src.z ) )

		//template<typename Y>
		//  explicit Vec3( const Y &v )
		//  : x( VEC3CONV<Vec3<typename T::TYPE>,Y>::getX( v ) ), y( VEC3CONV<typename T::TYPE,Y>::getY( v ) ), z( VEC3CONV<typename T::TYPE,Y>::getZ( v ) )



		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: void set( T ax, T ay, T az )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " ax, " + type + " ay, " + type + " az )" ).c_str(),
			 asMETHODPR(Vec3<T>,set,(T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void set( const Vec3<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,set,(const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );




		// OPERATOR NOT SUPPORTED: Vec3<T>& operator=( const Vec3<T> &rhs )



		//template<typename FromT>
		// OPERATOR NOT SUPPORTED: Vec3<T>& operator=( const Vec3<FromT> &rhs )



		// OPERATOR NOT SUPPORTED: T& operator[]( int n )



		// OPERATOR NOT SUPPORTED: const T& operator[]( int n ) const



		//  T* ptr() const

		// OPERATOR: const Vec3<T> operator+( const Vec3<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Vec3<T>,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec3<T> operator-( const Vec3<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Vec3<T>,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec3<T> operator*( const Vec3<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec3<T>,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec3<T> operator/( const Vec3<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Vec3<T>,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator+=( const Vec3<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Vec3<T>&,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator-=( const Vec3<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Vec3<T>&,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator*=( const Vec3<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Vec3<T>&,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator/=( const Vec3<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Vec3<T>&,Vec3<T>,const Vec3<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec3<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Vec3<T>,Vec3<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator+=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Vec3<T>&,Vec3<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator-=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Vec3<T>&,Vec3<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator*=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Vec3<T>&,Vec3<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec3<T>& operator/=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Vec3<T>&,Vec3<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR NOT SUPPORTED: bool operator==( const Vec3<T>& rhs ) const



		// OPERATOR NOT SUPPORTED: bool operator!=( const Vec3<T>& rhs ) const



		// METHOD: T dot( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " dot( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,dot,(const Vec3<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec3<T> cross( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " cross( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,cross,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T distance( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distance( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,distance,(const Vec3<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T distanceSquared( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distanceSquared( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,distanceSquared,(const Vec3<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T length() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " length()" ).c_str(),
			 asMETHODPR(Vec3<T>,length,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T lengthSquared() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " lengthSquared()" ).c_str(),
			 asMETHODPR(Vec3<T>,lengthSquared,()const,T), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void limit( T maxLength )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void limit( " + type + " maxLength )" ).c_str(),
			 asMETHODPR(Vec3<T>,limit,(T ),void), asCALL_THISCALL ); assert( r >= 0 );






		// METHOD: Vec3<T> limited( T maxLength ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " limited( " + type + " maxLength )" ).c_str(),
			 asMETHODPR(Vec3<T>,limited,(T )const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void invert()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void invert()" ).c_str(),
			 asMETHODPR(Vec3<T>,invert,(),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec3<T> inverse() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverse()" ).c_str(),
			 asMETHODPR(Vec3<T>,inverse,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void normalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void normalize()" ).c_str(),
			 asMETHODPR(Vec3<T>,normalize,(),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec3<T> normalized() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " normalized()" ).c_str(),
			 asMETHODPR(Vec3<T>,normalized,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void safeNormalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void safeNormalize()" ).c_str(),
			 asMETHODPR(Vec3<T>,safeNormalize,(),void), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: Vec3<T> safeNormalized() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " safeNormalized()" ).c_str(),
			 asMETHODPR(Vec3<T>,safeNormalized,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );






		// METHOD: Vec3<T> getOrthogonal() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " getOrthogonal()" ).c_str(),
			 asMETHODPR(Vec3<T>,getOrthogonal,()const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void rotateX( T angle )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotateX( " + type + " angle )" ).c_str(),
			 asMETHODPR(Vec3<T>,rotateX,(T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void rotateY( T angle )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotateY( " + type + " angle )" ).c_str(),
			 asMETHODPR(Vec3<T>,rotateY,(T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void rotateZ( T angle )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotateZ( " + type + " angle )" ).c_str(),
			 asMETHODPR(Vec3<T>,rotateZ,(T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void rotate( Vec3<T> axis, T angle )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( " + name + " axis, " + type + " angle )" ).c_str(),
			 asMETHODPR(Vec3<T>,rotate,(Vec3<T> ,T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec3<T> lerp( T fact, const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lerp( " + type + " fact, const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,lerp,(T ,const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void lerpEq( T fact, const Vec3<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void lerpEq( " + type + " fact, const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec3<T>,lerpEq,(T ,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );




		// STATIC METHOD: Vec3<T> max()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " max()" ).c_str(),
			 asFUNCTIONPR(Vec3<T>::max,(),Vec3<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: Vec3<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(Vec3<T>::zero,(),Vec3<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: Vec3<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(Vec3<T>::one,(),Vec3<T>), asCALL_CDECL ); assert( r >= 0 );




		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: Vec3<T> slerp( T fact, const Vec3<T> &r ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " slerp( " + type + " fact, const " + name + " &in r )" ).c_str(),
			 asMETHODPR(Vec3<T>,slerp,(T ,const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );





	}
		// PROPERTY: class Vec4
	template<typename T>
	void registerCinderVec4Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Vec4<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderVec4Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Vec4<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Vec4<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec4<T>,const Vec4<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Vec4<T>&,Vec4<T>,Vec4<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: public:
		// PROPERTY: T x,y,z,w
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " x" ).c_str(),
                                           asOFFSET(Vec4<T>,x)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " y" ).c_str(),
                                           asOFFSET(Vec4<T>,y)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " z" ).c_str(),
                                           asOFFSET(Vec4<T>,z)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " w" ).c_str(),
                                           asOFFSET(Vec4<T>,w)); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type
		// PROPERTY: static const int DIM = 4

		//  : x( 0 ), y( 0 ), z( 0 ), w( 0 )

		// CONSTRUCTOR: Vec4( T nx, T ny, T nz, T nw = 0 )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " nx, " + type + " ny, " + type + " nz, " + type + " nw = 0 )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec4<T>,T ,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : x( nx ), y( ny ), z( nz ), w( nw )

		// CONSTRUCTOR: Vec4( const Vec3<T>& src, T aW = 0 )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + "&in  src, " + type + " aW = 0 )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Vec4<T>,const Vec3<T>& ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : x( src.x ), y( src.y ), z( src.z ), w( aW )

		//  : x( src.x ), y( src.y ), z( src.z ), w( src.w )

		//template<typename FromT>
		//  Vec4( const Vec4<FromT>& src )
		//  : x( static_cast<T>( src.x ) ), y( static_cast<T>( src.y ) ), z( static_cast<T>( src.z ) ),w( static_cast<T>( src.w ) )

		//  explicit Vec4( const T *d ) : x( d[0] ), y( d[1] ), z( d[2] ), w( d[3] )

		// METHOD: void set( T ax, T ay, T az, T aw )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " ax, " + type + " ay, " + type + " az, " + type + " aw )" ).c_str(),
			 asMETHODPR(Vec4<T>,set,(T ,T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void set( const Vec4<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec4<T>,set,(const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );




		// OPERATOR NOT SUPPORTED: Vec4<T>& operator=( const Vec4<T>& rhs )



		//template<typename FromT>
		// OPERATOR NOT SUPPORTED: Vec4<T>& operator=( const Vec4<FromT>& rhs )



		// OPERATOR NOT SUPPORTED: T& operator[]( int n )



		// OPERATOR NOT SUPPORTED: const T& operator[]( int n ) const



		//  T* ptr() const

		// OPERATOR: const Vec4<T> operator+( const Vec4<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Vec4<T>,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec4<T> operator-( const Vec4<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Vec4<T>,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec4<T> operator*( const Vec4<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec4<T>,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec4<T> operator/( const Vec4<T>& rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Vec4<T>,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator+=( const Vec4<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Vec4<T>&,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator-=( const Vec4<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Vec4<T>&,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator*=( const Vec4<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Vec4<T>&,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator/=( const Vec4<T>& rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( const " + name + "&in  rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Vec4<T>&,Vec4<T>,const Vec4<T>& >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Vec4<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Vec4<T>,Vec4<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator+=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Vec4<T>&,Vec4<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator-=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Vec4<T>&,Vec4<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator*=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Vec4<T>&,Vec4<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Vec4<T>& operator/=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Vec4<T>&,Vec4<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR NOT SUPPORTED: bool operator==( const Vec4<T>& rhs ) const



		// OPERATOR NOT SUPPORTED: bool operator!=( const Vec4<T>& rhs ) const



		// METHOD: T dot( const Vec4<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " dot( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec4<T>,dot,(const Vec4<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec4<T> cross( const Vec4<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " cross( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec4<T>,cross,(const Vec4<T> &)const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T distance( const Vec4<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distance( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec4<T>,distance,(const Vec4<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T distanceSquared( const Vec4<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " distanceSquared( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec4<T>,distanceSquared,(const Vec4<T> &)const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T length() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " length()" ).c_str(),
			 asMETHODPR(Vec4<T>,length,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: T lengthSquared() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " lengthSquared()" ).c_str(),
			 asMETHODPR(Vec4<T>,lengthSquared,()const,T), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void normalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void normalize()" ).c_str(),
			 asMETHODPR(Vec4<T>,normalize,(),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec4<T> normalized() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " normalized()" ).c_str(),
			 asMETHODPR(Vec4<T>,normalized,()const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void safeNormalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void safeNormalize()" ).c_str(),
			 asMETHODPR(Vec4<T>,safeNormalize,(),void), asCALL_THISCALL ); assert( r >= 0 );






		// METHOD: void limit( T maxLength )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void limit( " + type + " maxLength )" ).c_str(),
			 asMETHODPR(Vec4<T>,limit,(T ),void), asCALL_THISCALL ); assert( r >= 0 );






		// METHOD: Vec4<T> limited( T maxLength ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " limited( " + type + " maxLength )" ).c_str(),
			 asMETHODPR(Vec4<T>,limited,(T )const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void invert()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void invert()" ).c_str(),
			 asMETHODPR(Vec4<T>,invert,(),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec4<T> inverse() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverse()" ).c_str(),
			 asMETHODPR(Vec4<T>,inverse,()const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: Vec4<T> lerp( T fact, const Vec4<T>& r ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lerp( " + type + " fact, const " + name + "&in  r )" ).c_str(),
			 asMETHODPR(Vec4<T>,lerp,(T ,const Vec4<T>& )const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void lerpEq( T fact, const Vec4<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void lerpEq( " + type + " fact, const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(Vec4<T>,lerpEq,(T ,const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );




		// STATIC METHOD: Vec4<T> max()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " max()" ).c_str(),
			 asFUNCTIONPR(Vec4<T>::max,(),Vec4<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: Vec4<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(Vec4<T>::zero,(),Vec4<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: Vec4<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(Vec4<T>::one,(),Vec4<T>), asCALL_CDECL ); assert( r >= 0 );




		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: Vec4<T> slerp( T fact, const Vec3<T> &r ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " slerp( " + type + " fact, const Vec3" + suffix + " &in r )" ).c_str(),
			 asMETHODPR(Vec4<T>,slerp,(T ,const Vec3<T> &)const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );





	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec2Type<int>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec2Impl<int>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec2Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec2Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec2Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec2Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec3Type<int>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec3Impl<int>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec3Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec3Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec3Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec3Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec4Type<int>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec4Impl<int>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec4Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec4Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderVec4Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderVec4Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
