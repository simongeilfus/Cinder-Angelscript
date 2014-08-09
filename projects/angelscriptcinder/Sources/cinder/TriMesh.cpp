#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/TriMesh.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderTriMeshType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "TriMesh", sizeof(TriMesh), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTriMeshImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "TriMesh", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<TriMesh>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "TriMesh", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<TriMesh>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "TriMesh", asBEHAVE_CONSTRUCT,
			"void f(const TriMesh &in )", asFUNCTION( ( as::RegistrationHelper::constructor<TriMesh,const TriMesh &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "TriMesh","TriMesh& opAssign(const TriMesh &in)", asFUNCTION((as::RegistrationHelper::opAssign<TriMesh&,TriMesh,TriMesh&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void clear()
		r = engine->RegisterObjectMethod( "TriMesh", "void clear()",
			 asMETHODPR(TriMesh,clear,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasNormals() const
		r = engine->RegisterObjectMethod( "TriMesh", "bool hasNormals()",
			 asMETHODPR(TriMesh,hasNormals,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasColorsRGB() const
		r = engine->RegisterObjectMethod( "TriMesh", "bool hasColorsRGB()",
			 asMETHODPR(TriMesh,hasColorsRGB,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasColorsRGBA() const
		r = engine->RegisterObjectMethod( "TriMesh", "bool hasColorsRGBA()",
			 asMETHODPR(TriMesh,hasColorsRGBA,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasTexCoords() const
		r = engine->RegisterObjectMethod( "TriMesh", "bool hasTexCoords()",
			 asMETHODPR(TriMesh,hasTexCoords,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void appendVertex( const Vec3f &v )
		r = engine->RegisterObjectMethod( "TriMesh", "void appendVertex( const Vec3f &in v )",
			 asMETHODPR(TriMesh,appendVertex,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void appendVertices( const Vec3f *verts, size_t num )

		//  void appendVertices( const Vec4d *verts, size_t num )

		// METHOD: void appendNormal( const Vec3f &v )
		r = engine->RegisterObjectMethod( "TriMesh", "void appendNormal( const Vec3f &in v )",
			 asMETHODPR(TriMesh,appendNormal,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void appendNormals( const Vec3f *normals, size_t num )

		//  void appendNormals( const Vec4d *normals, size_t num )

		// METHOD: void appendColorRgb( const Color &rgb )
		r = engine->RegisterObjectMethod( "TriMesh", "void appendColorRgb( const Color &in rgb )",
			 asMETHODPR(TriMesh,appendColorRgb,(const Color &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void appendColorRgba( const ColorA &rgba )
		r = engine->RegisterObjectMethod( "TriMesh", "void appendColorRgba( const ColorA &in rgba )",
			 asMETHODPR(TriMesh,appendColorRgba,(const ColorA &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void appendTexCoord( const Vec2f &v )
		r = engine->RegisterObjectMethod( "TriMesh", "void appendTexCoord( const Vec2f &in v )",
			 asMETHODPR(TriMesh,appendTexCoord,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void appendColorsRgb( const Color *rgbs, size_t num )

		//  void appendColorsRgba( const ColorA *rgbas, size_t num )

		//  void appendTexCoords( const Vec2f *texcoords, size_t num )

		// PROPERTY: */
		// METHOD: void appendTriangle( uint32_t v0, uint32_t v1, uint32_t v2 )
		r = engine->RegisterObjectMethod( "TriMesh", "void appendTriangle( uint32 v0, uint32 v1, uint32 v2 )",
			 asMETHODPR(TriMesh,appendTriangle,(uint32_t ,uint32_t ,uint32_t ),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void appendIndices( const uint32_t *indices, size_t num )


		// METHOD: size_t getNumIndices() const
		r = engine->RegisterObjectMethod( "TriMesh", "uint getNumIndices()",
			 asMETHODPR(TriMesh,getNumIndices,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: size_t getNumTriangles() const
		r = engine->RegisterObjectMethod( "TriMesh", "uint getNumTriangles()",
			 asMETHODPR(TriMesh,getNumTriangles,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: size_t getNumVertices() const
		r = engine->RegisterObjectMethod( "TriMesh", "uint getNumVertices()",
			 asMETHODPR(TriMesh,getNumVertices,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );



		//  void getTriangleVertices( size_t idx, Vec3f *a, Vec3f *b, Vec3f *c ) const


		// PROPERTY: */

		// METHOD: AxisAlignedBox3f calcBoundingBox() const
		r = engine->RegisterObjectMethod( "TriMesh", "AxisAlignedBox3f calcBoundingBox()",
			 asMETHODPR(TriMesh,calcBoundingBox,()const,AxisAlignedBox3f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: AxisAlignedBox3f calcBoundingBox( const Matrix44f &transform ) const
		r = engine->RegisterObjectMethod( "TriMesh", "AxisAlignedBox3f calcBoundingBox( const Matrix44f &in transform )",
			 asMETHODPR(TriMesh,calcBoundingBox,(const Matrix44f &)const,AxisAlignedBox3f), asCALL_THISCALL ); assert( r >= 0 );


/*
		// METHOD: void read( DataSourceRef in )
		r = engine->RegisterObjectMethod( "TriMesh", "void read( DataSourceRef in )",
			 asMETHODPR(TriMesh,read,(DataSourceRef ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void write( DataTargetRef out ) const
		r = engine->RegisterObjectMethod( "TriMesh", "void write( DataTargetRef out )",
			 asMETHODPR(TriMesh,write,(DataTargetRef )const,void), asCALL_THISCALL ); assert( r >= 0 );

*/

		// METHOD: void recalculateNormals()
		r = engine->RegisterObjectMethod( "TriMesh", "void recalculateNormals()",
			 asMETHODPR(TriMesh,recalculateNormals,(),void), asCALL_THISCALL ); assert( r >= 0 );


	}
	void registerCinderTriMesh2dType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "TriMesh2d", sizeof(TriMesh2d), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTriMesh2dImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "TriMesh2d", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<TriMesh2d>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "TriMesh2d", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<TriMesh2d>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "TriMesh2d", asBEHAVE_CONSTRUCT,
			"void f(const TriMesh2d &in )", asFUNCTION( ( as::RegistrationHelper::constructor<TriMesh2d,const TriMesh2d &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "TriMesh2d","TriMesh2d& opAssign(const TriMesh2d &in)", asFUNCTION((as::RegistrationHelper::opAssign<TriMesh2d&,TriMesh2d,TriMesh2d&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// METHOD: void clear()
		r = engine->RegisterObjectMethod( "TriMesh2d", "void clear()",
			 asMETHODPR(TriMesh2d,clear,(),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: bool hasColorsRgb() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "bool hasColorsRgb()",
			 asMETHODPR(TriMesh2d,hasColorsRgb,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasColorsRgba() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "bool hasColorsRgba()",
			 asMETHODPR(TriMesh2d,hasColorsRgba,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool hasTexCoords() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "bool hasTexCoords()",
			 asMETHODPR(TriMesh2d,hasTexCoords,()const,bool), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void appendVertex( const Vec2f &v )
		r = engine->RegisterObjectMethod( "TriMesh2d", "void appendVertex( const Vec2f &in v )",
			 asMETHODPR(TriMesh2d,appendVertex,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );


		//  void appendVertices( const Vec2f *verts, size_t num )

		// METHOD: void appendColorRgb( const Color &rgb )
		r = engine->RegisterObjectMethod( "TriMesh2d", "void appendColorRgb( const Color &in rgb )",
			 asMETHODPR(TriMesh2d,appendColorRgb,(const Color &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void appendColorRgba( const ColorA &rgba )
		r = engine->RegisterObjectMethod( "TriMesh2d", "void appendColorRgba( const ColorA &in rgba )",
			 asMETHODPR(TriMesh2d,appendColorRgba,(const ColorA &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void appendTexCoord( const Vec2f &v )
		r = engine->RegisterObjectMethod( "TriMesh2d", "void appendTexCoord( const Vec2f &in v )",
			 asMETHODPR(TriMesh2d,appendTexCoord,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void appendColorsRgb( const Color *rgbs, size_t num )

		//  void appendColorsRgba( const ColorA *rgbas, size_t num )

		//  void appendTexCoords( const Vec2f *texcoords, size_t num )

		// PROPERTY: */
		// METHOD: void appendTriangle( uint32_t v0, uint32_t v1, uint32_t v2 )
		r = engine->RegisterObjectMethod( "TriMesh2d", "void appendTriangle( uint32 v0, uint32 v1, uint32 v2 )",
			 asMETHODPR(TriMesh2d,appendTriangle,(uint32_t ,uint32_t ,uint32_t ),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void appendIndices( const uint32_t *indices, size_t num )


		// METHOD: size_t getNumIndices() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "uint getNumIndices()",
			 asMETHODPR(TriMesh2d,getNumIndices,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: size_t getNumTriangles() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "uint getNumTriangles()",
			 asMETHODPR(TriMesh2d,getNumTriangles,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: size_t getNumVertices() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "uint getNumVertices()",
			 asMETHODPR(TriMesh2d,getNumVertices,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );



		//  void getTriangleVertices( size_t idx, Vec2f *a, Vec2f *b, Vec2f *c ) const


		//  const std::vector<uint32_t>& getIndices() const */


		// METHOD: Rectf calcBoundingBox() const
		r = engine->RegisterObjectMethod( "TriMesh2d", "Rectf calcBoundingBox()",
			 asMETHODPR(TriMesh2d,calcBoundingBox,()const,Rectf), asCALL_THISCALL ); assert( r >= 0 );


	}
}
