#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Color.h"
#include "cinder/Utilities.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderColorTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(ColorT<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderColorTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<ColorT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<ColorT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorT<T>,const ColorT<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + " & opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<ColorT<T>&,ColorT<T>,const ColorT<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: T r,g,b
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " r" ).c_str(),
                                           asOFFSET(ColorT<T>,r)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " g" ).c_str(),
                                           asOFFSET(ColorT<T>,g)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " b" ).c_str(),
                                           asOFFSET(ColorT<T>,b)); assert( r >= 0 );

		// CONSTRUCTOR: ColorT( T aR, T aG, T aB )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " aR, " + type + " aG, " + type + " aB )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorT<T>,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : r( aR ), g( aG ), b( aB )

		//  : r( src.r ), g( src.g ), b( src.b )

		//  ColorT( const char *svgColorName )
        
        if( engine->GetObjectTypeByName( "Vec3f" ) != NULL ){
            // CONSTRUCTOR: ColorT( int cm, const Vec3f &v )
            r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
                                                std::string( "void f( int cm, const Vec3f &in v )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorT<T>,ColorModel ,const Vec3f &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        }
		// CONSTRUCTOR: ColorT( int cm, float x, float y, float z )
		/*r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( int cm, float x, float y, float z )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorT<T>,ColorModel ,float ,float ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/


		// METHOD: void set( T ar, T ag, T ab )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " ar, " + type + " ag, " + type + " ab )" ).c_str(),
			 asMETHODPR(ColorT<T>,set,(T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: void set( const ColorT<T> &rhs )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(ColorT<T>,set,(const ColorT<T> &),void), asCALL_THISCALL ); assert( r >= 0 );



        
        if( engine->GetObjectTypeByName( "Vec3f" ) != NULL ){
            // METHOD: void set( int cm, const Vec3f &v )
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( int cm, const Vec3f &in v )" ).c_str(),
                                             asMETHODPR(ColorT<T>,set,(ColorModel ,const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );
        }

		// OPERATOR NOT SUPPORTED: ColorT<T> operator=( const ColorT<T> &rhs )



		//template<class FromT>
		// OPERATOR NOT SUPPORTED: ColorT<T> operator=( const ColorT<FromT> &rhs )


        
        if( engine->GetObjectTypeByName( "Vec3f" ) != NULL ){
            // METHOD: Vec3f get( int cm ) const
            r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec3f get( int cm )" ).c_str(),
                                             asMETHODPR(ColorT<T>,get,(ColorModel )const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );
        }


		// OPERATOR NOT SUPPORTED: T& operator[]( int n )



		// OPERATOR NOT SUPPORTED: const T& operator[]( int n ) const



		//  T* ptr() const

		// OPERATOR: ColorT<T> operator+( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opAdd( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<ColorT<T>,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator-( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opSub( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<ColorT<T>,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator*( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opMul( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<ColorT<T>,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator/( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opDiv( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<ColorT<T>,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator+=( const ColorT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opAddAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<const ColorT<T>&,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator-=( const ColorT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opSubAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<const ColorT<T>&,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator*=( const ColorT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opMulAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<const ColorT<T>&,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator/=( const ColorT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opDivAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<const ColorT<T>&,ColorT<T>,const ColorT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator+( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opAdd( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<ColorT<T>,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator-( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opSub( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<ColorT<T>,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator*( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opMul( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<ColorT<T>,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorT<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<ColorT<T>,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator+=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opAddAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<const ColorT<T>&,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator-=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opSubAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<const ColorT<T>&,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator*=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opMulAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<const ColorT<T>&,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorT<T>& operator/=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opDivAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<const ColorT<T>&,ColorT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR NOT SUPPORTED: bool operator==( const ColorT<T>& rhs ) const



		// OPERATOR NOT SUPPORTED: bool operator!=( const ColorT<T>& rhs ) const



		// METHOD: float dot( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float dot( const " + name + " &in rhs )" ).c_str(),
			 asMETHOD(ColorT<T>,dot), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float distance( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float distance( const " + name + " &in rhs )" ).c_str(),
			 asMETHODPR(ColorT<T>,distance,(const ColorT<T> &)const,float), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float distanceSquared( const ColorT<T> &rhs ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float distanceSquared( const " + name + " &in rhs )" ).c_str(),
			 asMETHOD(ColorT<T>,distanceSquared), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float length() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float length()" ).c_str(),
			 asMETHODPR(ColorT<T>,length,()const,float), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float lengthSquared() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float lengthSquared()" ).c_str(),
			 asMETHOD(ColorT<T>,lengthSquared), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void normalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void normalize()" ).c_str(),
			 asMETHODPR(ColorT<T>,normalize,(),void), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: ColorT<T> lerp( float fact, const ColorT<T> &d ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lerp( float fact, const " + name + " &in d )" ).c_str(),
			 asMETHODPR(ColorT<T>,lerp,(float ,const ColorT<T> &)const,ColorT<T>), asCALL_THISCALL ); assert( r >= 0 );




		// STATIC METHOD: ColorT<T> max()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " max()" ).c_str(),
			 asFUNCTIONPR(ColorT<T>::max,(),ColorT<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: ColorT<T> black()
		r = engine->RegisterGlobalFunction( std::string( name + " black()" ).c_str(),
			 asFUNCTIONPR(ColorT<T>::black,(),ColorT<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: ColorT<T> white()
		r = engine->RegisterGlobalFunction( std::string( name + " white()" ).c_str(),
			 asFUNCTIONPR(ColorT<T>::white,(),ColorT<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: ColorT<T> gray( T value )
		r = engine->RegisterGlobalFunction( std::string( name + " gray( " + type + " value )" ).c_str(),
			 asFUNCTIONPR(ColorT<T>::gray,(T ),ColorT<T>), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: ColorT<T> hex( uint32_t hexValue )
		r = engine->RegisterGlobalFunction( std::string( name + " hex( uint32 hexValue )" ).c_str(),
			 asFUNCTIONPR(ColorT<T>::hex,(uint32_t ),ColorT<T>), asCALL_CDECL ); assert( r >= 0 );




		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
	template<typename T>
	void registerCinderColorATType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(ColorAT<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
    
    
    template<typename T>
    static void ColorASvgNameConstructor( const std::string& name, float alpha, ColorAT<T>* ptr) { new (ptr) ColorAT<T>(name.c_str(),alpha); }
    
    
	template<typename T>
	void registerCinderColorATImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<ColorAT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<ColorAT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorAT<T>,const ColorAT<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + " & opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<ColorAT<T>&,ColorAT<T>,const ColorAT<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: public:
		// PROPERTY: T r,g,b,a
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " r" ).c_str(),
                                           asOFFSET(ci::ColorT<T>,r)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " g" ).c_str(),
                                           asOFFSET(ci::ColorT<T>,g)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " b" ).c_str(),
                                           asOFFSET(ci::ColorT<T>,b)); assert( r >= 0 );
        r = engine->RegisterObjectProperty( name.c_str(),
                                           (type + " a" ).c_str(),
                                           asOFFSET(ci::ColorT<T>,b)); assert( r >= 0 );

		//  : r( 0 ), g( 0 ), b( 0 ), a( 0 )

		// CONSTRUCTOR: ColorAT( T aR, T aG, T aB, T aA )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( " + type + " aR, " + type + " aG, " + type + " aB, " + type + " aA )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorAT<T>,T ,T ,T ,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : r( aR ), g( aG ), b( aB ), a( aA )

		//  : r( src.r ), g( src.g ), b( src.b ), a( src.a )

		// CONSTRUCTOR: ColorAT( const ColorT<T> &col, T aA )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( const Color &in col, " + type + " aA )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorAT<T>,const ColorT<T> &,T > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : r( col.r ), g( col.g ), b( col.b ), a( aA )

		//  ColorAT( const char *svgColorName, T aA )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
                                            std::string( "void f( string svgColorName, float aA = 1.0f )" ).c_str(), asFUNCTION( ColorASvgNameConstructor<T> ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: ColorAT( int cm, float c1, float c2, float c3, float aA = 1.0f )
		/*r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( int cm, float c1, float c2, float c3, float aA = 1.0f )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ColorAT<T>,ColorModel ,float ,float ,float ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );*/


		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: void set( T ar, T ag, T ab , T aa )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void set( " + type + " ar, " + type + " ag, " + type + " ab , " + type + " aa )" ).c_str(),
			 asMETHODPR(ColorAT<T>,set,(T ,T ,T ,T ),void), asCALL_THISCALL ); assert( r >= 0 );







		// OPERATOR NOT SUPPORTED: ColorAT<T> operator=( const ColorAT<T>& rhs )



		//template<class FromT>
		// OPERATOR NOT SUPPORTED: ColorAT<T> operator=( const ColorAT<FromT>& rhs )



		// OPERATOR NOT SUPPORTED: T& operator[]( int n )



		// OPERATOR NOT SUPPORTED: const T& operator[]( int n ) const



		//  T* ptr() const

		// OPERATOR: ColorAT<T> operator+( const ColorAT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opAdd( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<ColorAT<T>,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator-( const ColorAT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opSub( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<ColorAT<T>,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator*( const ColorAT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opMul( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<ColorAT<T>,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator/( const ColorAT<T> &rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opDiv( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<ColorAT<T>,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator+=( const ColorAT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opAddAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<const ColorAT<T>&,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator-=( const ColorAT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opSubAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<const ColorAT<T>&,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator*=( const ColorAT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opMulAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<const ColorAT<T>&,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator/=( const ColorAT<T> &rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opDivAssign( const " + name + " &in rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<const ColorAT<T>&,ColorAT<T>,const ColorAT<T> &>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator+( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opAdd( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAdd<ColorAT<T>,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator-( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opSub( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSub<ColorAT<T>,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator*( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opMul( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMul<ColorAT<T>,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: ColorAT<T> operator/( T rhs ) const
		r = engine->RegisterObjectMethod(name.c_str(), std::string( name + " opDiv( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDiv<ColorAT<T>,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator+=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opAddAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opAddAssign<const ColorAT<T>&,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator-=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opSubAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opSubAssign<const ColorAT<T>&,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator*=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opMulAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opMulAssign<const ColorAT<T>&,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// OPERATOR: const ColorAT<T>& operator/=( T rhs )
		r = engine->RegisterObjectMethod(name.c_str(), std::string( "const " + name + "& opDivAssign( " + type + " rhs )" ).c_str(), asFUNCTION((as::RegistrationHelper::opDivAssign<const ColorAT<T>&,ColorAT<T>,T >)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// OPERATOR NOT SUPPORTED: bool operator==( const ColorAT<T>& rhs ) const



		// OPERATOR NOT SUPPORTED: bool operator!=( const ColorAT<T>& rhs ) const



		// METHOD: float length() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float length()" ).c_str(),
			 asMETHODPR(ColorAT<T>,length,()const,float), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: void normalize()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void normalize()" ).c_str(),
			 asMETHODPR(ColorAT<T>,normalize,(),void), asCALL_THISCALL ); assert( r >= 0 );





		// METHOD: ColorAT<T> premultiplied() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " premultiplied()" ).c_str(),
			 asMETHODPR(ColorAT<T>,premultiplied,()const,ColorAT<T>), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: float lengthSquared() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float lengthSquared()" ).c_str(),
			 asMETHOD(ColorAT<T>,lengthSquared), asCALL_THISCALL ); assert( r >= 0 );




		// METHOD: ColorAT<T> lerp( T fact, const ColorAT<T> &d ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " lerp( " + type + " fact, const " + name + " &in d )" ).c_str(),
			 asMETHODPR(ColorAT<T>,lerp,(T ,const ColorAT<T> &)const,ColorAT<T>), asCALL_THISCALL ); assert( r >= 0 );




		// STATIC METHOD: ColorAT<T> zero()
		r = engine->SetDefaultNamespace( useNamespaces ? ( "ci::" + name ).c_str() : name.c_str() ); assert( r >= 0 );
		r = engine->RegisterGlobalFunction( std::string( name + " zero()" ).c_str(),
			 asFUNCTIONPR(ColorAT<T>::zero,(),ColorAT<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: ColorAT<T> black()
		r = engine->RegisterGlobalFunction( std::string( name + " black()" ).c_str(),
			 asFUNCTIONPR(ColorAT<T>::black,(),ColorAT<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: ColorAT<T> white()
		r = engine->RegisterGlobalFunction( std::string( name + " white()" ).c_str(),
			 asFUNCTIONPR(ColorAT<T>::white,(),ColorAT<T>), asCALL_CDECL ); assert( r >= 0 );




		//  static ColorAT<T> gray( T value, T alpha = CHANTRAIT<T>::max() )
		r = engine->RegisterGlobalFunction( std::string( name + " gray( " + type + " value, " + type + " alpha = " + toString( CHANTRAIT<T>::max() ) + " )" ).c_str(), asFUNCTIONPR(ColorAT<T>::gray,(T,T),ColorAT<T>), asCALL_CDECL ); assert( r >= 0 );




		// STATIC METHOD: ColorAT<T> hex( uint32_t hexValue )
		r = engine->RegisterGlobalFunction( std::string( name + " hex( uint32 hexValue )" ).c_str(),
			 asFUNCTIONPR(ColorAT<T>::hex,(uint32_t ),ColorAT<T>), asCALL_CDECL ); assert( r >= 0 );





		// STATIC METHOD: ColorAT<T> hexA( uint32_t hexValue )
		r = engine->RegisterGlobalFunction( std::string( name + " hexA( uint32 hexValue )" ).c_str(),
			 asFUNCTIONPR(ColorAT<T>::hexA,(uint32_t ),ColorAT<T>), asCALL_CDECL ); assert( r >= 0 );




		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderColorTType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderColorTImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderColorTType<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderColorTImpl<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderColorATType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderColorATImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderColorATType<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderColorATImpl<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
