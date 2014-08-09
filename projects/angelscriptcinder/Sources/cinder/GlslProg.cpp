#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/gl/GlslProg.h"


using namespace std;
using namespace ci;
using namespace ci::gl;

namespace as {

	void registerCinderGlslProgType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "GlslProg", sizeof(GlslProg), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderGlslProgImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "GlslProg", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<GlslProg>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "GlslProg", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<GlslProg>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "GlslProg", asBEHAVE_CONSTRUCT,
			"void f(const GlslProg &in )", asFUNCTION( ( as::RegistrationHelper::constructor<GlslProg,const GlslProg &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "GlslProg","GlslProg& opAssign(const GlslProg &in)", asFUNCTION((as::RegistrationHelper::opAssign<GlslProg&,GlslProg,GlslProg&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: GlslProg( DataSourceRef vertexShader, DataSourceRef fragmentShader = DataSourceRef(), DataSourceRef geometryShader = DataSourceRef(),
	/*	r = engine->RegisterObjectBehaviour( "GlslProg", asBEHAVE_CONSTRUCT,
			"void f( DataSourceRef vertexShader, DataSourceRef fragmentShader = DataSourceRef()", asFUNCTION( ( as::RegistrationHelper::constructor<GlslProg,DataSourceRef ,DataSourceRef > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/
		//  GLint geometryInputType = GL_POINTS, GLint geometryOutputType = GL_TRIANGLES, GLint geometryOutputVertices = 0 )

		//  GlslProg( const char *vertexShader, const char *fragmentShader = 0, const char *geometryShader = 0, GLint geometryInputType = GL_POINTS, GLint geometryOutputType = GL_TRIANGLES, GLint geometryOutputVertices = 0 )


		// METHOD: void bind() const
		r = engine->RegisterObjectMethod( "GlslProg", "void bind()",
			 asMETHODPR(GlslProg,bind,()const,void), asCALL_THISCALL ); assert( r >= 0 );

		// STATIC METHOD: void unbind()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::GlslProg" : "gl::GlslProg" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "void unbind()",
			 asFUNCTIONPR(GlslProg::unbind,(),void), asCALL_CDECL ); assert( r >= 0 );


		r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// METHOD: GLuint getHandle() const
		r = engine->RegisterObjectMethod( "GlslProg", "uint getHandle()",
			 asMETHODPR(GlslProg,getHandle,()const,GLuint), asCALL_THISCALL ); assert( r >= 0 );


		//  void uniform( const std::string &name, int data )
		//  void uniform( const std::string &name, const Vec2i &data )
		//  void uniform( const std::string &name, const int *data, int count )
		//  void uniform( const std::string &name, const Vec2i *data, int count )
		//  void uniform( const std::string &name, float data )
		//  void uniform( const std::string &name, const Vec2f &data )
		//  void uniform( const std::string &name, const Vec3f &data )
		//  void uniform( const std::string &name, const Vec4f &data )
		//  void uniform( const std::string &name, const Color &data )
		//  void uniform( const std::string &name, const ColorA &data )
		//  void uniform( const std::string &name, const Matrix22f &data, bool transpose = false )
		//  void uniform( const std::string &name, const Matrix33f &data, bool transpose = false )
		//  void uniform( const std::string &name, const Matrix44f &data, bool transpose = false )
		//  void uniform( const std::string &name, const float *data, int count )
		//  void uniform( const std::string &name, const Vec2f *data, int count )
		//  void uniform( const std::string &name, const Vec3f *data, int count )
		//  void uniform( const std::string &name, const Vec4f *data, int count )
		//  void uniform( const std::string &name, const Matrix22f *data, int count, bool transpose = false )
		//  void uniform( const std::string &name, const Matrix33f *data, int count, bool transpose = false )
		//  void uniform( const std::string &name, const Matrix44f *data, int count, bool transpose = false )

		//  GLint getUniformLocation( const std::string &name )
		//  GLint getAttribLocation( const std::string &name )

		//  std::string getShaderLog( GLuint handle ) const

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
