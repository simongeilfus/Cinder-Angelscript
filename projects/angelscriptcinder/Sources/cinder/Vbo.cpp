#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/gl/Vbo.h"


using namespace std;
using namespace ci;
using namespace ci::gl;

namespace as {

	void registerCinderVboType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "Vbo", sizeof(Vbo), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderVboImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Vbo", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Vbo>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Vbo", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Vbo>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Vbo", asBEHAVE_CONSTRUCT,
			"void f(const Vbo &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Vbo,const Vbo &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Vbo","Vbo& opAssign(const Vbo &in)", asFUNCTION((as::RegistrationHelper::opAssign<Vbo&,Vbo,Vbo&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: Vbo( GLenum aTarget )
		r = engine->RegisterObjectBehaviour( "Vbo", asBEHAVE_CONSTRUCT,
			"void f( uint aTarget )", asFUNCTION( ( as::RegistrationHelper::constructor<Vbo,GLenum > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void bind()
		r = engine->RegisterObjectMethod( "Vbo", "void bind()",
			 asMETHODPR(Vbo,bind,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void unbind()
		r = engine->RegisterObjectMethod( "Vbo", "void unbind()",
			 asMETHODPR(Vbo,unbind,(),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void bufferData( size_t size, const void *data, GLenum usage )
		//  void bufferSubData( ptrdiff_t offset, size_t size, const void *data )

		//  uint8_t* map( GLenum access )
		// METHOD: void unmap()
		r = engine->RegisterObjectMethod( "Vbo", "void unmap()",
			 asMETHODPR(Vbo,unmap,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: GLenum getTarget() const
		r = engine->RegisterObjectMethod( "Vbo", "uint getTarget()",
			 asMETHODPR(Vbo,getTarget,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: GLuint getId() const
		r = engine->RegisterObjectMethod( "Vbo", "uint getId()",
			 asMETHODPR(Vbo,getId,()const,GLuint), asCALL_THISCALL ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );


	}
	void registerCinderVboMeshLayoutType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl::VboMesh"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "Layout", sizeof(	VboMesh::Layout), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderVboMeshLayoutImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl::VboMesh"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Layout", asBEHAVE_CONSTRUCT,
                                            "void f()", asFUNCTION( as::RegistrationHelper::constructor<	VboMesh::Layout>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Layout", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<	VboMesh::Layout>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Layout", asBEHAVE_CONSTRUCT,
			"void f(const 	Layout &in )", asFUNCTION( ( as::RegistrationHelper::constructor<	VboMesh::Layout,const 	VboMesh::Layout &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Layout","	Layout& opAssign(const 	Layout &in)", asFUNCTION((as::RegistrationHelper::opAssign<	VboMesh::Layout&,	VboMesh::Layout,	VboMesh::Layout&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: bool isDefaults() const
		r = engine->RegisterObjectMethod( "Layout", "bool isDefaults()",
			 asMETHODPR(	VboMesh::Layout,isDefaults,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasNormals() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasNormals()",
			 asMETHODPR(	VboMesh::Layout,hasNormals,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticNormals() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticNormals()",
			 asMETHODPR(	VboMesh::Layout,hasStaticNormals,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicNormals() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicNormals()",
			 asMETHODPR(	VboMesh::Layout,hasDynamicNormals,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticNormals()
		r = engine->RegisterObjectMethod( "Layout", "void setStaticNormals()",
			 asMETHODPR(	VboMesh::Layout,setStaticNormals,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicNormals()
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicNormals()",
			 asMETHODPR(	VboMesh::Layout,setDynamicNormals,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasColorsRGB() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasColorsRGB()",
			 asMETHODPR(	VboMesh::Layout,hasColorsRGB,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticColorsRGB() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticColorsRGB()",
			 asMETHODPR(	VboMesh::Layout,hasStaticColorsRGB,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicColorsRGB() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicColorsRGB()",
			 asMETHODPR(	VboMesh::Layout,hasDynamicColorsRGB,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticColorsRGB()
		r = engine->RegisterObjectMethod( "Layout", "void setStaticColorsRGB()",
			 asMETHODPR(	VboMesh::Layout,setStaticColorsRGB,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicColorsRGB()
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicColorsRGB()",
			 asMETHODPR(	VboMesh::Layout,setDynamicColorsRGB,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasColorsRGBA() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasColorsRGBA()",
			 asMETHODPR(	VboMesh::Layout,hasColorsRGBA,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticColorsRGBA() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticColorsRGBA()",
			 asMETHODPR(	VboMesh::Layout,hasStaticColorsRGBA,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicColorsRGBA() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicColorsRGBA()",
			 asMETHODPR(	VboMesh::Layout,hasDynamicColorsRGBA,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticColorsRGBA()
		r = engine->RegisterObjectMethod( "Layout", "void setStaticColorsRGBA()",
			 asMETHODPR(	VboMesh::Layout,setStaticColorsRGBA,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicColorsRGBA()
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicColorsRGBA()",
			 asMETHODPR(	VboMesh::Layout,setDynamicColorsRGBA,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasTexCoords2d( size_t unit = 0 ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasTexCoords2d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,hasTexCoords2d,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticTexCoords2d( size_t unit = 0 ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticTexCoords2d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,hasStaticTexCoords2d,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicTexCoords2d( size_t unit = 0 ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicTexCoords2d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,hasDynamicTexCoords2d,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticTexCoords2d( size_t unit = 0 )
		r = engine->RegisterObjectMethod( "Layout", "void setStaticTexCoords2d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,setStaticTexCoords2d,(size_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicTexCoords2d( size_t unit = 0 )
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicTexCoords2d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,setDynamicTexCoords2d,(size_t ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasStaticTexCoords() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticTexCoords()",
			 asMETHODPR(	VboMesh::Layout,hasStaticTexCoords,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasDynamicTexCoords() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicTexCoords()",
			 asMETHODPR(	VboMesh::Layout,hasDynamicTexCoords,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasTexCoords( size_t unit ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasTexCoords( uint unit )",
			 asMETHODPR(	VboMesh::Layout,hasTexCoords,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasTexCoords3d( size_t unit = 0 ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasTexCoords3d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,hasTexCoords3d,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticTexCoords3d( size_t unit = 0 ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticTexCoords3d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,hasStaticTexCoords3d,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicTexCoords3d( size_t unit = 0 ) const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicTexCoords3d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,hasDynamicTexCoords3d,(size_t )const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticTexCoords3d( size_t unit = 0 )
		r = engine->RegisterObjectMethod( "Layout", "void setStaticTexCoords3d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,setStaticTexCoords3d,(size_t ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicTexCoords3d( size_t unit = 0 )
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicTexCoords3d( uint unit = 0 )",
			 asMETHODPR(	VboMesh::Layout,setDynamicTexCoords3d,(size_t ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasIndices() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasIndices()",
			 asMETHODPR(	VboMesh::Layout,hasIndices,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticIndices() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticIndices()",
			 asMETHODPR(	VboMesh::Layout,hasStaticIndices,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicIndices() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicIndices()",
			 asMETHODPR(	VboMesh::Layout,hasDynamicIndices,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticIndices()
		r = engine->RegisterObjectMethod( "Layout", "void setStaticIndices()",
			 asMETHODPR(	VboMesh::Layout,setStaticIndices,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicIndices()
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicIndices()",
			 asMETHODPR(	VboMesh::Layout,setDynamicIndices,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasPositions() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasPositions()",
			 asMETHODPR(	VboMesh::Layout,hasPositions,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasStaticPositions() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasStaticPositions()",
			 asMETHODPR(	VboMesh::Layout,hasStaticPositions,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasDynamicPositions() const
		r = engine->RegisterObjectMethod( "Layout", "bool hasDynamicPositions()",
			 asMETHODPR(	VboMesh::Layout,hasDynamicPositions,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setStaticPositions()
		r = engine->RegisterObjectMethod( "Layout", "void setStaticPositions()",
			 asMETHODPR(	VboMesh::Layout,setStaticPositions,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setDynamicPositions()
		r = engine->RegisterObjectMethod( "Layout", "void setDynamicPositions()",
			 asMETHODPR(	VboMesh::Layout,setDynamicPositions,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// PROPERTY: enum CustomAttr
		// PROPERTY: static int sCustomAttrSizes[TOTAL_CUSTOM_ATTR_TYPES]
		// PROPERTY: static GLint sCustomAttrNumComponents[TOTAL_CUSTOM_ATTR_TYPES]
		// PROPERTY: static GLenum sCustomAttrTypes[TOTAL_CUSTOM_ATTR_TYPES]
		// METHOD: void addDynamicCustomFloat()
		r = engine->RegisterObjectMethod( "Layout", "void addDynamicCustomFloat()",
			 asMETHODPR(	VboMesh::Layout,addDynamicCustomFloat,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void addDynamicCustomVec2f()
		r = engine->RegisterObjectMethod( "Layout", "void addDynamicCustomVec2f()",
			 asMETHODPR(	VboMesh::Layout,addDynamicCustomVec2f,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void addDynamicCustomVec3f()
		r = engine->RegisterObjectMethod( "Layout", "void addDynamicCustomVec3f()",
			 asMETHODPR(	VboMesh::Layout,addDynamicCustomVec3f,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void addDynamicCustomVec4f()
		r = engine->RegisterObjectMethod( "Layout", "void addDynamicCustomVec4f()",
			 asMETHODPR(	VboMesh::Layout,addDynamicCustomVec4f,(),void), asCALL_THISCALL ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );


	}
	void registerCinderVboMeshVertexIterType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "VertexIter", sizeof(	VboMesh::VertexIter), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	/*void registerCinderVboMeshVertexIterImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "VertexIter", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<	VboMesh::VertexIter>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "VertexIter", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<	VboMesh::VertexIter>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "VertexIter", asBEHAVE_CONSTRUCT,
			"void f(const 	VertexIter &in )", asFUNCTION( ( as::RegistrationHelper::constructor<	VboMesh::VertexIter,const 	VboMesh::VertexIter &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "VertexIter","VertexIter& opAssign(const 	VertexIter &in)", asFUNCTION((as::RegistrationHelper::opAssign<	VboMesh::VertexIter&,	VboMesh::VertexIter,	VboMesh::VertexIter&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// METHOD: VertexIter( const VboMesh &mesh )
		//r = engine->RegisterObjectMethod( "VertexIter", "VertexIter( const VboMesh &in mesh )",
		//	 asMETHODPR(	VboMesh::VertexIter,VboMesh::VertexIter,(const VboMesh &),VboMesh::VertexIter( const VboMesh &mesh )), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setPosition( const Vec3f &v )
		r = engine->RegisterObjectMethod( "VertexIter", "void setPosition( const Vec3f &in v )",
			 asMETHODPR(	VboMesh::VertexIter,setPosition,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setPosition( float x, float y, float z )
		r = engine->RegisterObjectMethod( "VertexIter", "void setPosition( float x, float y, float z )",
			 asMETHODPR(	VboMesh::VertexIter,setPosition,(float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setNormal( const Vec3f &n )
		r = engine->RegisterObjectMethod( "VertexIter", "void setNormal( const Vec3f &in n )",
			 asMETHODPR(	VboMesh::VertexIter,setNormal,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColorRGB( const Color &n )
		r = engine->RegisterObjectMethod( "VertexIter", "void setColorRGB( const Color &in n )",
			 asMETHODPR(	VboMesh::VertexIter,setColorRGB,(const Color &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColorRGBA( const ColorA &n )
		r = engine->RegisterObjectMethod( "VertexIter", "void setColorRGBA( const ColorA &in n )",
			 asMETHODPR(	VboMesh::VertexIter,setColorRGBA,(const ColorA &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoord2d0( const Vec2f &t )
		r = engine->RegisterObjectMethod( "VertexIter", "void setTexCoord2d0( const Vec2f &in t )",
			 asMETHODPR(	VboMesh::VertexIter,setTexCoord2d0,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoord3d0( const Vec3f &t )
		r = engine->RegisterObjectMethod( "VertexIter", "void setTexCoord3d0( const Vec3f &in t )",
			 asMETHODPR(	VboMesh::VertexIter,setTexCoord3d0,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoord2d1( const Vec2f &t )
		r = engine->RegisterObjectMethod( "VertexIter", "void setTexCoord2d1( const Vec2f &in t )",
			 asMETHODPR(	VboMesh::VertexIter,setTexCoord2d1,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoord3d1( const Vec3f &t )
		r = engine->RegisterObjectMethod( "VertexIter", "void setTexCoord3d1( const Vec3f &in t )",
			 asMETHODPR(	VboMesh::VertexIter,setTexCoord3d1,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoord2d2( const Vec2f &t )
		r = engine->RegisterObjectMethod( "VertexIter", "void setTexCoord2d2( const Vec2f &in t )",
			 asMETHODPR(	VboMesh::VertexIter,setTexCoord2d2,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoord3d2( const Vec3f &t )
		r = engine->RegisterObjectMethod( "VertexIter", "void setTexCoord3d2( const Vec3f &in t )",
			 asMETHODPR(	VboMesh::VertexIter,setTexCoord3d2,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCustomFloat( size_t index, float v )
		r = engine->RegisterObjectMethod( "VertexIter", "void setCustomFloat( uint index, float v )",
			 asMETHODPR(	VboMesh::VertexIter,setCustomFloat,(size_t ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCustomVec2f( size_t index, const Vec2f &v )
		r = engine->RegisterObjectMethod( "VertexIter", "void setCustomVec2f( uint index, const Vec2f &in v )",
			 asMETHODPR(	VboMesh::VertexIter,setCustomVec2f,(size_t ,const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCustomVec3f( size_t index, const Vec3f &v )
		r = engine->RegisterObjectMethod( "VertexIter", "void setCustomVec3f( uint index, const Vec3f &in v )",
			 asMETHODPR(	VboMesh::VertexIter,setCustomVec3f,(size_t ,const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCustomVec4f( size_t index, const Vec4f &v )
		r = engine->RegisterObjectMethod( "VertexIter", "void setCustomVec4f( uint index, const Vec4f &in v )",
			 asMETHODPR(	VboMesh::VertexIter,setCustomVec4f,(size_t ,const Vec4f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool isDone() const
		r = engine->RegisterObjectMethod( "VertexIter", "bool isDone()",
			 asMETHODPR(	VboMesh::VertexIter,isDone,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: size_t getIndex() const
		r = engine->RegisterObjectMethod( "VertexIter", "uint getIndex()",
			 asMETHODPR(	VboMesh::VertexIter,getIndex,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: size_t getStride() const
		r = engine->RegisterObjectMethod( "VertexIter", "uint getStride()",
			 asMETHODPR(	VboMesh::VertexIter,getStride,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		//  void* getPointer() const

		//  Vec3f* getPositionPointer() const






		// PROPERTY: std::shared_ptr<Obj> mObj
		// PROPERTY: uint8_t *mPtr
		// PROPERTY: uint8_t *mData, *mDataEnd // we cache these from the Obj to reduce dereferencing
		// PROPERTY: size_t mPositionOffset, mNormalOffset
		// PROPERTY: size_t mColorRGBOffset, mColorRGBAOffset
		// PROPERTY: size_t mTexCoordOffset[ATTR_MAX_TEXTURE_UNIT+1]
		// PROPERTY: uint8_t mStride
	}*/
	void registerCinderVboMeshType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "VboMesh", sizeof(VboMesh), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );

        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderVboMeshImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "VboMesh", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<VboMesh>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "VboMesh", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<VboMesh>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "VboMesh", asBEHAVE_CONSTRUCT,
			"void f(const VboMesh &in )", asFUNCTION( ( as::RegistrationHelper::constructor<VboMesh,const VboMesh &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "VboMesh","VboMesh& opAssign(const VboMesh &in)", asFUNCTION((as::RegistrationHelper::opAssign<VboMesh&,VboMesh,VboMesh&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: public:
		// PROPERTY: enum
		// PROPERTY: enum
		// PROPERTY: enum

		// PROPERTY: public:
		// PROPERTY: class VertexIter

		//  explicit VboMesh( const TriMesh &triMesh, Layout layout = Layout() )
		//  explicit VboMesh( const TriMesh2d &triMesh, Layout layout = Layout() )

		// CONSTRUCTOR: VboMesh( size_t numVertices, size_t numIndices, Layout layout, GLenum primitiveType )
		r = engine->RegisterObjectBehaviour( "VboMesh", asBEHAVE_CONSTRUCT,
			"void f( uint numVertices, uint numIndices, gl::VboMesh::Layout layout, uint primitiveType )", asFUNCTION( ( as::RegistrationHelper::constructor<VboMesh,size_t ,size_t ,VboMesh::Layout ,GLenum > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		//  VboMesh( size_t numVertices, size_t numIndices, Layout layout, GLenum primitiveType, Vbo *indexBuffer, Vbo *staticBuffer, Vbo *dynamicBuffer )

		// METHOD: size_t getNumIndices() const
		r = engine->RegisterObjectMethod( "VboMesh", "uint getNumIndices()",
			 asMETHODPR(VboMesh,getNumIndices,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: size_t getNumVertices() const
		r = engine->RegisterObjectMethod( "VboMesh", "uint getNumVertices()",
			 asMETHODPR(VboMesh,getNumVertices,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: GLenum getPrimitiveType() const
		r = engine->RegisterObjectMethod( "VboMesh", "uint getPrimitiveType()",
			 asMETHODPR(VboMesh,getPrimitiveType,()const,GLenum), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: const Layout& getLayout() const
		r = engine->RegisterObjectMethod( "VboMesh", "const gl::VboMesh::Layout& getLayout()",
                                         asMETHODPR(VboMesh,getLayout,()const,const VboMesh::Layout&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void bindIndexBuffer() const
		r = engine->RegisterObjectMethod( "VboMesh", "void bindIndexBuffer()",
			 asMETHODPR(VboMesh,bindIndexBuffer,()const,void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void enableClientStates() const
		r = engine->RegisterObjectMethod( "VboMesh", "void enableClientStates()",
			 asMETHODPR(VboMesh,enableClientStates,()const,void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void disableClientStates() const
		r = engine->RegisterObjectMethod( "VboMesh", "void disableClientStates()",
			 asMETHODPR(VboMesh,disableClientStates,()const,void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void bindAllData() const
		r = engine->RegisterObjectMethod( "VboMesh", "void bindAllData()",
			 asMETHODPR(VboMesh,bindAllData,()const,void), asCALL_THISCALL ); assert( r >= 0 );

		// STATIC METHOD: void unbindBuffers()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::VboMesh" : "gl::VboMesh" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "void unbindBuffers()",
			 asFUNCTIONPR(VboMesh::unbindBuffers,(),void), asCALL_CDECL ); assert( r >= 0 );


		//  void bufferIndices( const std::vector<uint32_t> &indices )
		//  void bufferPositions( const std::vector<Vec3f> &positions )
		//  void bufferPositions( const Vec3f *positions, size_t count )
		//  void bufferNormals( const std::vector<Vec3f> &normals )
		//  void bufferTexCoords2d( size_t unit, const std::vector<Vec2f> &texCoords )
		//  void bufferTexCoords3d( size_t unit, const std::vector<Vec3f> &texCoords )
		//  void bufferColorsRGB( const std::vector<Color> &colors )
		//  void bufferColorsRGBA( const std::vector<ColorA> &colors )
		r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// METHOD: class VertexIter mapVertexBuffer()
		/*r = engine->RegisterObjectMethod( "VboMesh", "VertexIter mapVertexBuffer()",
			 asMETHODPR(VboMesh,mapVertexBuffer,(), VboMesh::VertexIter), asCALL_THISCALL ); assert( r >= 0 );
*/

		// METHOD: Vbo& getIndexVbo() const
		r = engine->RegisterObjectMethod( "VboMesh", "Vbo& getIndexVbo()",
			 asMETHODPR(VboMesh,getIndexVbo,()const,Vbo&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vbo& getStaticVbo() const
		r = engine->RegisterObjectMethod( "VboMesh", "Vbo& getStaticVbo()",
			 asMETHODPR(VboMesh,getStaticVbo,()const,Vbo&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vbo& getDynamicVbo() const
		r = engine->RegisterObjectMethod( "VboMesh", "Vbo& getDynamicVbo()",
			 asMETHODPR(VboMesh,getDynamicVbo,()const,Vbo&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setCustomStaticLocation( size_t internalIndex, GLuint location )
		r = engine->RegisterObjectMethod( "VboMesh", "void setCustomStaticLocation( uint internalIndex, uint location )",
			 asMETHODPR(VboMesh,setCustomStaticLocation,(size_t ,GLuint ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCustomDynamicLocation( size_t internalIndex, GLuint location )
		r = engine->RegisterObjectMethod( "VboMesh", "void setCustomDynamicLocation( uint internalIndex, uint location )",
			 asMETHODPR(VboMesh,setCustomDynamicLocation,(size_t ,GLuint ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: size_t getTexCoordOffset( size_t unit ) const
		r = engine->RegisterObjectMethod( "VboMesh", "uint getTexCoordOffset( uint unit )",
			 asMETHODPR(VboMesh,getTexCoordOffset,(size_t )const,size_t), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setTexCoordOffset( size_t unit, size_t aTexCoordOffset )
		r = engine->RegisterObjectMethod( "VboMesh", "void setTexCoordOffset( uint unit, uint aTexCoordOffset )",
			 asMETHODPR(VboMesh,setTexCoordOffset,(size_t ,size_t ),void), asCALL_THISCALL ); assert( r >= 0 );



        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );


	}
}
