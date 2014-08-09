#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Matrix44.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderMatrix44Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Matrix44<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderMatrix44Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Matrix44<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Matrix44<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix44<T>,const Matrix44<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Matrix44<T>&,Matrix44<T>,Matrix44<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type

		// PROPERTY: static const size_t DIM = 4
		// PROPERTY: static const size_t DIM_SQ = DIM*DIM
		//  static const size_t MEM_LEN = sizeof(T)*DIM_SQ















		// PROPERTY: union




		// CONSTRUCTOR: Matrix44( T s )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " s )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix44<T>,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		//  Matrix44( const T *dt, bool srcIsRowMajor = false )





		// CONSTRUCTOR: Matrix44( const Vec3<T> &vx, const Vec3<T> &vy, const Vec3<T> &vz )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + " &in vx, const Vec3" + suffix + " &in vy, const Vec3" + suffix + " &in vz )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix44<T>,const Vec3<T> &,const Vec3<T> &,const Vec3<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Matrix44( const Vec4<T> &vx, const Vec4<T> &vy, const Vec4<T> &vz, const Vec4<T> &vw )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec4" + suffix + " &in vx, const Vec4" + suffix + " &in vy, const Vec4" + suffix + " &in vz, const Vec4" + suffix + " &in vw )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix44<T>,const Vec4<T> &,const Vec4<T> &,const Vec4<T> &,const Vec4<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//template< typename FromT >
		//  Matrix44( const Matrix44<FromT>& src )

		// CONSTRUCTOR: Matrix44( const Matrix22<T>& src )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Matrix22" + suffix + "&in  src )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix44<T>,const Matrix22<T>& > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  explicit Matrix44( const MatrixAffine2<T> &src )
		// CONSTRUCTOR: Matrix44( const Matrix33<T>& src )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Matrix33" + suffix + "&in  src )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix44<T>,const Matrix33<T>& > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );




		// OPERATOR NOT SUPPORTED: Matrix44<T>& operator=( const Matrix44<T>& rhs )
		// OPERATOR NOT SUPPORTED: Matrix44<T>& operator=( T rhs )

		//template< typename FromT >
		// OPERATOR NOT SUPPORTED: Matrix44<T>& operator=( const Matrix44<FromT>& rhs )


		// OPERATOR NOT SUPPORTED: Matrix44<T>& operator=( const Matrix22<T>& rhs )
		// OPERATOR NOT SUPPORTED: Matrix44<T>& operator=( const MatrixAffine2<T>& rhs )
		// OPERATOR NOT SUPPORTED: Matrix44<T>& operator=( const Matrix33<T>& rhs )

		// METHOD: bool equalCompare( const Matrix44<T>& rhs, T epsilon ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool equalCompare( const " + name + "&in  rhs, " + type + " epsilon )" ).c_str(),
			 asMETHODPR(Matrix44<T>,equalCompare,(const Matrix44<T>& ,T )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// OPERATOR NOT SUPPORTED: bool operator==( const Matrix44<T> &rhs ) const
		// OPERATOR NOT SUPPORTED: bool operator!=( const Matrix44<T> &rhs ) const

		// OPERATOR: Matrix44<T>& operator*=( const Matrix44<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Matrix44<T>&,Matrix44<T>,const Matrix44<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix44<T>& operator+=( const Matrix44<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Matrix44<T>&,Matrix44<T>,const Matrix44<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix44<T>& operator-=( const Matrix44<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Matrix44<T>&,Matrix44<T>,const Matrix44<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: Matrix44<T>& operator*=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Matrix44<T>&,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix44<T>& operator/=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Matrix44<T>&,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix44<T>& operator+=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Matrix44<T>&,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix44<T>& operator-=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Matrix44<T>&,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Matrix44<T> operator*( const Matrix44<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Matrix44<T>,Matrix44<T>,const Matrix44<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix44<T> operator+( const Matrix44<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Matrix44<T>,Matrix44<T>,const Matrix44<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix44<T> operator-( const Matrix44<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Matrix44<T>,Matrix44<T>,const Matrix44<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR: const Vec3<T> operator*( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const Vec3" + suffix + " opMul( const Vec3" + suffix + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec3<T>,Matrix44<T>,const Vec3<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR: const Vec4<T> operator*( const Vec4<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const Vec4" + suffix + " opMul( const Vec4" + suffix + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec4<T>,Matrix44<T>,const Vec4<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Matrix44<T> operator*( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Matrix44<T>,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix44<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Matrix44<T>,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix44<T> operator+( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Matrix44<T>,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix44<T> operator-( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Matrix44<T>,Matrix44<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: T& at( int row, int col )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + "& at( int row, int col )" ).c_str(),
			 asMETHODPR(Matrix44<T>,at,(int ,int ),T&), asCALL_THISCALL ); assert( r >= 0 );




		//  void set( const T *dt, bool srcIsRowMajor = false )

		// METHOD: void set( T d0, T d1, T d2, T d3, T d4, T d5, T d6, T d7, T d8, T d9, T d10, T d11, T d12, T d13, T d14, T d15, bool srcIsRowMajor = false )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " d0, " + type + " d1, " + type + " d2, " + type + " d3, " + type + " d4, " + type + " d5, " + type + " d6, " + type + " d7, " + type + " d8, " + type + " d9, " + type + " d10, " + type + " d11, " + type + " d12, " + type + " d13, " + type + " d14, " + type + " d15, bool srcIsRowMajor = false )" ).c_str(),
			 asMETHODPR(Matrix44<T>,set,(T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,T ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec4<T> getColumn( int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec4" + suffix + " getColumn( int col )" ).c_str(),
			 asMETHODPR(Matrix44<T>,getColumn,(int )const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColumn( int col, const Vec4<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumn( int col, const Vec4" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,setColumn,(int ,const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec4<T> getRow( int row ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec4" + suffix + " getRow( int row )" ).c_str(),
			 asMETHODPR(Matrix44<T>,getRow,(int )const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setRow( int row, const Vec4<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRow( int row, const Vec4" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,setRow,(int ,const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getColumns( Vec4<T> *c0, Vec4<T> *c1, Vec4<T> *c2, Vec4<T> *c3 ) const
		// METHOD: void setColumns( const Vec4<T> &c0, const Vec4<T> &c1, const Vec4<T> &c2, const Vec4<T> &c3 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumns( const Vec4" + suffix + " &in c0, const Vec4" + suffix + " &in c1, const Vec4" + suffix + " &in c2, const Vec4" + suffix + " &in c3 )" ).c_str(),
			 asMETHODPR(Matrix44<T>,setColumns,(const Vec4<T> &,const Vec4<T> &,const Vec4<T> &,const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getRows( Vec4<T> *r0, Vec4<T> *r1, Vec4<T> *r2, Vec4<T> *r3 ) const
		// METHOD: void setRows( const Vec4<T> &r0, const Vec4<T> &r1, const Vec4<T> &r2, const Vec4<T> &r3 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRows( const Vec4" + suffix + " &in r0, const Vec4" + suffix + " &in r1, const Vec4" + suffix + " &in r2, const Vec4" + suffix + " &in r3 )" ).c_str(),
			 asMETHODPR(Matrix44<T>,setRows,(const Vec4<T> &,const Vec4<T> &,const Vec4<T> &,const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Matrix22<T> subMatrix22( int row, int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Matrix22" + suffix + " subMatrix22( int row, int col )" ).c_str(),
			 asMETHODPR(Matrix44<T>,subMatrix22,(int ,int )const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix33<T> subMatrix33( int row, int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Matrix33" + suffix + " subMatrix33( int row, int col )" ).c_str(),
			 asMETHODPR(Matrix44<T>,subMatrix33,(int ,int )const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setToNull()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToNull()" ).c_str(),
			 asMETHODPR(Matrix44<T>,setToNull,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setToIdentity()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToIdentity()" ).c_str(),
			 asMETHODPR(Matrix44<T>,setToIdentity,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T determinant() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " determinant()" ).c_str(),
			 asMETHODPR(Matrix44<T>,determinant,()const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T trace( bool fullTrace = false ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " trace( bool fullTrace = false )" ).c_str(),
			 asMETHODPR(Matrix44<T>,trace,(bool )const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix44<T> diagonal() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " diagonal()" ).c_str(),
			 asMETHODPR(Matrix44<T>,diagonal,()const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix44<T> lowerTriangular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lowerTriangular()" ).c_str(),
			 asMETHODPR(Matrix44<T>,lowerTriangular,()const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix44<T> upperTriangular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " upperTriangular()" ).c_str(),
			 asMETHODPR(Matrix44<T>,upperTriangular,()const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void transpose()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void transpose()" ).c_str(),
			 asMETHODPR(Matrix44<T>,transpose,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix44<T> transposed() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " transposed()" ).c_str(),
			 asMETHODPR(Matrix44<T>,transposed,()const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix44<T> inverted( T epsilon = FLT_MIN ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverted( " + type + " epsilon = FLT_MIN )" ).c_str(),
			 asMETHODPR(Matrix44<T>,inverted,(T )const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> preMultiply( const Vec3<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " preMultiply( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,preMultiply,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec4<T> preMultiply( const Vec4<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec4" + suffix + " preMultiply( const Vec4" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,preMultiply,(const Vec4<T> &)const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> postMultiply( const Vec3<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " postMultiply( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,postMultiply,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec4<T> postMultiply( const Vec4<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec4" + suffix + " postMultiply( const Vec4" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,postMultiply,(const Vec4<T> &)const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void affineInvert()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void affineInvert()" ).c_str(),
			 asMETHODPR(Matrix44<T>,affineInvert,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix44<T> affineInverted() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " affineInverted()" ).c_str(),
			 asMETHODPR(Matrix44<T>,affineInverted,()const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void orthonormalInvert()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void orthonormalInvert()" ).c_str(),
			 asMETHODPR(Matrix44<T>,orthonormalInvert,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix44<T> orthonormalInverted() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " orthonormalInverted()" ).c_str(),
			 asMETHODPR(Matrix44<T>,orthonormalInverted,()const,Matrix44<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> transformPoint( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " transformPoint( const Vec3" + suffix + " &in rhs )" ).c_str(),
			 asMETHODPR(Matrix44<T>,transformPoint,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> transformPointAffine( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " transformPointAffine( const Vec3" + suffix + " &in rhs )" ).c_str(),
			 asMETHODPR(Matrix44<T>,transformPointAffine,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> transformVec( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " transformVec( const Vec3" + suffix + " &in rhs )" ).c_str(),
			 asMETHODPR(Matrix44<T>,transformVec,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec4<T> transformVec( const Vec4<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec4" + suffix + " transformVec( const Vec4" + suffix + " &in rhs )" ).c_str(),
			 asMETHODPR(Matrix44<T>,transformVec,(const Vec4<T> &)const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec4<T> getTranslate() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec4" + suffix + " getTranslate()" ).c_str(),
			 asMETHODPR(Matrix44<T>,getTranslate,()const,Vec4<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setTranslate( const Vec3<T>& v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setTranslate( const Vec3" + suffix + "&in  v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,setTranslate,(const Vec3<T>& ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTranslate( const Vec4<T>& v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setTranslate( const Vec4" + suffix + "&in  v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,setTranslate,(const Vec4<T>& ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void translate( const Vec3<T> &tr )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void translate( const Vec3" + suffix + " &in tr )" ).c_str(),
			 asMETHODPR(Matrix44<T>,translate,(const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void translate( const Vec4<T> &tr )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void translate( const Vec4" + suffix + " &in tr )" ).c_str(),
			 asMETHODPR(Matrix44<T>,translate,(const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void rotate( const Vec3<T> &axis, T radians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const Vec3" + suffix + " &in axis, " + type + " radians )" ).c_str(),
			 asMETHODPR(Matrix44<T>,rotate,(const Vec3<T> &,T ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void rotate( const Vec4<T> &axis, T radians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const Vec4" + suffix + " &in axis, " + type + " radians )" ).c_str(),
			 asMETHODPR(Matrix44<T>,rotate,(const Vec4<T> &,T ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void rotate( const Vec3<T> &eulerRadians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const Vec3" + suffix + " &in eulerRadians )" ).c_str(),
			 asMETHODPR(Matrix44<T>,rotate,(const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void rotate( const Vec4<T> &eulerRadians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const Vec4" + suffix + " &in eulerRadians )" ).c_str(),
			 asMETHODPR(Matrix44<T>,rotate,(const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void rotate( const Vec3<T> &from, const Vec3<T> &to, const Vec3<T> &worldUp )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const Vec3" + suffix + " &in from, const Vec3" + suffix + " &in to, const Vec3" + suffix + " &in worldUp )" ).c_str(),
			 asMETHODPR(Matrix44<T>,rotate,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void rotate( const Vec4<T> &from, const Vec4<T> &to, const Vec4<T> &worldUp )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const Vec4" + suffix + " &in from, const Vec4" + suffix + " &in to, const Vec4" + suffix + " &in worldUp )" ).c_str(),
			 asMETHODPR(Matrix44<T>,rotate,(const Vec4<T> &,const Vec4<T> &,const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void scale( T s )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( " + type + " s )" ).c_str(),
			 asMETHODPR(Matrix44<T>,scale,(T ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scale( const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,scale,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scale( const Vec3<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,scale,(const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scale( const Vec4<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( const Vec4" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix44<T>,scale,(const Vec4<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Matrix44<T> invertTransform() const
		/*r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " invertTransform()" ).c_str(),
			 asMETHOD(Matrix44<T>,invertTransform), asCALL_THISCALL ); assert( r >= 0 );
*/


		// STATIC METHOD: Matrix44<T> identity()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " identity()" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::identity,(),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix44<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::one,(),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix44<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::zero,(),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix44<T> createTranslation( const Vec3<T> &v, T w = 1 )
		r = engine->RegisterGlobalFunction( std::string( name + " createTranslation( const Vec3" + suffix + " &in v, " + type + " w = 1 )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createTranslation,(const Vec3<T> &,T ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createTranslation( const Vec4<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createTranslation( const Vec4" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createTranslation,(const Vec4<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix44<T> createRotation( const Vec3<T> &axis, T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec3" + suffix + " &in axis, " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotation,(const Vec3<T> &,T ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createRotation( const Vec4<T> &axis, T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec4" + suffix + " &in axis, " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotation,(const Vec4<T> &,T ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createRotation( const Vec3<T> &from, const Vec3<T> &to, const Vec3<T> &worldUp )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec3" + suffix + " &in from, const Vec3" + suffix + " &in to, const Vec3" + suffix + " &in worldUp )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotation,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createRotation( const Vec4<T> &from, const Vec4<T> &to, const Vec4<T> &worldUp )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec4" + suffix + " &in from, const Vec4" + suffix + " &in to, const Vec4" + suffix + " &in worldUp )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotation,(const Vec4<T> &,const Vec4<T> &,const Vec4<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix44<T> createRotation( const Vec3<T> &eulerRadians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec3" + suffix + " &in eulerRadians )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotation,(const Vec3<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createRotation( const Vec4<T> &eulerRadians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec4" + suffix + " &in eulerRadians )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotation,(const Vec4<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix44<T> createRotationOnb( const Vec3<T>& u, const Vec3<T>& v, const Vec3<T>& w )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotationOnb( const Vec3" + suffix + "&in  u, const Vec3" + suffix + "&in  v, const Vec3" + suffix + "&in  w )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotationOnb,(const Vec3<T>& ,const Vec3<T>& ,const Vec3<T>& ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createRotationOnb( const Vec4<T>& u, const Vec4<T>& v, const Vec4<T>& w )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotationOnb( const Vec4" + suffix + "&in  u, const Vec4" + suffix + "&in  v, const Vec4" + suffix + "&in  w )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createRotationOnb,(const Vec4<T>& ,const Vec4<T>& ,const Vec4<T>& ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix44<T> createScale( T s )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( " + type + " s )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createScale,(T ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createScale( const Vec2<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createScale,(const Vec2<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createScale( const Vec3<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( const Vec3" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createScale,(const Vec3<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> createScale( const Vec4<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( const Vec4" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::createScale,(const Vec4<T> &),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix44<T> alignZAxisWithTarget( Vec3<T> targetDir, Vec3<T> upDir )
		r = engine->RegisterGlobalFunction( std::string( name + " alignZAxisWithTarget( Vec3" + suffix + " targetDir, Vec3" + suffix + " upDir )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::alignZAxisWithTarget,(Vec3<T> ,Vec3<T> ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix44<T> alignZAxisWithTarget( Vec4<T> targetDir, Vec4<T> upDir )
		r = engine->RegisterGlobalFunction( std::string( name + " alignZAxisWithTarget( Vec4" + suffix + " targetDir, Vec4" + suffix + " upDir )" ).c_str(),
			 asFUNCTIONPR(Matrix44<T>::alignZAxisWithTarget,(Vec4<T> ,Vec4<T> ),Matrix44<T>), asCALL_CDECL ); assert( r >= 0 );


		//  friend std::ostream& operator<<( std::ostream &lhs, const Matrix44<T> &rhs )


		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrix44Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrix44Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrix44Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrix44Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
