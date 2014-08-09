#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Matrix.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderMatrix33Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Matrix33<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderMatrix33Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Matrix33<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Matrix33<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix33<T>,const Matrix33<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Matrix33<T>&,Matrix33<T>,Matrix33<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type

		// PROPERTY: static const size_t DIM = 3
		// PROPERTY: static const size_t DIM_SQ = DIM*DIM
		//  static const size_t MEM_LEN = sizeof(T)*DIM_SQ













		// PROPERTY: union




		// CONSTRUCTOR: Matrix33( T s )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " s )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix33<T>,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		//  Matrix33( const T *dt, bool srcIsRowMajor = false )





		// CONSTRUCTOR: Matrix33( const Vec3<T> &vx, const Vec3<T> &vy, const Vec3<T> &vz )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec3" + suffix + " &in vx, const Vec3" + suffix + " &in vy, const Vec3" + suffix + " &in vz )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix33<T>,const Vec3<T> &,const Vec3<T> &,const Vec3<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//template< typename FromT >
		//  Matrix33( const Matrix33<FromT>& src )

		// CONSTRUCTOR: Matrix33( const Matrix22<T>& src )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Matrix22" + suffix + "&in  src )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix33<T>,const Matrix22<T>& > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );




		// OPERATOR NOT SUPPORTED: Matrix33<T>& operator=( const Matrix33<T>& rhs )
		// OPERATOR NOT SUPPORTED: Matrix33<T>& operator=( T rhs )

		//template< typename FromT >
		// OPERATOR NOT SUPPORTED: Matrix33<T>& operator=( const Matrix33<FromT>& rhs )


		// OPERATOR NOT SUPPORTED: Matrix33<T>& operator=( const Matrix22<T>& rhs )

		// METHOD: bool equalCompare( const Matrix33<T>& rhs, T epsilon ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool equalCompare( const " + name + "&in  rhs, " + type + " epsilon )" ).c_str(),
			 asMETHODPR(Matrix33<T>,equalCompare,(const Matrix33<T>& ,T )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// OPERATOR NOT SUPPORTED: bool operator==( const Matrix33<T> &rhs ) const
		// OPERATOR NOT SUPPORTED: bool operator!=( const Matrix33<T> &rhs ) const

		// OPERATOR: Matrix33<T>& operator*=( const Matrix33<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Matrix33<T>&,Matrix33<T>,const Matrix33<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix33<T>& operator+=( const Matrix33<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Matrix33<T>&,Matrix33<T>,const Matrix33<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix33<T>& operator-=( const Matrix33<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Matrix33<T>&,Matrix33<T>,const Matrix33<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: Matrix33<T>& operator*=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Matrix33<T>&,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix33<T>& operator/=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Matrix33<T>&,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix33<T>& operator+=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Matrix33<T>&,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix33<T>& operator-=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Matrix33<T>&,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Matrix33<T> operator*( const Matrix33<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Matrix33<T>,Matrix33<T>,const Matrix33<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix33<T> operator+( const Matrix33<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Matrix33<T>,Matrix33<T>,const Matrix33<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix33<T> operator-( const Matrix33<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Matrix33<T>,Matrix33<T>,const Matrix33<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR: const Vec3<T> operator*( const Vec3<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const Vec3" + suffix + " opMul( const Vec3" + suffix + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec3<T>,Matrix33<T>,const Vec3<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Matrix33<T> operator*( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Matrix33<T>,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix33<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Matrix33<T>,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix33<T> operator+( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Matrix33<T>,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix33<T> operator-( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Matrix33<T>,Matrix33<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: T& at( int row, int col )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + "& at( int row, int col )" ).c_str(),
			 asMETHODPR(Matrix33<T>,at,(int ,int ),T&), asCALL_THISCALL ); assert( r >= 0 );




		//  void set( const T *dt, bool srcIsRowMajor = false )

		// METHOD: void set( T d0, T d1, T d2, T d3, T d4, T d5, T d6, T d7, T d8, bool srcIsRowMajor = false )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " d0, " + type + " d1, " + type + " d2, " + type + " d3, " + type + " d4, " + type + " d5, " + type + " d6, " + type + " d7, " + type + " d8, bool srcIsRowMajor = false )" ).c_str(),
			 asMETHODPR(Matrix33<T>,set,(T ,T ,T ,T ,T ,T ,T ,T ,T ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3<T> getColumn( int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " getColumn( int col )" ).c_str(),
			 asMETHODPR(Matrix33<T>,getColumn,(int )const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColumn( int col, const Vec3<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumn( int col, const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix33<T>,setColumn,(int ,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3<T> getRow( int row ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " getRow( int row )" ).c_str(),
			 asMETHODPR(Matrix33<T>,getRow,(int )const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setRow( int row, const Vec3<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRow( int row, const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix33<T>,setRow,(int ,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getColumns( Vec3<T> *c0, Vec3<T> *c1, Vec3<T> *c2 ) const
		// METHOD: void setColumns( const Vec3<T> &c0, const Vec3<T> &c1, const Vec3<T> &c2 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumns( const Vec3" + suffix + " &in c0, const Vec3" + suffix + " &in c1, const Vec3" + suffix + " &in c2 )" ).c_str(),
			 asMETHODPR(Matrix33<T>,setColumns,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getRows( Vec3<T> *r0, Vec3<T> *r1, Vec3<T> *r2 ) const
		// METHOD: void setRows( const Vec3<T> &r0, const Vec3<T> &r1, const Vec3<T> &r2 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRows( const Vec3" + suffix + " &in r0, const Vec3" + suffix + " &in r1, const Vec3" + suffix + " &in r2 )" ).c_str(),
			 asMETHODPR(Matrix33<T>,setRows,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Matrix22<T> subMatrix22( int row, int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Matrix22" + suffix + " subMatrix22( int row, int col )" ).c_str(),
			 asMETHODPR(Matrix33<T>,subMatrix22,(int ,int )const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setToNull()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToNull()" ).c_str(),
			 asMETHODPR(Matrix33<T>,setToNull,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setToIdentity()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToIdentity()" ).c_str(),
			 asMETHODPR(Matrix33<T>,setToIdentity,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T determinant() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " determinant()" ).c_str(),
			 asMETHODPR(Matrix33<T>,determinant,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T trace() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " trace()" ).c_str(),
			 asMETHODPR(Matrix33<T>,trace,()const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix33<T> diagonal() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " diagonal()" ).c_str(),
			 asMETHODPR(Matrix33<T>,diagonal,()const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix33<T> lowerTriangular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lowerTriangular()" ).c_str(),
			 asMETHODPR(Matrix33<T>,lowerTriangular,()const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix33<T> upperTriangular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " upperTriangular()" ).c_str(),
			 asMETHODPR(Matrix33<T>,upperTriangular,()const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void transpose()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void transpose()" ).c_str(),
			 asMETHODPR(Matrix33<T>,transpose,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix33<T> transposed() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " transposed()" ).c_str(),
			 asMETHODPR(Matrix33<T>,transposed,()const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix33<T> inverted( T epsilon = FLT_MIN ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverted( " + type + " epsilon = FLT_MIN )" ).c_str(),
			 asMETHODPR(Matrix33<T>,inverted,(T )const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> preMultiply( const Vec3<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " preMultiply( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix33<T>,preMultiply,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> postMultiply( const Vec3<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " postMultiply( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix33<T>,postMultiply,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec3<T> transformVec( const Vec3<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3" + suffix + " transformVec( const Vec3" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix33<T>,transformVec,(const Vec3<T> &)const,Vec3<T>), asCALL_THISCALL ); assert( r >= 0 );

/*

		//template <template <typename> class VecT>
		// METHOD: void rotate( const VecT<T> &axis, T radians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const VecT" + suffix + " &in axis, " + type + " radians )" ).c_str(),
			 asMETHODPR(Matrix33<T>,rotate,(const VecT<T> &,T ),void), asCALL_THISCALL ); assert( r >= 0 );


		//template <template <typename> class VecT>
		// METHOD: void rotate( const VecT<T> &eulerRadians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const VecT" + suffix + " &in eulerRadians )" ).c_str(),
			 asMETHODPR(Matrix33<T>,rotate,(const VecT<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//template <template <typename> class VecT>
		// METHOD: void rotate( const VecT<T> &from, const VecT<T> &to, const VecT<T> &worldUp )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( const VecT" + suffix + " &in from, const VecT" + suffix + " &in to, const VecT" + suffix + " &in worldUp )" ).c_str(),
			 asMETHODPR(Matrix33<T>,rotate,(const VecT<T> &,const VecT<T> &,const VecT<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

*/

		// METHOD: Matrix33<T> invertTransform() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " invertTransform()" ).c_str(),
			 asMETHODPR(Matrix33<T>,invertTransform,()const,Matrix33<T>), asCALL_THISCALL ); assert( r >= 0 );



		// STATIC METHOD: Matrix33<T> identity()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " identity()" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::identity,(),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix33<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::one,(),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix33<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::zero,(),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix33<T> createRotation( const Vec3<T> &axis, T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec3" + suffix + " &in axis, " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::createRotation,(const Vec3<T> &,T ),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix33<T> createRotation( const Vec3<T> &from, const Vec3<T> &to, const Vec3<T> &worldUp )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec3" + suffix + " &in from, const Vec3" + suffix + " &in to, const Vec3" + suffix + " &in worldUp )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::createRotation,(const Vec3<T> &,const Vec3<T> &,const Vec3<T> &),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix33<T> createRotation( const Vec3<T> &eulerRadians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( const Vec3" + suffix + " &in eulerRadians )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::createRotation,(const Vec3<T> &),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix33<T> createScale( T s )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( " + type + " s )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::createScale,(T ),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix33<T> createScale( const Vec2<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::createScale,(const Vec2<T> &),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix33<T> createScale( const Vec3<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( const Vec3" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::createScale,(const Vec3<T> &),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix33<T> alignZAxisWithTarget( Vec3<T> targetDir, Vec3<T> upDir )
		r = engine->RegisterGlobalFunction( std::string( name + " alignZAxisWithTarget( Vec3" + suffix + " targetDir, Vec3" + suffix + " upDir )" ).c_str(),
			 asFUNCTIONPR(Matrix33<T>::alignZAxisWithTarget,(Vec3<T> ,Vec3<T> ),Matrix33<T>), asCALL_CDECL ); assert( r >= 0 );


		//  friend std::ostream& operator<<( std::ostream &lhs, const Matrix33<T> &rhs )



		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrix33Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrix33Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrix33Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrix33Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
