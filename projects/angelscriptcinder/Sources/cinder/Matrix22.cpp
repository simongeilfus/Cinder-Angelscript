#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Matrix22.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderMatrix22Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(Matrix22<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderMatrix22Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Matrix22<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Matrix22<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix22<T>,const Matrix22<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<Matrix22<T>&,Matrix22<T>,Matrix22<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef T TYPE
		// PROPERTY: typedef T value_type

		// PROPERTY: static const size_t DIM = 2
		// PROPERTY: static const size_t DIM_SQ = DIM*DIM
		//  static const size_t MEM_LEN = sizeof(T)*DIM_SQ











		// PROPERTY: union




		// CONSTRUCTOR: Matrix22( T s )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " s )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix22<T>,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		//  Matrix22( const T *dt, bool srcIsRowMajor = false )


		// CONSTRUCTOR: Matrix22( T d0, T d1, T d2, T d3, bool srcIsRowMajor = false )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " d0, " + type + " d1, " + type + " d2, " + type + " d3, bool srcIsRowMajor = false )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix22<T>,T ,T ,T ,T ,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// CONSTRUCTOR: Matrix22( const Vec2<T> &vx, const Vec2<T> &vy )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Vec2" + suffix + " &in vx, const Vec2" + suffix + " &in vy )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<Matrix22<T>,const Vec2<T> &,const Vec2<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//template< typename FromT >
		//  Matrix22( const Matrix22<FromT>& src )



		// OPERATOR NOT SUPPORTED: Matrix22<T>& operator=( const Matrix22<T>& rhs )
		// OPERATOR NOT SUPPORTED: Matrix22<T>& operator=( const T &rhs )

		//template< typename FromT >
		// OPERATOR NOT SUPPORTED: Matrix22<T>& operator=( const Matrix22<FromT>& rhs )

		// METHOD: bool equalCompare( const Matrix22<T>& rhs, T epsilon ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool equalCompare( const " + name + "&in  rhs, " + type + " epsilon )" ).c_str(),
			 asMETHODPR(Matrix22<T>,equalCompare,(const Matrix22<T>& ,T )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// OPERATOR NOT SUPPORTED: bool operator==( const Matrix22<T> &rhs ) const
		// OPERATOR NOT SUPPORTED: bool operator!=( const Matrix22<T> &rhs ) const

		// OPERATOR: Matrix22<T>& operator*=( const Matrix22<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Matrix22<T>&,Matrix22<T>,const Matrix22<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix22<T>& operator+=( const Matrix22<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Matrix22<T>&,Matrix22<T>,const Matrix22<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix22<T>& operator-=( const Matrix22<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Matrix22<T>&,Matrix22<T>,const Matrix22<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: Matrix22<T>& operator*=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opMulAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<Matrix22<T>&,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix22<T>& operator/=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opDivAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<Matrix22<T>&,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix22<T>& operator+=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opAddAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<Matrix22<T>&,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: Matrix22<T>& operator-=( T s )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + "& opSubAssign( " + type + " s )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<Matrix22<T>&,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Matrix22<T> operator*( const Matrix22<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Matrix22<T>,Matrix22<T>,const Matrix22<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix22<T> operator+( const Matrix22<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Matrix22<T>,Matrix22<T>,const Matrix22<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix22<T> operator-( const Matrix22<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Matrix22<T>,Matrix22<T>,const Matrix22<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// OPERATOR: const Vec2<T> operator*( const Vec2<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const Vec2" + suffix + " opMul( const Vec2" + suffix + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Vec2<T>,Matrix22<T>,const Vec2<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR: const Matrix22<T> operator*( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opMul( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<const Matrix22<T>,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix22<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<const Matrix22<T>,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix22<T> operator+( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opAdd( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<const Matrix22<T>,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const Matrix22<T> operator-( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + " opSub( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<const Matrix22<T>,Matrix22<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: T& at( int row, int col )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + "& at( int row, int col )" ).c_str(),
			 asMETHODPR(Matrix22<T>,at,(int ,int ),T&), asCALL_THISCALL ); assert( r >= 0 );


		//  void set( const T *dt, bool srcIsRowMajor = false )

		// METHOD: void set( T d0, T d1, T d2, T d3, bool srcIsRowMajor = false )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " d0, " + type + " d1, " + type + " d2, " + type + " d3, bool srcIsRowMajor = false )" ).c_str(),
			 asMETHODPR(Matrix22<T>,set,(T ,T ,T ,T ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2<T> getColumn( int col ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getColumn( int col )" ).c_str(),
			 asMETHODPR(Matrix22<T>,getColumn,(int )const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColumn( int col, const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumn( int col, const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix22<T>,setColumn,(int ,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2<T> getRow( int row ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " getRow( int row )" ).c_str(),
			 asMETHODPR(Matrix22<T>,getRow,(int )const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setRow( int row, const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRow( int row, const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix22<T>,setRow,(int ,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getColumns( Vec2<T> *c0, Vec2<T> *c1 ) const
		// METHOD: void setColumns( const Vec2<T> &c0, const Vec2<T> &c1 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setColumns( const Vec2" + suffix + " &in c0, const Vec2" + suffix + " &in c1 )" ).c_str(),
			 asMETHODPR(Matrix22<T>,setColumns,(const Vec2<T> &,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void getRows( Vec2<T> *r0, Vec2<T> *r1 ) const
		// METHOD: void setRows( const Vec2<T> &r0, const Vec2<T> &r1 )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setRows( const Vec2" + suffix + " &in r0, const Vec2" + suffix + " &in r1 )" ).c_str(),
			 asMETHODPR(Matrix22<T>,setRows,(const Vec2<T> &,const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setToNull()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToNull()" ).c_str(),
			 asMETHODPR(Matrix22<T>,setToNull,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setToIdentity()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setToIdentity()" ).c_str(),
			 asMETHODPR(Matrix22<T>,setToIdentity,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T determinant() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " determinant()" ).c_str(),
			 asMETHODPR(Matrix22<T>,determinant,()const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T trace() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " trace()" ).c_str(),
			 asMETHODPR(Matrix22<T>,trace,()const,T), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix22<T> diagonal() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " diagonal()" ).c_str(),
			 asMETHODPR(Matrix22<T>,diagonal,()const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix22<T> lowerTriangular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lowerTriangular()" ).c_str(),
			 asMETHODPR(Matrix22<T>,lowerTriangular,()const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix22<T> upperTriangular() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " upperTriangular()" ).c_str(),
			 asMETHODPR(Matrix22<T>,upperTriangular,()const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void transpose()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void transpose()" ).c_str(),
			 asMETHODPR(Matrix22<T>,transpose,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Matrix22<T> transposed() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " transposed()" ).c_str(),
			 asMETHODPR(Matrix22<T>,transposed,()const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix22<T> inverted( T epsilon = FLT_MIN ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " inverted( " + type + " epsilon = FLT_MIN )" ).c_str(),
			 asMETHODPR(Matrix22<T>,inverted,(T )const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec2<T> preMultiply( const Vec2<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " preMultiply( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix22<T>,preMultiply,(const Vec2<T> &)const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec2<T> postMultiply( const Vec2<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " postMultiply( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix22<T>,postMultiply,(const Vec2<T> &)const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Vec2<T> transformVec( const Vec2<T> &v ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2" + suffix + " transformVec( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix22<T>,transformVec,(const Vec2<T> &)const,Vec2<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void rotate( T radians )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void rotate( " + type + " radians )" ).c_str(),
			 asMETHODPR(Matrix22<T>,rotate,(T ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void scale( T s )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( " + type + " s )" ).c_str(),
			 asMETHODPR(Matrix22<T>,scale,(T ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void scale( const Vec2<T> &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void scale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asMETHODPR(Matrix22<T>,scale,(const Vec2<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Matrix22<T> invertTransform() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " invertTransform()" ).c_str(),
			 asMETHODPR(Matrix22<T>,invertTransform,()const,Matrix22<T>), asCALL_THISCALL ); assert( r >= 0 );



		// STATIC METHOD: Matrix22<T> identity()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " identity()" ).c_str(),
			 asFUNCTIONPR(Matrix22<T>::identity,(),Matrix22<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix22<T> one()
		r = engine->RegisterGlobalFunction( std::string( name + " one()" ).c_str(),
			 asFUNCTIONPR(Matrix22<T>::one,(),Matrix22<T>), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: Matrix22<T> zero()
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(Matrix22<T>::zero,(),Matrix22<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix22<T> createRotation( T radians )
		r = engine->RegisterGlobalFunction( std::string( name + " createRotation( " + type + " radians )" ).c_str(),
			 asFUNCTIONPR(Matrix22<T>::createRotation,(T ),Matrix22<T>), asCALL_CDECL ); assert( r >= 0 );



		// STATIC METHOD: Matrix22<T> createScale( T s )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( " + type + " s )" ).c_str(),
			 asFUNCTIONPR(Matrix22<T>::createScale,(T ),Matrix22<T>), asCALL_CDECL ); assert( r >= 0 );

		// STATIC METHOD: Matrix22<T> createScale( const Vec2<T> &v )
		r = engine->RegisterGlobalFunction( std::string( name + " createScale( const Vec2" + suffix + " &in v )" ).c_str(),
			 asFUNCTIONPR(Matrix22<T>::createScale,(const Vec2<T> &),Matrix22<T>), asCALL_CDECL ); assert( r >= 0 );


		//  friend std::ostream& operator<<( std::ostream& lhs, const Matrix22<T>& rhs )



		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrix22Type<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrix22Impl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderMatrix22Type<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderMatrix22Impl<double>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
