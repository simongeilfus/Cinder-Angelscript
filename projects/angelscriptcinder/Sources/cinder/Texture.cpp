#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/gl/Texture.h"


using namespace std;
using namespace ci;
using namespace ci::gl;

namespace as {

	void registerCinderTextureFormatType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl::Texture"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "Format", sizeof(Texture::Format), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTextureFormatImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl::Texture"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Format", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Texture::Format>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Format", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Texture::Format>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Format", asBEHAVE_CONSTRUCT,
			"void f(const Format &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture::Format,const Texture::Format &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Format","Format& opAssign(const Format &in)", asFUNCTION((as::RegistrationHelper::opAssign<Texture::Format&,Texture::Format,Texture::Format&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
	}
	void registerCinderTextureType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Texture", sizeof(Texture), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTextureImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Texture>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Texture>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f(const Texture &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,const Texture &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Texture","Texture& opAssign(const Texture &in)", asFUNCTION((as::RegistrationHelper::opAssign<Texture&,Texture,Texture&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: struct Format

		// PROPERTY: public:


		// CONSTRUCTOR: Texture( int aWidth, int aHeight, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( int aWidth, int aHeight, gl::Texture::Format format = gl::Texture::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,int ,int ,Texture::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//  Texture( const unsigned char *data, int dataFormat, int aWidth, int aHeight, Format format = Format() )

		// CONSTRUCTOR: Texture( const Surface8u &surface, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( const Surface &in surface, gl::Texture::Format format = gl::Texture::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,const Surface8u &,Texture::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

/*
		// CONSTRUCTOR: Texture( const Surface32f &surface, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( const Surface32f &in surface, gl::Texture::Format format = gl::Texture::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,const Surface32f &,Texture::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/

		// CONSTRUCTOR: Texture( const Channel8u &channel, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( const Channel &in channel, gl::Texture::Format format = gl::Texture::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,const Channel8u &,Texture::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
/*

		// CONSTRUCTOR: Texture( const Channel32f &channel, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( const Channel32f &in channel, gl::Texture::Format format = gl::Texture::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,const Channel32f &,Texture::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: Texture( ImageSourceRef imageSource, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( ImageSourceRef imageSource, gl::Texture::Format format = gl::Texture::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,ImageSourceRef ,Texture::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/

		// CONSTRUCTOR: Texture( GLenum aTarget, GLuint aTextureID, int aWidth, int aHeight, bool aDoNotDispose )
		r = engine->RegisterObjectBehaviour( "Texture", asBEHAVE_CONSTRUCT,
			"void f( uint aTarget, uint fID, int aWidth, int aHeight, bool aDoNotDispose )", asFUNCTION( ( as::RegistrationHelper::constructor<Texture,GLenum ,GLuint ,int ,int ,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// PROPERTY: public:

		// METHOD: void setDoNotDispose( bool aDoNotDispose = true )
		r = engine->RegisterObjectMethod( "Texture", "void setDoNotDispose( bool aDoNotDispose = true )",
			 asMETHODPR(Texture,setDoNotDispose,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void setDeallocator( void(*aDeallocatorFunc)( void * ), void *aDeallocatorRefcon )

		// METHOD: void setWrap( GLenum wrapS, GLenum wrapT )
		r = engine->RegisterObjectMethod( "Texture", "void setWrap( uint wrapS, uint wrapT )",
			 asMETHODPR(Texture,setWrap,(GLenum ,GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: Possible values are \c GL_CLAMP, \c GL_REPEAT and \c GL_CLAMP_TO_EDGE. **/
		// METHOD: void setWrapS( GLenum wrapS )
		r = engine->RegisterObjectMethod( "Texture", "void setWrapS( uint wrapS )",
			 asMETHODPR(Texture,setWrapS,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: Possible values are \c GL_CLAMP, \c GL_REPEAT and \c GL_CLAMP_TO_EDGE. **/
		// METHOD: void setWrapT( GLenum wrapT )
		r = engine->RegisterObjectMethod( "Texture", "void setWrapT( uint wrapT )",
			 asMETHODPR(Texture,setWrapT,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: * Possible values are \li \c GL_NEAREST \li \c GL_LINEAR \li \c GL_NEAREST_MIPMAP_NEAREST \li \c GL_LINEAR_MIPMAP_NEAREST \li \c GL_NEAREST_MIPMAP_LINEAR \li \c GL_LINEAR_MIPMAP_LINEAR **/
		// METHOD: void setMinFilter( GLenum minFilter )
		r = engine->RegisterObjectMethod( "Texture", "void setMinFilter( uint minFilter )",
			 asMETHODPR(Texture,setMinFilter,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: * Possible values are \li \c GL_NEAREST \li \c GL_LINEAR \li \c GL_NEAREST_MIPMAP_NEAREST \li \c GL_LINEAR_MIPMAP_NEAREST \li \c GL_NEAREST_MIPMAP_LINEAR \li \c GL_LINEAR_MIPMAP_LINEAR **/
		// METHOD: void setMagFilter( GLenum magFilter )
		r = engine->RegisterObjectMethod( "Texture", "void setMagFilter( uint magFilter )",
			 asMETHODPR(Texture,setMagFilter,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void setCleanTexCoords( float maxU, float maxV )
		r = engine->RegisterObjectMethod( "Texture", "void setCleanTexCoords( float maxU, float maxV )",
			 asMETHODPR(Texture,setCleanTexCoords,(float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void update( const Surface &surface )
		r = engine->RegisterObjectMethod( "Texture", "void update( const Surface &in surface )",
			 asMETHODPR(Texture,update,(const Surface &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void update( const Surface32f &surface )
		r = engine->RegisterObjectMethod( "Texture", "void update( const Surface32f &in surface )",
			 asMETHODPR(Texture,update,(const Surface32f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: \todo Method for updating a subrectangle with an offset into the source **/
		// METHOD: void update( const Surface &surface, const Area &area )
		r = engine->RegisterObjectMethod( "Texture", "void update( const Surface &in surface, const Area &in area )",
			 asMETHODPR(Texture,update,(const Surface &,const Area &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void update( const Channel32f &channel )
		r = engine->RegisterObjectMethod( "Texture", "void update( const Channel32f &in channel )",
			 asMETHODPR(Texture,update,(const Channel32f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void update( const Channel8u &channel, const Area &area )
		r = engine->RegisterObjectMethod( "Texture", "void update( const Channel &in channel, const Area &in area )",
			 asMETHODPR(Texture,update,(const Channel8u &,const Area &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: GLint getWidth() const
		r = engine->RegisterObjectMethod( "Texture", "int getWidth()",
			 asMETHODPR(Texture,getWidth,()const,GLint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLint getHeight() const
		r = engine->RegisterObjectMethod( "Texture", "int getHeight()",
			 asMETHODPR(Texture,getHeight,()const,GLint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLint getCleanWidth() const
		r = engine->RegisterObjectMethod( "Texture", "int getCleanWidth()",
			 asMETHODPR(Texture,getCleanWidth,()const,GLint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLint getCleanHeight() const
		r = engine->RegisterObjectMethod( "Texture", "int getCleanHeight()",
			 asMETHODPR(Texture,getCleanHeight,()const,GLint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( "Texture", "Vec2i getSize()",
			 asMETHODPR(Texture,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getAspectRatio() const
		r = engine->RegisterObjectMethod( "Texture", "float getAspectRatio()",
			 asMETHODPR(Texture,getAspectRatio,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getBounds() const
		r = engine->RegisterObjectMethod( "Texture", "Area getBounds()",
			 asMETHODPR(Texture,getBounds,()const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getCleanBounds() const
		r = engine->RegisterObjectMethod( "Texture", "Area getCleanBounds()",
			 asMETHODPR(Texture,getCleanBounds,()const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasAlpha() const
		r = engine->RegisterObjectMethod( "Texture", "bool hasAlpha()",
			 asMETHODPR(Texture,hasAlpha,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getLeft() const
		r = engine->RegisterObjectMethod( "Texture", "float getLeft()",
			 asMETHODPR(Texture,getLeft,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getRight() const
		r = engine->RegisterObjectMethod( "Texture", "float getRight()",
			 asMETHODPR(Texture,getRight,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getTop() const
		r = engine->RegisterObjectMethod( "Texture", "float getTop()",
			 asMETHODPR(Texture,getTop,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getBottom() const
		r = engine->RegisterObjectMethod( "Texture", "float getBottom()",
			 asMETHODPR(Texture,getBottom,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getMaxU() const
		r = engine->RegisterObjectMethod( "Texture", "float getMaxU()",
			 asMETHODPR(Texture,getMaxU,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getMaxV() const
		r = engine->RegisterObjectMethod( "Texture", "float getMaxV()",
			 asMETHODPR(Texture,getMaxV,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Rectf getAreaTexCoords( const Area &area ) const
		r = engine->RegisterObjectMethod( "Texture", "Rectf getAreaTexCoords( const Area &in area )",
			 asMETHODPR(Texture,getAreaTexCoords,(const Area &)const,Rectf), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLint getInternalFormat() const
		r = engine->RegisterObjectMethod( "Texture", "int getInternalFormat()",
			 asMETHODPR(Texture,getInternalFormat,()const,GLint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLuint getId() const
		r = engine->RegisterObjectMethod( "Texture", "uint getId()",
			 asMETHODPR(Texture,getId,()const,GLuint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLenum getTarget() const
		r = engine->RegisterObjectMethod( "Texture", "uint getTarget()",
			 asMETHODPR(Texture,getTarget,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isFlipped() const
		r = engine->RegisterObjectMethod( "Texture", "bool isFlipped()",
			 asMETHODPR(Texture,isFlipped,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setFlipped( bool aFlipped = true )
		r = engine->RegisterObjectMethod( "Texture", "void setFlipped( bool aFlipped = true )",
			 asMETHODPR(Texture,setFlipped,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		//  Equivalent to calling \code glEnable( target ); glBindTexture( target, textureID ) \endcode **/
		// METHOD: void enableAndBind() const
		r = engine->RegisterObjectMethod( "Texture", "void enableAndBind()",
			 asMETHODPR(Texture,enableAndBind,()const,void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void disable() const
		r = engine->RegisterObjectMethod( "Texture", "void disable()",
			 asMETHODPR(Texture,disable,()const,void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void bind( GLuint textureUnit = 0 ) const
		r = engine->RegisterObjectMethod( "Texture", "void bind( uint textureUnit = 0 )",
			 asMETHODPR(Texture,bind,(GLuint )const,void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void unbind( GLuint textureUnit = 0 ) const
		r = engine->RegisterObjectMethod( "Texture", "void unbind( uint textureUnit = 0 )",
			 asMETHODPR(Texture,unbind,(GLuint )const,void), asCALL_THISCALL ); assert( r >= 0 );



		// STATIC METHOD: Texture loadDds( IStreamRef ddsStream, Format format )
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Texture" : "gl::Texture" ); assert( r >= 0 );
/*
		r = engine->RegisterGlobalFunction( "Texture loadDds( IStreamRef ddsStream, Format format )",
			 asFUNCTIONPR(Texture::loadDds,(IStreamRef ,Texture::Format ),Texture), asCALL_CDECL ); assert( r >= 0 );


*/
		//  static void SurfaceChannelOrderToDataFormatAndType( const SurfaceChannelOrder &sco, GLint *dataFormat, GLenum *type )

		// STATIC METHOD: bool dataFormatHasAlpha( GLint dataFormat )
		r = engine->RegisterGlobalFunction( "bool dataFormatHasAlpha( int dataFormat )",
			 asFUNCTIONPR(Texture::dataFormatHasAlpha,(GLint ),bool), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: bool dataFormatHasColor( GLint dataFormat )
		r = engine->RegisterGlobalFunction( "bool dataFormatHasColor( int dataFormat )",
			 asFUNCTIONPR(Texture::dataFormatHasColor,(GLint ),bool), asCALL_CDECL ); assert( r >= 0 );



		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: Texture weakClone() const
		r = engine->RegisterObjectMethod( "Texture", "Texture weakClone()",
			 asMETHODPR(Texture,weakClone,()const,Texture), asCALL_THISCALL ); assert( r >= 0 );


		//  #if ! defined( CINDER_GLES )

		//  #endif

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );


	}
}
