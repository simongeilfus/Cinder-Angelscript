#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Text.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderTextLayoutType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "TextLayout", sizeof(TextLayout), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTextLayoutImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "TextLayout", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<TextLayout>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "TextLayout", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<TextLayout>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "TextLayout", asBEHAVE_CONSTRUCT,
			"void f(const TextLayout &in )", asFUNCTION( ( as::RegistrationHelper::constructor<TextLayout,const TextLayout &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "TextLayout","TextLayout& opAssign(const TextLayout &in)", asFUNCTION((as::RegistrationHelper::opAssign<TextLayout&,TextLayout,TextLayout&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: */


		// METHOD: void clear( const Color &color )
		r = engine->RegisterObjectMethod( "TextLayout", "void clear( const Color &in color )",
			 asMETHODPR(TextLayout,clear,(const Color &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void clear( const ColorA &color )
		r = engine->RegisterObjectMethod( "TextLayout", "void clear( const ColorA &in color )",
			 asMETHODPR(TextLayout,clear,(const ColorA &),void), asCALL_THISCALL ); assert( r >= 0 );



		//  void addLine( const std::string &line )

		//  void addCenteredLine( const std::string &line )

		//  void addRightLine( const std::string &line )

		//  void append( const std::string &str )

		// METHOD: void setFont( const Font &font )
		r = engine->RegisterObjectMethod( "TextLayout", "void setFont( const Font &in font )",
			 asMETHODPR(TextLayout,setFont,(const Font &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setColor( const Color &color )
		r = engine->RegisterObjectMethod( "TextLayout", "void setColor( const Color &in color )",
			 asMETHODPR(TextLayout,setColor,(const Color &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setColor( const ColorA &color )
		r = engine->RegisterObjectMethod( "TextLayout", "void setColor( const ColorA &in color )",
			 asMETHODPR(TextLayout,setColor,(const ColorA &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setLeadingOffset( float leadingOffset )
		r = engine->RegisterObjectMethod( "TextLayout", "void setLeadingOffset( float leadingOffset )",
			 asMETHODPR(TextLayout,setLeadingOffset,(float ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void setBorder( int horizontal, int vertical )
		r = engine->RegisterObjectMethod( "TextLayout", "void setBorder( int horizontal, int vertical )",
			 asMETHODPR(TextLayout,setBorder,(int ,int ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: Surface render( bool useAlpha = false, bool premultiplied = false )
		r = engine->RegisterObjectMethod( "TextLayout", "Surface render( bool useAlpha = false, bool premultiplied = false )",
			 asMETHODPR(TextLayout,render,(bool ,bool ),Surface), asCALL_THISCALL ); assert( r >= 0 );


	}
	void registerCinderTextBoxType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "TextBox", sizeof(TextBox), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderTextBoxImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "TextBox", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<TextBox>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "TextBox", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<TextBox>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "TextBox", asBEHAVE_CONSTRUCT,
			"void f(const TextBox &in )", asFUNCTION( ( as::RegistrationHelper::constructor<TextBox,const TextBox &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "TextBox","TextBox& opAssign(const TextBox &in)", asFUNCTION((as::RegistrationHelper::opAssign<TextBox&,TextBox,TextBox&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// PROPERTY: typedef enum Alignment Alignment
		// PROPERTY: enum


		// METHOD: TextBox& size( Vec2i sz )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& size( Vec2i sz )",
			 asMETHODPR(TextBox,size,(Vec2i ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: TextBox& size( int width, int height )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& size( int width, int height )",
			 asMETHODPR(TextBox,size,(int ,int ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec2i getSize() const
		r = engine->RegisterObjectMethod( "TextBox", "Vec2i getSize()",
			 asMETHODPR(TextBox,getSize,()const,Vec2i), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setSize( Vec2i sz )
		r = engine->RegisterObjectMethod( "TextBox", "void setSize( Vec2i sz )",
			 asMETHODPR(TextBox,setSize,(Vec2i ),void), asCALL_THISCALL ); assert( r >= 0 );


		//  TextBox& text( const std::string &t )
		//  const std::string& getText() const
		//  void setText( const std::string &t )
		//  void appendText( const std::string &t )

		// METHOD: TextBox& font( const Font &f )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& font( const Font &in f )",
			 asMETHODPR(TextBox,font,(const Font &),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const Font& getFont() const
		r = engine->RegisterObjectMethod( "TextBox", "const Font& getFont()",
			 asMETHODPR(TextBox,getFont,()const,const Font&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setFont( const Font &f )
		r = engine->RegisterObjectMethod( "TextBox", "void setFont( const Font &in f )",
			 asMETHODPR(TextBox,setFont,(const Font &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: TextBox& alignment( Alignment align )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& alignment( int align )",
                                         asMETHODPR(TextBox,alignment,(TextBox::Alignment ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Alignment getAlignment() const
		r = engine->RegisterObjectMethod( "TextBox", "int getAlignment()",
			 asMETHODPR(TextBox,getAlignment,()const,TextBox::Alignment), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setAlignment( Alignment align )
		r = engine->RegisterObjectMethod( "TextBox", "void setAlignment( int align )",
			 asMETHODPR(TextBox,setAlignment,(TextBox::Alignment ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: TextBox& color( ColorA color )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& color( ColorA color )",
			 asMETHODPR(TextBox,color,(ColorA ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: ColorA getColor() const
		r = engine->RegisterObjectMethod( "TextBox", "ColorA getColor()",
			 asMETHODPR(TextBox,getColor,()const,ColorA), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setColor( ColorA color )
		r = engine->RegisterObjectMethod( "TextBox", "void setColor( ColorA color )",
			 asMETHODPR(TextBox,setColor,(ColorA ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: TextBox& backgroundColor( ColorA bgColor )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& backgroundColor( ColorA bgColor )",
			 asMETHODPR(TextBox,backgroundColor,(ColorA ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: ColorA getBackgroundColor() const
		r = engine->RegisterObjectMethod( "TextBox", "ColorA getBackgroundColor()",
			 asMETHODPR(TextBox,getBackgroundColor,()const,ColorA), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setBackgroundColor( ColorA bgColor )
		r = engine->RegisterObjectMethod( "TextBox", "void setBackgroundColor( ColorA bgColor )",
			 asMETHODPR(TextBox,setBackgroundColor,(ColorA ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: TextBox& premultiplied( bool premult = true )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& premultiplied( bool premult = true )",
			 asMETHODPR(TextBox,premultiplied,(bool ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool getPremultiplied() const
		r = engine->RegisterObjectMethod( "TextBox", "bool getPremultiplied()",
			 asMETHODPR(TextBox,getPremultiplied,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setPremultiplied( bool premult )
		r = engine->RegisterObjectMethod( "TextBox", "void setPremultiplied( bool premult )",
			 asMETHODPR(TextBox,setPremultiplied,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: TextBox& ligate( bool ligateText = true )
		r = engine->RegisterObjectMethod( "TextBox", "TextBox& ligate( bool ligateText = true )",
			 asMETHODPR(TextBox,ligate,(bool ),TextBox&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool getLigate() const
		r = engine->RegisterObjectMethod( "TextBox", "bool getLigate()",
			 asMETHODPR(TextBox,getLigate,()const,bool), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setLigate( bool ligateText )
		r = engine->RegisterObjectMethod( "TextBox", "void setLigate( bool ligateText )",
			 asMETHODPR(TextBox,setLigate,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec2f measure() const
		r = engine->RegisterObjectMethod( "TextBox", "Vec2f measure()",
			 asMETHODPR(TextBox,measure,()const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		// PROPERTY: \warning Does not support word wrapping on Windows. **/
		//  std::vector<std::pair<uint16_t,Vec2f> > measureGlyphs() const

		//  Surface render( Vec2f offset = Vec2f::zero() )

	}
}
