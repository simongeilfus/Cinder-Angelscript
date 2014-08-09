#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/gl/DisplayList.h"


using namespace std;
using namespace ci;
using namespace ci::gl;

namespace as {

	void registerCinderDisplayListType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Register the ObjectType
		r = engine->RegisterObjectType( "DisplayList", sizeof(DisplayList), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );
        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderDisplayListImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        r = engine->SetDefaultNamespace("gl"); assert( r >= 0 );

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "DisplayList", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<DisplayList>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "DisplayList", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<DisplayList>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "DisplayList", asBEHAVE_CONSTRUCT,
			"void f(const DisplayList &in )", asFUNCTION( ( as::RegistrationHelper::constructor<DisplayList,const DisplayList &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "DisplayList","DisplayList& opAssign(const DisplayList &in)", asFUNCTION((as::RegistrationHelper::opAssign<DisplayList&,DisplayList,DisplayList&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  DisplayList( GLint aMode/* = GL_COMPILE*/ )

		// METHOD: void newList()
		r = engine->RegisterObjectMethod( "DisplayList", "void newList()",
			 asMETHODPR(DisplayList,newList,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void endList()
		r = engine->RegisterObjectMethod( "DisplayList", "void endList()",
			 asMETHODPR(DisplayList,endList,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: int getID() const
		r = engine->RegisterObjectMethod( "DisplayList", "int getID()",
			 asMETHODPR(DisplayList,getID,()const,int), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void draw() const
		r = engine->RegisterObjectMethod( "DisplayList", "void draw()",
			 asMETHODPR(DisplayList,draw,()const,void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Matrix44f& getModelMatrix()
		r = engine->RegisterObjectMethod( "DisplayList", "Matrix44f& getModelMatrix()",
			 asMETHODPR(DisplayList,getModelMatrix,(),Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Matrix44f& getModelMatrix() const
		/*r = engine->RegisterObjectMethod( "DisplayList", "const Matrix44f& getModelMatrix()",
			 asMETHODPR(DisplayList,getModelMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setMaterial( const Material &aMaterial )
		r = engine->RegisterObjectMethod( "DisplayList", "void setMaterial( const Material &in aMaterial )",
			 asMETHODPR(DisplayList,setMaterial,(const Material &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Material& getMaterial()
		r = engine->RegisterObjectMethod( "DisplayList", "Material& getMaterial()",
			 asMETHODPR(DisplayList,getMaterial,(),Material&), asCALL_THISCALL ); assert( r >= 0 );
*/


        
        r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
