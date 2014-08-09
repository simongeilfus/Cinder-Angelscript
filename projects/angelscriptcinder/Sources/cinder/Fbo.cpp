#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/gl/Fbo.h"


using namespace std;
using namespace ci;
using namespace ci::gl;

namespace as {

	void registerCinderRenderbufferType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "Renderbuffer", sizeof(Renderbuffer), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderRenderbufferImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Renderbuffer", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Renderbuffer>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Renderbuffer", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Renderbuffer>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Renderbuffer", asBEHAVE_CONSTRUCT,
			"void f(const Renderbuffer &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Renderbuffer,const Renderbuffer &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Renderbuffer","Renderbuffer& opAssign(const Renderbuffer &in)", asFUNCTION((as::RegistrationHelper::opAssign<Renderbuffer&,Renderbuffer,Renderbuffer&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		//  #if defined( CINDER_GLES )
		// CONSTRUCTOR: Renderbuffer( int width, int height, GLenum internalFormat = GL_RGBA8_OES )
		r = engine->RegisterObjectBehaviour( "Renderbuffer", asBEHAVE_CONSTRUCT,
			"void f( int width, int height, uint internalFormat = GL_RGBA8_OES )", asFUNCTION( ( as::RegistrationHelper::constructor<Renderbuffer,int ,int ,GLenum > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  #else
		// CONSTRUCTOR: Renderbuffer( int width, int height, GLenum internalFormat = GL_RGBA8 )
		r = engine->RegisterObjectBehaviour( "Renderbuffer", asBEHAVE_CONSTRUCT,
			"void f( int width, int height, uint internalFormat = GL_RGBA8 )", asFUNCTION( ( as::RegistrationHelper::constructor<Renderbuffer,int ,int ,GLenum > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  #endif

		// CONSTRUCTOR: Renderbuffer( int width, int height, GLenum internalFormat, int msaaSamples, int coverageSamples = 0 )
		r = engine->RegisterObjectBehaviour( "Renderbuffer", asBEHAVE_CONSTRUCT,
			"void f( int width, int height, uint internalFormat, int msaaSamples, int coverageSamples = 0 )", asFUNCTION( ( as::RegistrationHelper::constructor<Renderbuffer,int ,int ,GLenum ,int ,int > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: int getWidth() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "int getWidth()",
			 asMETHODPR(Renderbuffer,getWidth,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getHeight() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "int getHeight()",
			 asMETHODPR(Renderbuffer,getHeight,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "Vec2i getSize()",
			 asMETHODPR(Renderbuffer,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getBounds() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "Area getBounds()",
			 asMETHODPR(Renderbuffer,getBounds,()const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getAspectRatio() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "float getAspectRatio()",
			 asMETHODPR(Renderbuffer,getAspectRatio,()const,float), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: GLuint getId() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "uint getId()",
			 asMETHODPR(Renderbuffer,getId,()const,GLuint), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLenum getInternalFormat() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "uint getInternalFormat()",
			 asMETHODPR(Renderbuffer,getInternalFormat,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getSamples() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "int getSamples()",
			 asMETHODPR(Renderbuffer,getSamples,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getCoverageSamples() const
		r = engine->RegisterObjectMethod( "Renderbuffer", "int getCoverageSamples()",
			 asMETHODPR(Renderbuffer,getCoverageSamples,()const,int), asCALL_THISCALL ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );


	}
	void registerCinderFboFormatType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl::Fbo"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "Format", sizeof(Fbo::Format), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderFboFormatImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl::Fbo"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Format", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Fbo::Format>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Format", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Fbo::Format>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Format", asBEHAVE_CONSTRUCT,
			"void f(const Format &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Fbo::Format,const Fbo::Format &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Format","Format& opAssign(const Format &in)", asFUNCTION((as::RegistrationHelper::opAssign<Fbo::Format&,Fbo::Format,Fbo::Format&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: public:



		// METHOD: void setTarget( GLenum target )
		r = engine->RegisterObjectMethod( "Format", "void setTarget( uint target )",
			 asMETHODPR(Fbo::Format,setTarget,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setColorInternalFormat( GLenum colorInternalFormat )
		r = engine->RegisterObjectMethod( "Format", "void setColorInternalFormat( uint colorInternalFormat )",
			 asMETHODPR(Fbo::Format,setColorInternalFormat,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setDepthInternalFormat( GLenum depthInternalFormat )
		r = engine->RegisterObjectMethod( "Format", "void setDepthInternalFormat( uint depthInternalFormat )",
			 asMETHODPR(Fbo::Format,setDepthInternalFormat,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setSamples( int samples )
		r = engine->RegisterObjectMethod( "Format", "void setSamples( int samples )",
			 asMETHODPR(Fbo::Format,setSamples,(int ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setCoverageSamples( int coverageSamples )
		r = engine->RegisterObjectMethod( "Format", "void setCoverageSamples( int coverageSamples )",
			 asMETHODPR(Fbo::Format,setCoverageSamples,(int ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void enableColorBuffer( bool colorBuffer = true, int numColorBuffers = 1 )
		r = engine->RegisterObjectMethod( "Format", "void enableColorBuffer( bool colorBuffer = true, int numColorBuffers = 1 )",
			 asMETHODPR(Fbo::Format,enableColorBuffer,(bool ,int ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void enableDepthBuffer( bool depthBuffer = true, bool asTexture = true )
		r = engine->RegisterObjectMethod( "Format", "void enableDepthBuffer( bool depthBuffer = true, bool asTexture = true )",
			 asMETHODPR(Fbo::Format,enableDepthBuffer,(bool ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void enableMipmapping( bool enableMipmapping = true )
		r = engine->RegisterObjectMethod( "Format", "void enableMipmapping( bool enableMipmapping = true )",
			 asMETHODPR(Fbo::Format,enableMipmapping,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void setWrap( GLenum wrapS, GLenum wrapT )
		r = engine->RegisterObjectMethod( "Format", "void setWrap( uint wrapS, uint wrapT )",
			 asMETHODPR(Fbo::Format,setWrap,(GLenum ,GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: Possible values are \c GL_CLAMP, \c GL_REPEAT and \c GL_CLAMP_TO_EDGE. **/
		// METHOD: void setWrapS( GLenum wrapS )
		r = engine->RegisterObjectMethod( "Format", "void setWrapS( uint wrapS )",
			 asMETHODPR(Fbo::Format,setWrapS,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: Possible values are \c GL_CLAMP, \c GL_REPEAT and \c GL_CLAMP_TO_EDGE. **/
		// METHOD: void setWrapT( GLenum wrapT )
		r = engine->RegisterObjectMethod( "Format", "void setWrapT( uint wrapT )",
			 asMETHODPR(Fbo::Format,setWrapT,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: * Possible values are \li \c GL_NEAREST \li \c GL_LINEAR \li \c GL_NEAREST_MIPMAP_NEAREST \li \c GL_LINEAR_MIPMAP_NEAREST \li \c GL_NEAREST_MIPMAP_LINEAR \li \c GL_LINEAR_MIPMAP_LINEAR **/
		// METHOD: void setMinFilter( GLenum minFilter )
		r = engine->RegisterObjectMethod( "Format", "void setMinFilter( uint minFilter )",
			 asMETHODPR(Fbo::Format,setMinFilter,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: * Possible values are \li \c GL_NEAREST \li \c GL_LINEAR \li \c GL_NEAREST_MIPMAP_NEAREST \li \c GL_LINEAR_MIPMAP_NEAREST \li \c GL_NEAREST_MIPMAP_LINEAR \li \c GL_LINEAR_MIPMAP_LINEAR **/
		// METHOD: void setMagFilter( GLenum magFilter )
		r = engine->RegisterObjectMethod( "Format", "void setMagFilter( uint magFilter )",
			 asMETHODPR(Fbo::Format,setMagFilter,(GLenum ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: GLenum getTarget() const
		r = engine->RegisterObjectMethod( "Format", "uint getTarget()",
			 asMETHODPR(Fbo::Format,getTarget,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLenum getColorInternalFormat() const
		r = engine->RegisterObjectMethod( "Format", "uint getColorInternalFormat()",
			 asMETHODPR(Fbo::Format,getColorInternalFormat,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLenum getDepthInternalFormat() const
		r = engine->RegisterObjectMethod( "Format", "uint getDepthInternalFormat()",
			 asMETHODPR(Fbo::Format,getDepthInternalFormat,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getSamples() const
		r = engine->RegisterObjectMethod( "Format", "int getSamples()",
			 asMETHODPR(Fbo::Format,getSamples,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getCoverageSamples() const
		r = engine->RegisterObjectMethod( "Format", "int getCoverageSamples()",
			 asMETHODPR(Fbo::Format,getCoverageSamples,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasColorBuffer() const
		r = engine->RegisterObjectMethod( "Format", "bool hasColorBuffer()",
			 asMETHODPR(Fbo::Format,hasColorBuffer,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getNumColorBuffers() const
		r = engine->RegisterObjectMethod( "Format", "int getNumColorBuffers()",
			 asMETHODPR(Fbo::Format,getNumColorBuffers,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasDepthBuffer() const
		r = engine->RegisterObjectMethod( "Format", "bool hasDepthBuffer()",
			 asMETHODPR(Fbo::Format,hasDepthBuffer,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasDepthBufferTexture() const
		r = engine->RegisterObjectMethod( "Format", "bool hasDepthBufferTexture()",
			 asMETHODPR(Fbo::Format,hasDepthBufferTexture,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool hasMipMapping() const
		r = engine->RegisterObjectMethod( "Format", "bool hasMipMapping()",
			 asMETHODPR(Fbo::Format,hasMipMapping,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
	}
	void registerCinderFboType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Fbo", sizeof(Fbo), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderFboImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Fbo", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Fbo>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Fbo", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Fbo>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Fbo", asBEHAVE_CONSTRUCT,
			"void f(const Fbo &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Fbo,const Fbo &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Fbo","Fbo& opAssign(const Fbo &in)", asFUNCTION((as::RegistrationHelper::opAssign<Fbo&,Fbo,Fbo&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );




		// CONSTRUCTOR: Fbo( int width, int height, Format format = Format() )
		r = engine->RegisterObjectBehaviour( "Fbo", asBEHAVE_CONSTRUCT,
                                            "void f( int width, int height, gl::Fbo::Format format = gl::Fbo::Format() )", asFUNCTION( ( as::RegistrationHelper::constructor<Fbo,int ,int ,Fbo::Format > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// CONSTRUCTOR: Fbo( int width, int height, bool alpha, bool color = true, bool depth = true )
		r = engine->RegisterObjectBehaviour( "Fbo", asBEHAVE_CONSTRUCT,
			"void f( int width, int height, bool alpha, bool color = true, bool depth = true )", asFUNCTION( ( as::RegistrationHelper::constructor<Fbo,int ,int ,bool ,bool ,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );



		// METHOD: int getWidth() const
		r = engine->RegisterObjectMethod( "Fbo", "int getWidth()",
			 asMETHODPR(Fbo,getWidth,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: int getHeight() const
		r = engine->RegisterObjectMethod( "Fbo", "int getHeight()",
			 asMETHODPR(Fbo,getHeight,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( "Fbo", "Vec2i getSize()",
			 asMETHODPR(Fbo,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Area getBounds() const
		r = engine->RegisterObjectMethod( "Fbo", "Area getBounds()",
			 asMETHODPR(Fbo,getBounds,()const,Area), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getAspectRatio() const
		r = engine->RegisterObjectMethod( "Fbo", "float getAspectRatio()",
			 asMETHODPR(Fbo,getAspectRatio,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: const Format& getFormat() const
		r = engine->RegisterObjectMethod( "Fbo", "const gl::Fbo::Format& getFormat()",
                                         asMETHODPR(Fbo,getFormat,()const,const Fbo::Format&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLenum getTarget() const
		r = engine->RegisterObjectMethod( "Fbo", "uint getTarget()",
			 asMETHODPR(Fbo,getTarget,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Texture& getTexture( int attachment = 0 )
		r = engine->RegisterObjectMethod( "Fbo", "Texture& getTexture( int attachment = 0 )",
			 asMETHODPR(Fbo,getTexture,(int ),Texture&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Texture& getDepthTexture()
		r = engine->RegisterObjectMethod( "Fbo", "Texture& getDepthTexture()",
			 asMETHODPR(Fbo,getDepthTexture,(),Texture&), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void bindTexture( int textureUnit = 0, int attachment = 0 )
		r = engine->RegisterObjectMethod( "Fbo", "void bindTexture( int textureUnit = 0, int attachment = 0 )",
			 asMETHODPR(Fbo,bindTexture,(int ,int ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void unbindTexture()
		r = engine->RegisterObjectMethod( "Fbo", "void unbindTexture()",
			 asMETHODPR(Fbo,unbindTexture,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void bindDepthTexture( int textureUnit = 0 )
		r = engine->RegisterObjectMethod( "Fbo", "void bindDepthTexture( int textureUnit = 0 )",
			 asMETHODPR(Fbo,bindDepthTexture,(int ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void bindFramebuffer()
		r = engine->RegisterObjectMethod( "Fbo", "void bindFramebuffer()",
			 asMETHODPR(Fbo,bindFramebuffer,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// STATIC METHOD: void unbindFramebuffer()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Fbo" : "gl::Fbo" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "void unbindFramebuffer()",
			 asFUNCTIONPR(Fbo::unbindFramebuffer,(),void), asCALL_CDECL ); assert( r >= 0 );



		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: GLuint getId() const
		r = engine->RegisterObjectMethod( "Fbo", "uint getId()",
			 asMETHODPR(Fbo,getId,()const,GLuint), asCALL_THISCALL ); assert( r >= 0 );


		//  #if ! defined( CINDER_GLES )

		// METHOD: GLuint getResolveId() const
		r = engine->RegisterObjectMethod( "Fbo", "uint getResolveId()",
			 asMETHODPR(Fbo,getResolveId,()const,GLuint), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void blitTo( Fbo dst, const Area &srcArea, const Area &dstArea, GLenum filter = GL_NEAREST, GLbitfield mask = GL_COLOR_BUFFER_BIT ) const
		r = engine->RegisterObjectMethod( "Fbo", "void blitTo( Fbo dst, const Area &in srcArea, const Area &in dstArea, uint filter, uint mask )",
			 asMETHODPR(Fbo,blitTo,(Fbo ,const Area &,const Area &,GLenum ,GLbitfield )const,void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void blitToScreen( const Area &srcArea, const Area &dstArea, GLenum filter = GL_NEAREST, GLbitfield mask = GL_COLOR_BUFFER_BIT ) const
		r = engine->RegisterObjectMethod( "Fbo", "void blitToScreen( const Area &in srcArea, const Area &in dstArea, uint filter, uint mask )",
			 asMETHODPR(Fbo,blitToScreen,(const Area &,const Area &,GLenum ,GLbitfield )const,void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void blitFromScreen( const Area &srcArea, const Area &dstArea, GLenum filter = GL_NEAREST, GLbitfield mask = GL_COLOR_BUFFER_BIT )
		r = engine->RegisterObjectMethod( "Fbo", "void blitFromScreen( const Area &in srcArea, const Area &in dstArea, uint filter, uint mask )",
			 asMETHODPR(Fbo,blitFromScreen,(const Area &,const Area &,GLenum ,GLbitfield ),void), asCALL_THISCALL ); assert( r >= 0 );

		//  #endif


		// STATIC METHOD: GLint getMaxSamples()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Fbo" : "gl::Fbo" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "int getMaxSamples()",
			 asFUNCTIONPR(Fbo::getMaxSamples,(),GLint), asCALL_CDECL ); assert( r >= 0 );


		// STATIC METHOD: GLint getMaxAttachments()
		r = engine->RegisterGlobalFunction( "int getMaxAttachments()",
			 asFUNCTIONPR(Fbo::getMaxAttachments,(),GLint), asCALL_CDECL ); assert( r >= 0 );





		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
