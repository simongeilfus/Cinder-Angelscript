#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Channel.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderChannelTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(ChannelT<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderChannelTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<ChannelT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<ChannelT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ChannelT<T>,const ChannelT<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<ChannelT<T>&,ChannelT<T>,ChannelT<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// CONSTRUCTOR: ChannelT( int32_t width, int32_t height )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( int32 width, int32 height )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ChannelT<T>,int32_t ,int32_t > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//  ChannelT( int32_t width, int32_t height, int32_t rowBytes, uint8_t increment, T *data )

		// CONSTRUCTOR: ChannelT( ImageSourceRef imageSource )
/*		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( ImageSourceRef imageSource )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<ChannelT<T>,ImageSourceRef > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

*/

		// METHOD: ChannelT clone( bool copyPixels = true ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " clone( bool copyPixels = true )" ).c_str(),
			 asMETHODPR(ChannelT<T>,clone,(bool )const,ChannelT<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: ChannelT clone( const Area &area, bool copyPixels = true ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " clone( const Area &in area, bool copyPixels = true )" ).c_str(),
			 asMETHODPR(ChannelT<T>,clone,(const Area &,bool )const,ChannelT<T>), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: int32_t getWidth() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int32 getWidth()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getWidth,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int32_t getHeight() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int32 getHeight()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getHeight,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2i getSize()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getAspectRatio() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float getAspectRatio()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getAspectRatio,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getBounds() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Area getBounds()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getBounds,()const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int32_t getRowBytes() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int32 getRowBytes()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getRowBytes,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: uint8_t getIncrement() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint8 getIncrement()" ).c_str(),
			 asMETHODPR(ChannelT<T>,getIncrement,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isPlanar() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isPlanar()" ).c_str(),
			 asMETHODPR(ChannelT<T>,isPlanar,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		//  T* getData()

		//  const T* getData() const

		//  T* getData( const Vec2i &offset )

		//  const T* getData( const Vec2i &offset ) const

		//  T* getData( int32_t x, int32_t y )

		//  const T* getData( int32_t x, int32_t y ) const



		// METHOD: void setValue( Vec2i pos, T v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setValue( Vec2i pos, " + type + " v )" ).c_str(),
			 asMETHODPR(ChannelT<T>,setValue,(Vec2i ,T ),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void copyFrom( const ChannelT<T> &srcChannel, const Area &srcArea, const Vec2i &relativeOffset = Vec2i::zero() )


		// METHOD: T areaAverage( const Area &area ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " areaAverage( const Area &in area )" ).c_str(),
			 asMETHODPR(ChannelT<T>,areaAverage,(const Area &)const,T), asCALL_THISCALL ); assert( r >= 0 );



		//  void setDeallocator( void(*aDeallocatorFunc)( void * ), void *aDeallocatorRefcon )

	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderChannelTType<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderChannelTImpl<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);



	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderChannelTType<uint16_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderChannelTImpl<uint16_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderChannelTType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderChannelTImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
