#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Font.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderFontType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Font", sizeof(Font), asOBJ_VALUE | asOBJ_APP_CLASS_CDA ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderFontImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "Font", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Font>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Font", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Font>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		/*r = engine->RegisterObjectBehaviour( "Font", asBEHAVE_CONSTRUCT,
			"void f(const Font &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Font,const Font &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );*/

		// Copy Assignement
		r = engine->RegisterObjectMethod( "Font","Font& opAssign(const Font &in)", asFUNCTION((as::RegistrationHelper::opAssign<Font&,Font,Font&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef uint16_t Glyph


		// PROPERTY: \note Assumes a point size relative to 72dpi on Cocoa but 96dpi on Windows. This creates rough parity between the platforms on type size, but in Windows this renders fonts smaller than normal. **/
		// CONSTRUCTOR: Font( const std::string &aName, float size )
		r = engine->RegisterObjectBehaviour( "Font", asBEHAVE_CONSTRUCT,
			"void f( string &in aName, float size )", asFUNCTION( ( as::RegistrationHelper::constructor<Font,const std::string &,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: \note Assumes a point size relative to 72dpi on Cocoa but 96dpi on Windows. This creates rough parity between the platforms on type size, but in Windows this renders fonts smaller than normal. **/
		// CONSTRUCTOR: Font( DataSourceRef dataSource, float size )
		/*r = engine->RegisterObjectBehaviour( "Font", asBEHAVE_CONSTRUCT,
			"void f( DataSourceRef dataSource, float size )", asFUNCTION( ( as::RegistrationHelper::constructor<Font,DataSourceRef ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/

		//  const std::string& getName() const
		//  std::string getFullName() const
		// METHOD: float getSize() const
		r = engine->RegisterObjectMethod( "Font", "float getSize()",
			 asMETHODPR(Font,getSize,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getLeading() const
		r = engine->RegisterObjectMethod( "Font", "float getLeading()",
			 asMETHODPR(Font,getLeading,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getAscent() const
		r = engine->RegisterObjectMethod( "Font", "float getAscent()",
			 asMETHODPR(Font,getAscent,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getDescent() const
		r = engine->RegisterObjectMethod( "Font", "float getDescent()",
			 asMETHODPR(Font,getDescent,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: size_t getNumGlyphs() const
		r = engine->RegisterObjectMethod( "Font", "uint getNumGlyphs()",
			 asMETHODPR(Font,getNumGlyphs,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Glyph getGlyphIndex( size_t idx ) const
		r = engine->RegisterObjectMethod( "Font", "uint16 getGlyphIndex( uint idx )",
                                         asMETHODPR(Font,getGlyphIndex,(size_t )const,Font::Glyph), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Glyph getGlyphChar( char utf8Char ) const
		r = engine->RegisterObjectMethod( "Font", "uint16 getGlyphChar( int8 utf8Char )",
			 asMETHODPR(Font,getGlyphChar,(char )const,Font::Glyph), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Shape2d getGlyphShape( Glyph glyphIndex ) const
		r = engine->RegisterObjectMethod( "Font", "Shape2d getGlyphShape( uint16 glyphIndex )",
			 asMETHODPR(Font,getGlyphShape,(Font::Glyph )const,Shape2d), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Rectf getGlyphBoundingBox( Glyph glyph ) const
		r = engine->RegisterObjectMethod( "Font", "Rectf getGlyphBoundingBox( uint16 glyph )",
			 asMETHODPR(Font,getGlyphBoundingBox,(Font::Glyph )const,Rectf), asCALL_THISCALL ); assert( r >= 0 );


		// STATIC METHOD: Font getDefault()
		r = engine->SetDefaultNamespace( useNamespaces ? "ci::Font" : "Font" ); assert( r >= 0 );

		r = engine->RegisterGlobalFunction( "Font getDefault()",
			 asFUNCTIONPR(Font::getDefault,(),Font), asCALL_CDECL ); assert( r >= 0 );


		r = engine->SetDefaultNamespace(""); assert( r >= 0 );

	}
}
