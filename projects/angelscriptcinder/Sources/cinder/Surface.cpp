#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Surface.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderSurfaceTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(SurfaceT<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderSurfaceTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<SurfaceT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<SurfaceT<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<SurfaceT<T>,const SurfaceT<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<SurfaceT<T>&,SurfaceT<T>,SurfaceT<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// PROPERTY: */
		// CONSTRUCTOR: SurfaceT( int32_t width, int32_t height, bool alpha, SurfaceChannelOrder channelOrder = SurfaceChannelOrder::UNSPECIFIED )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( int32 width, int32 height, bool alpha )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<SurfaceT<T>,int32_t ,int32_t ,bool ,SurfaceChannelOrder > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
/*
		// CONSTRUCTOR: SurfaceT( int32_t width, int32_t height, bool alpha, const SurfaceConstraints &constraints )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( int32 width, int32 height, bool alpha, const SurfaceConstraints &in constraints )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<SurfaceT<T>,int32_t ,int32_t ,bool ,const SurfaceConstraints &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//  SurfaceT( T *data, int32_t width, int32_t height, int32_t rowBytes, SurfaceChannelOrder channelOrder )

		// CONSTRUCTOR: SurfaceT( ImageSourceRef imageSource, const SurfaceConstraints &constraints = SurfaceConstraintsDefault(), boost::tribool alpha = boost::logic::indeterminate )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( ImageSourceRef imageSource, const SurfaceConstraints &in constraints = SurfaceConstraintsDefault()" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<SurfaceT<T>,ImageSourceRef ,const SurfaceConstraints &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

*/


		// METHOD: int32_t getWidth() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int32 getWidth()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getWidth,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int32_t getHeight() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int32 getHeight()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getHeight,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Vec2i getSize()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getAspectRatio() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "float getAspectRatio()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getAspectRatio,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getBounds() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Area getBounds()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getBounds,()const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasAlpha() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool hasAlpha()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,hasAlpha,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isPremultiplied() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isPremultiplied()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,isPremultiplied,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool setPremultiplied( bool premult = true ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool setPremultiplied( bool premult = true )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,setPremultiplied,(bool )const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int32_t getRowBytes() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "int32 getRowBytes()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getRowBytes,()const,int32_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: uint8_t getPixelInc() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint8 getPixelInc()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getPixelInc,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: SurfaceT clone( bool copyPixels = true ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " clone( bool copyPixels = true )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,clone,(bool )const,SurfaceT<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: SurfaceT clone( const Area &area, bool copyPixels = true ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( name + " clone( const Area &in area, bool copyPixels = true )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,clone,(const Area &,bool )const,SurfaceT<T>), asCALL_THISCALL ); assert( r >= 0 );



		//  T* getData()
		//  const T* getData() const
		//  T* getData( const Vec2i &offset )
		//  const T* getData( const Vec2i &offset ) const

		//  T* getDataRed( const Vec2i &offset )
		//  const T* getDataRed( const Vec2i &offset ) const

		//  T* getDataGreen( const Vec2i &offset )
		//  const T* getDataGreen( const Vec2i &offset ) const

		//  T* getDataBlue( const Vec2i &offset )
		//  const T* getDataBlue( const Vec2i &offset ) const

		//  T* getDataAlpha( const Vec2i &offset )
		//  const T* getDataAlpha( const Vec2i &offset ) const


		//  void setDeallocator( void(*aDeallocatorFunc)( void * ), void *aDeallocatorRefcon )

/*
		// METHOD: const SurfaceChannelOrder& getChannelOrder() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "const SurfaceChannelOrder& getChannelOrder()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getChannelOrder,()const,const SurfaceChannelOrder&), asCALL_THISCALL ); assert( r >= 0 );
*/

		// METHOD: uint8_t getRedOffset() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint8 getRedOffset()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getRedOffset,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: uint8_t getGreenOffset() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint8 getGreenOffset()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getGreenOffset,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: uint8_t getBlueOffset() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint8 getBlueOffset()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getBlueOffset,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: uint8_t getAlphaOffset() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint8 getAlphaOffset()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getAlphaOffset,()const,uint8_t), asCALL_THISCALL ); assert( r >= 0 );


	/*	// METHOD: void setChannelOrder( const SurfaceChannelOrder &aChannelOrder )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setChannelOrder( const SurfaceChannelOrder &in aChannelOrder )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,setChannelOrder,(const SurfaceChannelOrder &),void), asCALL_THISCALL ); assert( r >= 0 );

*/

		// METHOD: ChannelT<T>& getChannel( uint8_t channelIndex )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Channel& getChannel( uint8 channelIndex )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getChannel,(uint8_t ),ChannelT<T>&), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: ChannelT<T>& getChannelRed()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Channel& getChannelRed()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getChannelRed,(),ChannelT<T>&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: ChannelT<T>& getChannelGreen()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Channel& getChannelGreen()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getChannelGreen,(),ChannelT<T>&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: ChannelT<T>& getChannelBlue()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Channel& getChannelBlue()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getChannelBlue,(),ChannelT<T>&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: ChannelT<T>& getChannelAlpha()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Channel& getChannelAlpha()" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getChannelAlpha,(),ChannelT<T>&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: ColorAT<T> getPixel( Vec2i pos ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "ColorA getPixel( Vec2i pos )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,getPixel,(Vec2i )const,ColorAT<T>), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setPixel( Vec2i pos, const ColorT<T> &c )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setPixel( Vec2i pos, const Color &in c )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,setPixel,(Vec2i ,const ColorT<T> &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setPixel( Vec2i pos, const ColorAT<T> &c )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setPixel( Vec2i pos, const ColorA &in c )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,setPixel,(Vec2i ,const ColorAT<T> &),void), asCALL_THISCALL ); assert( r >= 0 );

/*

		// CONSTRUCTOR: void copyFrom( const SurfaceT<T> &srcSurface, const Area &srcArea, const Vec2i &relativeOffset = Vec2i::zero() )
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void copyFrom( const void f" + suffix + " &in srcSurface, const Area &in srcArea, const Vec2i &in relativeOffset = Vec2i::zero()" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<SurfaceT<T>,const SurfaceT<T> &,const Area &,const Vec2i &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


*/
		// METHOD: ColorT<T> areaAverage( const Area &area ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "Color areaAverage( const Area &in area )" ).c_str(),
			 asMETHODPR(SurfaceT<T>,areaAverage,(const Area &)const,ColorT<T>), asCALL_THISCALL ); assert( r >= 0 );


	}


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderSurfaceTType<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderSurfaceTImpl<uint8_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);



	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderSurfaceTType<uint16_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderSurfaceTImpl<uint16_t>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);


	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderSurfaceTType<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderSurfaceTImpl<float>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
}
