#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/MatrixAffine2.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderMatrixAffine2Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(MatrixAffine2<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderMatrixAffine2Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<MatrixAffine2<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<MatrixAffine2<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<MatrixAffine2<T>,const MatrixAffine2<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<MatrixAffine2<T>&,MatrixAffine2<T>,MatrixAffine2<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type

		//  static const size_t MEM_LEN = sizeof(T)*6















		// PROPERTY: union



		// CONSTRUCTOR: MatrixAffine2( T s )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " s )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<MatrixAffine2<T>,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  MatrixAffine2( const T *dt )



		// CONSTRUCTOR: MatrixAffine2( const Vec2<T> &vx, const Vec2<T> &vy, const Vec2<T> &vz )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec2" + suffix + " &in vx, const Vec2" + suffix + " &in vy, const Vec2" + suffix + " &in vz )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<MatrixAffine2<T>,const Vec2<T> &,const Vec2<T> &,const Vec2<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//template<typename FromT>
		//  MatrixAffine2( const MatrixAffine2<FromT> &src )

		// OPERATOR NOT SUPPORTED: MatrixAffine2<T>& operator=( const MatrixAffine2<T>& rhs )
		// OPERATOR NOT SUPPORTED: MatrixAffine2<T>& operator=( T rhs )

		//template<typename FromT>
		// OPERATOR NOT SUPPORTED: MatrixAffine2<T>& operator=( const MatrixAffine2<FromT> &rhs )

		// METHOD: bool equalCompare( const MatrixAffine2<T>& rhs, T epsilon ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool equalCompare( const " + name + "&in  rhs, " + type + " epsilon )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,equalCompare,(const MatrixAffine2<T>& ,T )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// OPERATOR NOT SUPPORTED: bool operator==( const MatrixAffine2<T> &rhs ) const
		// OPERATOR NOT SUPPORTED: bool operator!=( const MatrixAffine2<T> &rhs ) const

		// OPERATOR: MatrixAffine2<T>& operator*=( const MatrixAffine2<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<MatrixAffine2<T>&,MatrixAffine2<T>,const MatrixAffine2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: MatrixAffine2<T>& operator+=( const MatrixAffine2<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<MatrixAffine2<T>&,MatrixAffine2<T>,const MatrixAffine2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: MatrixAffine2<T>& operator-=( const MatrixAffine2<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<MatrixAffine2<T>&,MatrixAffine2<T>,const MatrixAffine2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: MatrixAffine2<T>& operator*=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<MatrixAffine2<T>&,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: MatrixAffine2<T>& operator/=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<MatrixAffine2<T>&,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: MatrixAffine2<T>& operator+=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<MatrixAffine2<T>&,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: MatrixAffine2<T>& operator-=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<MatrixAffine2<T>&,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const MatrixAffine2<T> operator*( const MatrixAffine2<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const MatrixAffine2<T>,MatrixAffine2<T>,const MatrixAffine2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const MatrixAffine2<T> operator+( const MatrixAffine2<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const MatrixAffine2<T>,MatrixAffine2<T>,const MatrixAffine2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const MatrixAffine2<T> operator-( const MatrixAffine2<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const MatrixAffine2<T>,MatrixAffine2<T>,const MatrixAffine2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: Vec2<T> transformPoint( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " transformPoint( const Vec2" + suffix + " &in rhs )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,transformPoint,(const Vec2<T> &)const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );


		// OPERATOR: const Vec2<T> operator*( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const Vec2" + suffix + " opMul( const Vec2" + suffix + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec2<T>,MatrixAffine2<T>,const Vec2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: Vec2<T> transformVec( const Vec2<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " transformVec( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,transformVec,(const Vec2<T> &)const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );


		// OPERATOR: const MatrixAffine2<T> operator*( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const MatrixAffine2<T>,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const MatrixAffine2<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const MatrixAffine2<T>,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const MatrixAffine2<T> operator+( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const MatrixAffine2<T>,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const MatrixAffine2<T> operator-( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const MatrixAffine2<T>,MatrixAffine2<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: T& at( int row, int col )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + "& at( int row, int col )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,at,(int ,int ),T&), asCALL_THISCALL ); assert( r >= 0 );



		// OPERATOR NOT SUPPORTED: T& operator[]( int idx )
		// OPERATOR NOT SUPPORTED: const T& operator[]( int idx ) const


		//  void set( const T *dt )

		// METHOD: void set( T d0, T d1, T d2, T d3, T d4, T d5 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " d0, " + type + " d1, " + type + " d2, " + type + " d3, " + type + " d4, " + type + " d5 )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,set,(T ,T ,T ,T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2<T> getColumn( int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getColumn( int col )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,getColumn,(int )const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColumn( int col, const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumn( int col, const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,setColumn,(int ,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3<T> getRow( int row ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " getRow( int row )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,getRow,(int )const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setRow( int row, const Vec3<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRow( int row, const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,setRow,(int ,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getColumns( Vec2<T> *c0, Vec2<T> *c1, Vec2<T> *c2 ) const
		// METHOD: void setColumns( const Vec2<T> &c0, const Vec2<T> &c1, const Vec2<T> &c2 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumns( const Vec2" + suffix + " &in c0, const Vec2" + suffix + " &in c1, const Vec2" + suffix + " &in c2 )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,setColumns,(const Vec2<T> &,const Vec2<T> &,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getRows( Vec3<T> *r0, Vec3<T> *r1, Vec3<T> *r2 ) const
		// METHOD: void setRows( const Vec3<T> &r0, const Vec3<T> &r1, const Vec3<T> &r2 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRows( const Vec3" + suffix + " &in r0, const Vec3" + suffix + " &in r1, const Vec3" + suffix + " &in r2 )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,setRows,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void setToNull()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToNull()" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,setToNull,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setToIdentity()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToIdentity()" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,setToIdentity,(),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool isSingular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isSingular()" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,isSingular,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void invert(T epsilon = EPSILON )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void invert()" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,invert,(T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: MatrixAffine2<T> invertCopy( T epsilon = EPSILON ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " invertCopy()" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,invertCopy,(T )const,MatrixAffine2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void translate( const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void translate( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,translate,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: MatrixAffine2 translateCopy( const Vec2<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " translateCopy( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,translateCopy,(const Vec2<T> &)const,MatrixAffine2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void rotate( T radians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( " + type + " radians )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,rotate,(T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void rotate( T radians, const Vec2<T> &pt )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( " + type + " radians, const Vec2" + suffix + " &in pt )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,rotate,(T ,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: MatrixAffine2 rotateCopy( T radians ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " rotateCopy( " + type + " radians )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,rotateCopy,(T )const,MatrixAffine2<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: MatrixAffine2 rotateCopy( T radians, const Vec2<T> &pt ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " rotateCopy( " + type + " radians, const Vec2" + suffix + " &in pt )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,rotateCopy,(T ,const Vec2<T> &)const,MatrixAffine2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void scale( T s )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( " + type + " s )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,scale,(T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void scale( const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,scale,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: MatrixAffine2 scaleCopy( T s ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " scaleCopy( " + type + " s )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,scaleCopy,(T )const,MatrixAffine2<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: MatrixAffine2 scaleCopy( const Vec2<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " scaleCopy( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(MatrixAffine2<T>,scaleCopy,(const Vec2<T> &)const,MatrixAffine2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// STATIC METHOD: MatrixAffine2<T> identity()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " identity()" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::identity,(),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: MatrixAffine2<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::one,(),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: MatrixAffine2<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::zero,(),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: MatrixAffine2<T> makeTranslate( const Vec2<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " makeTranslate( const Vec2" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeTranslate,(const Vec2<T> &),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: MatrixAffine2<T> makeRotate( T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " makeRotate( " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeRotate,(T ),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: MatrixAffine2<T> makeRotate( T radians, const Vec2<T> &pt )
		r = engine->RegisterGlobalFunction( std::string( name + " makeRotate( " + type + " radians, const Vec2" + suffix + " &in pt )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeRotate,(T ,const Vec2<T> &),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: MatrixAffine2<T> makeScale( T s )
		r = engine->RegisterGlobalFunction( std::string( name + " makeScale( " + type + " s )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeScale,(T ),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: MatrixAffine2<T> makeScale( const Vec2<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " makeScale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeScale,(const Vec2<T> &),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: MatrixAffine2<T> makeSkewX( T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " makeSkewX( " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeSkewX,(T ),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: MatrixAffine2<T> makeSkewY( T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " makeSkewY( " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(MatrixAffine2<T>::makeSkewY,(T ),MatrixAffine2<T>), asCALL_CDECL ); assert( r >= 0 );


		//  friend std::ostream& operator<<( std::ostream &lhs, const MatrixAffine2<T> &rhs )



		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrixAffine2Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrixAffine2Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrixAffine2Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrixAffine2Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
