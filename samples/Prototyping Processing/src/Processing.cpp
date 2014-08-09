#include "Processing.h"
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"


using namespace ci;
using namespace ci::app;
using namespace std;

namespace processing {
    
    bool doFill         = true;
    bool doStroke       = true;
    Color fillColor     = Color::white();
    Color strokeColor   = Color::black();
    
    
    
    
    void size( int w, int h )
    {
        AppNative::get()->setWindowSize( w, h );
    }
    
    void background( int gray )
    {
        gl::clear( ColorA::gray( (float) gray / 255.0f ) );
    }
    void background( int r, int g, int b )
    {
        gl::clear( ColorA( (float) r / 255.0f, (float) g / 255.0f, (float) b / 255.0f, 1.0f ) );
    }
    
    void fill( int gray )
    {
        doFill = true;
        fillColor = Color::gray( (float) gray / 255.0f );
    }
    void fill( int r, int g, int b )
    {
        doFill = true;
        fillColor = Color( (float) r / 255.0f, (float) g / 255.0f, (float) b / 255.0f );
    }
    void noFill()
    {
        doFill = false;
    }
    
    void stroke( int gray )
    {
        doStroke = true;
        strokeColor = Color::gray( (float) gray / 255.0f );
    }
    void stroke( int r, int g, int b )
    {
        doStroke = true;
        strokeColor = Color( (float) r / 255.0f, (float) g / 255.0f, (float) b / 255.0f );
    }
    void noStroke()
    {
        doStroke = false;
    }
    
    void line( float x1, float y1, float x2, float y2 )
    {
        gl::color( strokeColor );
        gl::drawLine( Vec2f( x1, y1 ), Vec2f( x2, y2 ) );
    }
    void rect( float x, float y, float w, float h )
    {
        if( doFill ){
            gl::color( fillColor );
            gl::drawSolidRect( Rectf( Vec2f( x, y ), Vec2f( x, y ) + Vec2f( w, h ) ) );
        }
        if( doStroke ){
            gl::color( strokeColor );
            gl::drawStrokedRect( Rectf( Vec2f( x, y ), Vec2f( x, y ) + Vec2f( w, h ) ) );
        }
    }
    void ellipse( float x, float y, float w, float h )
    {
        if( doFill ){
            gl::color( fillColor );
            gl::drawSolidEllipse( Vec2f( x, y ), w, h );
        }
        if( doStroke ){
            gl::color( strokeColor );
            gl::drawStrokedEllipse( Vec2f( x, y ), w, h );
        }
    }
    
    
    
    void registerProcessing( asIScriptEngine* engine )
    {
        int r;
        
        r = engine->RegisterGlobalFunction("void size( int w, int h )", asFUNCTION(size), asCALL_CDECL );  assert( r >= 0 );
        
        r = engine->RegisterGlobalFunction("void background( int gray )", asFUNCTIONPR(background,(int),void), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void background( int r, int g, int b )", asFUNCTIONPR(background,(int,int,int),void), asCALL_CDECL );  assert( r >= 0 );
        
        r = engine->RegisterGlobalFunction("void fill( int gray )", asFUNCTIONPR(fill,(int),void), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void fill( int r, int g, int b )", asFUNCTIONPR(fill,(int,int,int),void), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void noFill()", asFUNCTION(noFill), asCALL_CDECL );  assert( r >= 0 );
        
        r = engine->RegisterGlobalFunction("void stroke( int gray )", asFUNCTIONPR(stroke,(int),void), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void stroke( int r, int g, int b )", asFUNCTIONPR(stroke,(int,int,int),void), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void noStroke()", asFUNCTION(noStroke), asCALL_CDECL );  assert( r >= 0 );
        
        r = engine->RegisterGlobalFunction("void line( float x1, float y1, float x2, float y2 )", asFUNCTION(line), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void rect( float x, float y, float w, float h )", asFUNCTION(rect), asCALL_CDECL );  assert( r >= 0 );
        r = engine->RegisterGlobalFunction("void ellipse( float x, float y, float w, float h )", asFUNCTION(ellipse), asCALL_CDECL );  assert( r >= 0 );
    }
    
}