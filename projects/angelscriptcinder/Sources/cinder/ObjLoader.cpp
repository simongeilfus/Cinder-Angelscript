#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/ObjLoader.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderObjLoaderType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "ObjLoader", sizeof(ObjLoader), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderObjLoaderImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		/*// Default Constructor
		r = engine->RegisterObjectBehaviour( "ObjLoader", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<ObjLoader>), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/
		// Destructor
		r = engine->RegisterObjectBehaviour( "ObjLoader", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<ObjLoader>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "ObjLoader", asBEHAVE_CONSTRUCT,
			"void f(const ObjLoader &in )", asFUNCTION( ( as::RegistrationHelper::constructor<ObjLoader,const ObjLoader &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "ObjLoader","ObjLoader& opAssign(const ObjLoader &in)", asFUNCTION((as::RegistrationHelper::opAssign<ObjLoader&,ObjLoader,ObjLoader&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: **/
		// CONSTRUCTOR: ObjLoader( DataSourceRef dataSource, bool includeUVs = true )
	/*	r = engine->RegisterObjectBehaviour( "ObjLoader", asBEHAVE_CONSTRUCT,
			"void f( DataSourceRef dataSource, bool includeUVs = true )", asFUNCTION( ( as::RegistrationHelper::constructor<ObjLoader,DataSourceRef ,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: ObjLoader( DataSourceRef dataSource, DataSourceRef materialSource, bool includeUVs = true )
		r = engine->RegisterObjectBehaviour( "ObjLoader", asBEHAVE_CONSTRUCT,
			"void f( DataSourceRef dataSource, DataSourceRef materialSource, bool includeUVs = true )", asFUNCTION( ( as::RegistrationHelper::constructor<ObjLoader,DataSourceRef ,DataSourceRef ,bool > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/

		// PROPERTY: * \param optimizeVertices should the loader minimze the vertices by identifying shared vertices between faces. */
		//  void load( TriMesh *destTriMesh, boost::tribool loadNormals = boost::logic::indeterminate, boost::tribool loadTexCoords = boost::logic::indeterminate, bool optimizeVertices = true )
		// PROPERTY: * \param optimizeVertices should the loader minimize the vertices by identifying shared vertices between faces.*/
		//  void load( size_t groupIndex, TriMesh *destTriMesh, boost::tribool loadNormals = boost::logic::indeterminate, boost::tribool loadTexCoords = boost::logic::indeterminate, bool optimizeVertices = true )



		// STATIC METHOD: void write( DataTargetRef dataTarget, const TriMesh &mesh, bool writeNormals = true, bool writeUVs = true )
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::ObjLoader" : "ObjLoader" ); assert( r >= 0 );

	/*	r = engine->RegisterGlobalFunction( "void write( DataTargetRef dataTarget, const TriMesh &in mesh, bool writeNormals = true, bool writeUVs = true )",
			 asFUNCTIONPR(ObjLoader::write,(DataTargetRef ,const TriMesh &,bool ,bool ),void), asCALL_CDECL ); assert( r >= 0 );

*/

		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// METHOD: size_t getNumGroups() const
		r = engine->RegisterObjectMethod( "ObjLoader", "uint getNumGroups()",
			 asMETHODPR(ObjLoader,getNumGroups,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );



		//  const std::vector<Group>& getGroups() const

	}
}
