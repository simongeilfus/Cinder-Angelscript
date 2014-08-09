#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/PolyLine.h"


using namespace std;
using namespace ci;

namespace as {

	template<typename T>
	void registerCinderPolyLineType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( name.c_str(), sizeof(PolyLine<T>), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	template<typename T>
	void registerCinderPolyLineImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<PolyLine<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<PolyLine<T>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<PolyLine<T>,const PolyLine<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<PolyLine<T>&,PolyLine<T>,PolyLine<T>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: PolyLine( const std::vector<T> &aPoints ) : mPoints( aPoints ), mClosed( false )
/*		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
			std::string( "void f( array<Vec2f> &in aPoints )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<PolyLine<T>,const std::vector<T> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/

		//  const std::vector<T>& getPoints() const
		//  std::vector<T>& getPoints()


		// PROPERTY: typedef typename std::vector<T>::const_iterator const_iterator
		// PROPERTY: typedef typename std::vector<T>::iterator iterator

		// METHOD: size_t size() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint size()" ).c_str(),
			 asMETHODPR(PolyLine<T>,size,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void push_back( const T &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void push_back( const " + type + " &in v )" ).c_str(),
			 asMETHODPR(PolyLine<T>,push_back,(const T &),void), asCALL_THISCALL ); assert( r >= 0 );

		/*// METHOD: iterator begin()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "iterator begin()" ).c_str(),
			 asMETHODPR(PolyLine<T>,begin,(),iterator), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const_iterator begin() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "const_iterator begin()" ).c_str(),
			 asMETHODPR(PolyLine<T>,begin,()const,const_iterator), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: iterator end()
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "iterator end()" ).c_str(),
			 asMETHODPR(PolyLine<T>,end,(),iterator), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: const_iterator end() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "const_iterator end()" ).c_str(),
			 asMETHODPR(PolyLine<T>,end,()const,const_iterator), asCALL_THISCALL ); assert( r >= 0 );

*/
		// METHOD: void setClosed( bool aClosed = true )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setClosed( bool aClosed = true )" ).c_str(),
			 asMETHODPR(PolyLine<T>,setClosed,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isClosed() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isClosed()" ).c_str(),
			 asMETHODPR(PolyLine<T>,isClosed,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: T getPosition( float t ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getPosition( float t )" ).c_str(),
			 asMETHODPR(PolyLine<T>,getPosition,(float )const,T), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: T getDerivative( float t ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( type + " getDerivative( float t )" ).c_str(),
			 asMETHODPR(PolyLine<T>,getDerivative,(float )const,T), asCALL_THISCALL ); assert( r >= 0 );


		//  void scale( const T &scaleFactor, T scaleCenter = T::zero() )
		// METHOD: void offset( const T &offsetBy )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void offset( const " + type + " &in offsetBy )" ).c_str(),
			 asMETHODPR(PolyLine<T>,offset,(const T &),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: bool contains( const Vec2f &pt ) const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool contains( const Vec2f &in pt )" ).c_str(),
			 asMETHODPR(PolyLine<T>,contains,(const Vec2f &)const,bool), asCALL_THISCALL ); assert( r >= 0 );



		//  static std::vector<PolyLine> calcUnion( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )

		//  static std::vector<PolyLine> calcIntersection( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )

		//  static std::vector<PolyLine> calcXor( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )

		//  static std::vector<PolyLine> calcDifference( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )

	}
    
    
	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderPolyLineType<Vec2f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderPolyLineImpl<Vec2f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
    
    
	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderPolyLineType<Vec2d>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderPolyLineImpl<Vec2d>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
    
	// template specializations so we can keep our implementation in the cpp file
	template void registerCinderPolyLineType<Vec3f>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template<> void registerCinderPolyLineImpl<Vec3f>( asIScriptEngine* engine, const std::string & name, const std::string & type, const std::string &suffix, bool useNamespaces)
	{
		int r;
        
		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}
        
		// Default Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
                                            "void f()", asFUNCTION( as::RegistrationHelper::constructor<PolyLine<Vec3f>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        
		// Destructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_DESTRUCT,
                                            "void f()", asFUNCTION(as::RegistrationHelper::destructor<PolyLine<Vec3f>>), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        
		// Copy Constructor
		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
                                            ( "void f(const " + name + " &in )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<PolyLine<Vec3f>,const PolyLine<Vec3f> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        
		// Copy Assignement
		r = engine->RegisterObjectMethod( name.c_str(), ( name + "& opAssign(const " + name + " &in)" ).c_str(), asFUNCTION((as::RegistrationHelper::opAssign<PolyLine<Vec3f>&,PolyLine<Vec3f>,PolyLine<Vec3f>&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        
		// CONSTRUCTOR: PolyLine( const std::vector<Vec3f> &aPoints ) : mPoints( aPoints ), mClosed( false )
        /*		r = engine->RegisterObjectBehaviour( name.c_str(), asBEHAVE_CONSTRUCT,
         std::string( "void f( array<Vec2f> &in aPoints )" ).c_str(), asFUNCTION( ( as::RegistrationHelper::constructor<PolyLine<Vec3f>,const std::vector<Vec3f> &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
         */
        
		//  const std::vector<Vec3f>& getPoints() const
		//  std::vector<Vec3f>& getPoints()
        
        
		// PROPERTY: typedef typename std::vector<Vec3f>::const_iterator const_iterator
		// PROPERTY: typedef typename std::vector<Vec3f>::iterator iterator
        
		// METHOD: size_t size() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "uint size()" ).c_str(),
                                         asMETHODPR(PolyLine<Vec3f>,size,()const,size_t), asCALL_THISCALL ); assert( r >= 0 );
        
        
		// METHOD: void push_back( const T &v )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void push_back( const " + type + " &in v )" ).c_str(),
                                         asMETHODPR(PolyLine<Vec3f>,push_back,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );
        
		/*// METHOD: iterator begin()
         r = engine->RegisterObjectMethod( name.c_str(), std::string( "iterator begin()" ).c_str(),
         asMETHODPR(PolyLine<Vec3f>,begin,(),iterator), asCALL_THISCALL ); assert( r >= 0 );
         
         // METHOD: const_iterator begin() const
         r = engine->RegisterObjectMethod( name.c_str(), std::string( "const_iterator begin()" ).c_str(),
         asMETHODPR(PolyLine<Vec3f>,begin,()const,const_iterator), asCALL_THISCALL ); assert( r >= 0 );
         
         // METHOD: iterator end()
         r = engine->RegisterObjectMethod( name.c_str(), std::string( "iterator end()" ).c_str(),
         asMETHODPR(PolyLine<Vec3f>,end,(),iterator), asCALL_THISCALL ); assert( r >= 0 );
         
         // METHOD: const_iterator end() const
         r = engine->RegisterObjectMethod( name.c_str(), std::string( "const_iterator end()" ).c_str(),
         asMETHODPR(PolyLine<Vec3f>,end,()const,const_iterator), asCALL_THISCALL ); assert( r >= 0 );
         
         */
		// METHOD: void setClosed( bool aClosed = true )
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "void setClosed( bool aClosed = true )" ).c_str(),
                                         asMETHODPR(PolyLine<Vec3f>,setClosed,(bool ),void), asCALL_THISCALL ); assert( r >= 0 );
        
		// METHOD: bool isClosed() const
		r = engine->RegisterObjectMethod( name.c_str(), std::string( "bool isClosed()" ).c_str(),
                                         asMETHODPR(PolyLine<Vec3f>,isClosed,()const,bool), asCALL_THISCALL ); assert( r >= 0 );
        
        
        
        
		//  static std::vector<PolyLine> calcUnion( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )
        
		//  static std::vector<PolyLine> calcIntersection( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )
        
		//  static std::vector<PolyLine> calcXor( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )
        
		//  static std::vector<PolyLine> calcDifference( const std::vector<PolyLine> &a, std::vector<PolyLine> &b )
        
	}
    
    
	/*// template specializations so we can keep our implementation in the cpp file
	template void registerCinderPolyLineType<Vec3d>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);
	template void registerCinderPolyLineImpl<Vec3d>( asIScriptEngine*, const std::string &, const std::string &, const std::string &, bool);*/
}
