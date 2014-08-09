#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>

#include "cinder/Camera.h"


using namespace std;
using namespace ci;

namespace as {

	void registerCinderCameraType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "Camera", sizeof(Camera), asOBJ_VALUE | asOBJ_APP_CLASS | asOBJ_POD ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderCameraImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		/*r = engine->RegisterObjectBehaviour( "Camera", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<Camera>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "Camera", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<Camera>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "Camera", asBEHAVE_CONSTRUCT,
			"void f(const Camera &in )", asFUNCTION( ( as::RegistrationHelper::constructor<Camera,const Camera &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );
*/
		// Copy Assignement
		r = engine->RegisterObjectMethod( "Camera","Camera& opAssign(const Camera &in)", asFUNCTION((as::RegistrationHelper::opAssign<Camera&,Camera,Camera&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
		r = engine->RegisterObjectMethod( "Camera","Camera& opAssign(const CameraPersp &in)", asFUNCTION((as::RegistrationHelper::opAssign<Camera&,Camera,Camera&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
		r = engine->RegisterObjectMethod( "Camera","Camera& opAssign(const CameraOrtho &in)", asFUNCTION((as::RegistrationHelper::opAssign<Camera&,Camera,Camera&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
		r = engine->RegisterObjectMethod( "Camera","Camera& opAssign(const CameraStereo &in)", asFUNCTION((as::RegistrationHelper::opAssign<Camera&,Camera,Camera&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// METHOD: Vec3f getEyePoint() const
		r = engine->RegisterObjectMethod( "Camera", "Vec3f getEyePoint()",
			 asMETHODPR(Camera,getEyePoint,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setEyePoint( const Vec3f &aEyePoint )
		r = engine->RegisterObjectMethod( "Camera", "void setEyePoint( const Vec3f &in aEyePoint )",
			 asMETHODPR(Camera,setEyePoint,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getCenterOfInterest() const
		r = engine->RegisterObjectMethod( "Camera", "float getCenterOfInterest()",
			 asMETHODPR(Camera,getCenterOfInterest,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCenterOfInterest( float aCenterOfInterest )
		r = engine->RegisterObjectMethod( "Camera", "void setCenterOfInterest( float aCenterOfInterest )",
			 asMETHODPR(Camera,setCenterOfInterest,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f getCenterOfInterestPoint() const
		r = engine->RegisterObjectMethod( "Camera", "Vec3f getCenterOfInterestPoint()",
			 asMETHODPR(Camera,getCenterOfInterestPoint,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setCenterOfInterestPoint( const Vec3f &centerOfInterestPoint )
		r = engine->RegisterObjectMethod( "Camera", "void setCenterOfInterestPoint( const Vec3f &in centerOfInterestPoint )",
			 asMETHODPR(Camera,setCenterOfInterestPoint,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f getWorldUp() const
		r = engine->RegisterObjectMethod( "Camera", "Vec3f getWorldUp()",
			 asMETHODPR(Camera,getWorldUp,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setWorldUp( const Vec3f &aWorldUp )
		r = engine->RegisterObjectMethod( "Camera", "void setWorldUp( const Vec3f &in aWorldUp )",
			 asMETHODPR(Camera,setWorldUp,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void lookAt( const Vec3f &target )
		r = engine->RegisterObjectMethod( "Camera", "void lookAt( const Vec3f &in target )",
			 asMETHODPR(Camera,lookAt,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void lookAt( const Vec3f &aEyePoint, const Vec3f &target )
		r = engine->RegisterObjectMethod( "Camera", "void lookAt( const Vec3f &in aEyePoint, const Vec3f &in target )",
			 asMETHODPR(Camera,lookAt,(const Vec3f &,const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void lookAt( const Vec3f &aEyePoint, const Vec3f &target, const Vec3f &aUp )
		r = engine->RegisterObjectMethod( "Camera", "void lookAt( const Vec3f &in aEyePoint, const Vec3f &in target, const Vec3f &in aUp )",
			 asMETHODPR(Camera,lookAt,(const Vec3f &,const Vec3f &,const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: Vec3f getViewDirection() const
		r = engine->RegisterObjectMethod( "Camera", "Vec3f getViewDirection()",
			 asMETHODPR(Camera,getViewDirection,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setViewDirection( const Vec3f &aViewDirection )
		r = engine->RegisterObjectMethod( "Camera", "void setViewDirection( const Vec3f &in aViewDirection )",
			 asMETHODPR(Camera,setViewDirection,(const Vec3f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Quatf getOrientation() const
		r = engine->RegisterObjectMethod( "Camera", "Quatf getOrientation()",
			 asMETHODPR(Camera,getOrientation,()const,Quatf), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setOrientation( const Quatf &aOrientation )
		r = engine->RegisterObjectMethod( "Camera", "void setOrientation( const Quatf &in aOrientation )",
			 asMETHODPR(Camera,setOrientation,(const Quatf &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getFov() const
		r = engine->RegisterObjectMethod( "Camera", "float getFov()",
			 asMETHODPR(Camera,getFov,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setFov( float aFov )
		r = engine->RegisterObjectMethod( "Camera", "void setFov( float aFov )",
			 asMETHODPR(Camera,setFov,(float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getFovHorizontal() const
		r = engine->RegisterObjectMethod( "Camera", "float getFovHorizontal()",
			 asMETHODPR(Camera,getFovHorizontal,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setFovHorizontal( float aFov )
		r = engine->RegisterObjectMethod( "Camera", "void setFovHorizontal( float aFov )",
			 asMETHODPR(Camera,setFovHorizontal,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getAspectRatio() const
		r = engine->RegisterObjectMethod( "Camera", "float getAspectRatio()",
			 asMETHODPR(Camera,getAspectRatio,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setAspectRatio( float aAspectRatio )
		r = engine->RegisterObjectMethod( "Camera", "void setAspectRatio( float aAspectRatio )",
			 asMETHODPR(Camera,setAspectRatio,(float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getNearClip() const
		r = engine->RegisterObjectMethod( "Camera", "float getNearClip()",
			 asMETHODPR(Camera,getNearClip,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setNearClip( float aNearClip )
		r = engine->RegisterObjectMethod( "Camera", "void setNearClip( float aNearClip )",
			 asMETHODPR(Camera,setNearClip,(float ),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: float getFarClip() const
		r = engine->RegisterObjectMethod( "Camera", "float getFarClip()",
			 asMETHODPR(Camera,getFarClip,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: void setFarClip( float aFarClip )
		r = engine->RegisterObjectMethod( "Camera", "void setFarClip( float aFarClip )",
			 asMETHODPR(Camera,setFarClip,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		//  virtual void getNearClipCoordinates( Vec3f *topLeft, Vec3f *topRight, Vec3f *bottomLeft, Vec3f *bottomRight ) const
		//  virtual void getFarClipCoordinates( Vec3f *topLeft, Vec3f *topRight, Vec3f *bottomLeft, Vec3f *bottomRight ) const


		//  void getFrustum( float *left, float *top, float *right, float *bottom, float *near, float *far ) const

		// METHOD: virtual bool isPersp() const = 0
		r = engine->RegisterObjectMethod( "Camera", "bool isPersp()",
			 asMETHODPR(Camera,isPersp,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: virtual const Matrix44f& getProjectionMatrix() const
		r = engine->RegisterObjectMethod( "Camera", "const Matrix44f& getProjectionMatrix()",
			 asMETHODPR(Camera,getProjectionMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: virtual const Matrix44f& getModelViewMatrix() const
		r = engine->RegisterObjectMethod( "Camera", "const Matrix44f& getModelViewMatrix()",
			 asMETHODPR(Camera,getModelViewMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: virtual const Matrix44f& getInverseModelViewMatrix() const
		r = engine->RegisterObjectMethod( "Camera", "const Matrix44f& getInverseModelViewMatrix()",
			 asMETHODPR(Camera,getInverseModelViewMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Ray generateRay( float u, float v, float imagePlaneAspectRatio ) const
		r = engine->RegisterObjectMethod( "Camera", "Ray generateRay( float u, float v, float imagePlaneAspectRatio )",
			 asMETHODPR(Camera,generateRay,(float ,float ,float )const,Ray), asCALL_THISCALL ); assert( r >= 0 );

		//  void getBillboardVectors( Vec3f *right, Vec3f *up ) const


		// METHOD: Vec2f worldToScreen( const Vec3f &worldCoord, float screenWidth, float screenHeight ) const
		r = engine->RegisterObjectMethod( "Camera", "Vec2f worldToScreen( const Vec3f &in worldCoord, float screenWidth, float screenHeight )",
			 asMETHODPR(Camera,worldToScreen,(const Vec3f &,float ,float )const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f worldToEye( const Vec3f &worldCoord )
		r = engine->RegisterObjectMethod( "Camera", "Vec3f worldToEye( const Vec3f &in worldCoord )",
			 asMETHODPR(Camera,worldToEye,(const Vec3f &),Vec3f), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float worldToEyeDepth( const Vec3f &worldCoord ) const
		r = engine->RegisterObjectMethod( "Camera", "float worldToEyeDepth( const Vec3f &in worldCoord )",
			 asMETHODPR(Camera,worldToEyeDepth,(const Vec3f &)const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f worldToNdc( const Vec3f &worldCoord )
		r = engine->RegisterObjectMethod( "Camera", "Vec3f worldToNdc( const Vec3f &in worldCoord )",
			 asMETHODPR(Camera,worldToNdc,(const Vec3f &),Vec3f), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float getScreenRadius( const class Sphere &sphere, float screenWidth, float screenHeight ) const
		r = engine->RegisterObjectMethod( "Camera", "float getScreenRadius( const Sphere &in sphere, float screenWidth, float screenHeight )",
			 asMETHODPR(Camera,getScreenRadius,(const Sphere &,float ,float )const,float), asCALL_THISCALL ); assert( r >= 0 );


	}
	void registerCinderCameraPerspType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "CameraPersp", sizeof(CameraPersp), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderCameraPerspImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "CameraPersp", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<CameraPersp>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "CameraPersp", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<CameraPersp>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "CameraPersp", asBEHAVE_CONSTRUCT,
			"void f(const CameraPersp &in )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraPersp,const CameraPersp &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "CameraPersp","CameraPersp& opAssign(const CameraPersp &in)", asFUNCTION((as::RegistrationHelper::opAssign<CameraPersp&,CameraPersp,CameraPersp&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: CameraPersp( int pixelWidth, int pixelHeight, float fov ) // constructs screen-aligned camera
		r = engine->RegisterObjectBehaviour( "CameraPersp", asBEHAVE_CONSTRUCT,
			"void f( int pixelWidth, int pixelHeight, float fov )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraPersp,int ,int ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: CameraPersp( int pixelWidth, int pixelHeight, float fov, float nearPlane, float farPlane ) // constructs screen-aligned camera
		r = engine->RegisterObjectBehaviour( "CameraPersp", asBEHAVE_CONSTRUCT,
			"void f( int pixelWidth, int pixelHeight, float fov, float nearPlane, float farPlane )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraPersp,int ,int ,float ,float ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );


		// METHOD: void setPerspective( float verticalFovDegrees, float aspectRatio, float nearPlane, float farPlane )
		r = engine->RegisterObjectMethod( "CameraPersp", "void setPerspective( float verticalFovDegrees, float aspectRatio, float nearPlane, float farPlane )",
			 asMETHODPR(CameraPersp,setPerspective,(float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );


		//  A vertical lens shift of 1 (-1) will shift the view up (down) by half the height of the viewport. */
		//  void getLensShift( float *horizontal, float *vertical ) const
		//  A vertical lens shift of 1 (-1) will shift the view up (down) by half the height of the viewport. */
		// METHOD: Vec2f getLensShift() const
		r = engine->RegisterObjectMethod( "CameraPersp", "Vec2f getLensShift()",
			 asMETHODPR(CameraPersp,getLensShift,()const,Vec2f), asCALL_THISCALL ); assert( r >= 0 );

		//  A vertical lens shift of 1 (-1) will shift the view up (down) by half the height of the viewport. */
		// METHOD: void setLensShift( float horizontal, float vertical )
		r = engine->RegisterObjectMethod( "CameraPersp", "void setLensShift( float horizontal, float vertical )",
			 asMETHODPR(CameraPersp,setLensShift,(float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );

		//  A vertical lens shift of 1 (-1) will shift the view up (down) by half the height of the viewport. */
		// METHOD: void setLensShift( const Vec2f &shift )
		r = engine->RegisterObjectMethod( "CameraPersp", "void setLensShift( const Vec2f &in shift )",
			 asMETHODPR(CameraPersp,setLensShift,(const Vec2f &),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getLensShiftHorizontal() const
		r = engine->RegisterObjectMethod( "CameraPersp", "float getLensShiftHorizontal()",
			 asMETHODPR(CameraPersp,getLensShiftHorizontal,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		//  A horizontal lens shift of 1 (-1) will shift the view right (left) by half the width of the viewport. */
		// METHOD: void setLensShiftHorizontal( float horizontal )
		r = engine->RegisterObjectMethod( "CameraPersp", "void setLensShiftHorizontal( float horizontal )",
			 asMETHODPR(CameraPersp,setLensShiftHorizontal,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: float getLensShiftVertical() const
		r = engine->RegisterObjectMethod( "CameraPersp", "float getLensShiftVertical()",
			 asMETHODPR(CameraPersp,getLensShiftVertical,()const,float), asCALL_THISCALL ); assert( r >= 0 );

		//  A vertical lens shift of 1 (-1) will shift the view up (down) by half the height of the viewport. */
		// METHOD: void setLensShiftVertical( float vertical )
		r = engine->RegisterObjectMethod( "CameraPersp", "void setLensShiftVertical( float vertical )",
			 asMETHODPR(CameraPersp,setLensShiftVertical,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: virtual bool isPersp() const
		r = engine->RegisterObjectMethod( "CameraPersp", "bool isPersp()",
			 asMETHODPR(CameraPersp,isPersp,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: CameraPersp getFrameSphere( const class Sphere &worldSpaceSphere, int maxIterations = 20 ) const
		r = engine->RegisterObjectMethod( "CameraPersp", "CameraPersp getFrameSphere( const Sphere &in worldSpaceSphere, int maxIterations = 20 )",
			 asMETHOD(CameraPersp,getFrameSphere), asCALL_THISCALL ); assert( r >= 0 );


	}
	void registerCinderCameraOrthoType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "CameraOrtho", sizeof(CameraOrtho), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderCameraOrthoImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "CameraOrtho", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<CameraOrtho>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "CameraOrtho", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<CameraOrtho>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "CameraOrtho", asBEHAVE_CONSTRUCT,
			"void f(const CameraOrtho &in )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraOrtho,const CameraOrtho &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "CameraOrtho","CameraOrtho& opAssign(const CameraOrtho &in)", asFUNCTION((as::RegistrationHelper::opAssign<CameraOrtho&,CameraOrtho,CameraOrtho&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: CameraOrtho( float left, float right, float bottom, float top, float nearPlane, float farPlane )
		/*r = engine->RegisterObjectBehaviour( "CameraOrtho", asBEHAVE_CONSTRUCT,
			"void f( float left, float right, float bottom, float top, float nearPlane, float farPlane )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraOrtho,float ,float ,float ,float ,float ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

*/
		// METHOD: void setOrtho( float left, float right, float bottom, float top, float nearPlane, float farPlane )
		r = engine->RegisterObjectMethod( "CameraOrtho", "void setOrtho( float left, float right, float bottom, float top, float nearPlane, float farPlane )",
			 asMETHODPR(CameraOrtho,setOrtho,(float ,float ,float ,float ,float ,float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: virtual bool isPersp() const
		r = engine->RegisterObjectMethod( "CameraOrtho", "bool isPersp()",
			 asMETHODPR(CameraOrtho,isPersp,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


	}
	void registerCinderCameraStereoType( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Register the ObjectType
		r = engine->RegisterObjectType( "CameraStereo", sizeof(CameraStereo), asOBJ_VALUE | asOBJ_APP_CLASS_CDAK ); assert( r >= 0 );


		// Set back namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace(""); assert( r >= 0 );
		}

	}
	void registerCinderCameraStereoImpl( asIScriptEngine* engine, bool useNamespaces )
	{
		int r;

		// Set namespace if needed
		if( useNamespaces ){
			r = engine->SetDefaultNamespace("ci"); assert( r >= 0 );
		}

		// Default Constructor
		r = engine->RegisterObjectBehaviour( "CameraStereo", asBEHAVE_CONSTRUCT,
			"void f()", asFUNCTION( as::RegistrationHelper::constructor<CameraStereo>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Destructor
		r = engine->RegisterObjectBehaviour( "CameraStereo", asBEHAVE_DESTRUCT,
			"void f()", asFUNCTION(as::RegistrationHelper::destructor<CameraStereo>), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Constructor
		r = engine->RegisterObjectBehaviour( "CameraStereo", asBEHAVE_CONSTRUCT,
			"void f(const CameraStereo &in )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraStereo,const CameraStereo &> ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// Copy Assignement
		r = engine->RegisterObjectMethod( "CameraStereo","CameraStereo& opAssign(const CameraStereo &in)", asFUNCTION((as::RegistrationHelper::opAssign<CameraStereo&,CameraStereo,CameraStereo&>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		//  : mConvergence(1.0f), mEyeSeparation(0.05f), mIsStereo(false), mIsLeft(true)
		// CONSTRUCTOR: CameraStereo( int pixelWidth, int pixelHeight, float fov )
		r = engine->RegisterObjectBehaviour( "CameraStereo", asBEHAVE_CONSTRUCT,
			"void f( int pixelWidth, int pixelHeight, float fov )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraStereo,int ,int ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		// CONSTRUCTOR: CameraStereo( int pixelWidth, int pixelHeight, float fov, float nearPlane, float farPlane )
		r = engine->RegisterObjectBehaviour( "CameraStereo", asBEHAVE_CONSTRUCT,
			"void f( int pixelWidth, int pixelHeight, float fov, float nearPlane, float farPlane )", asFUNCTION( ( as::RegistrationHelper::constructor<CameraStereo,int ,int ,float ,float ,float > ) ), asCALL_CDECL_OBJLAST); assert( r >= 0 );

		

		// METHOD: float getConvergence() const
		r = engine->RegisterObjectMethod( "CameraStereo", "float getConvergence()",
			 asMETHODPR(CameraStereo,getConvergence,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setConvergence( float distance, bool adjustEyeSeparation=false )
		r = engine->RegisterObjectMethod( "CameraStereo", "void setConvergence( float distance, bool adjustEyeSeparation=false )",
			 asMETHODPR(CameraStereo,setConvergence,(float ,bool ),void), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: float getEyeSeparation() const
		r = engine->RegisterObjectMethod( "CameraStereo", "float getEyeSeparation()",
			 asMETHODPR(CameraStereo,getEyeSeparation,()const,float), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void setEyeSeparation( float distance )
		r = engine->RegisterObjectMethod( "CameraStereo", "void setEyeSeparation( float distance )",
			 asMETHODPR(CameraStereo,setEyeSeparation,(float ),void), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: Vec3f getEyePointShifted() const
		r = engine->RegisterObjectMethod( "CameraStereo", "Vec3f getEyePointShifted()",
			 asMETHODPR(CameraStereo,getEyePointShifted,()const,Vec3f), asCALL_THISCALL ); assert( r >= 0 );



		// METHOD: void enableStereoLeft()
		r = engine->RegisterObjectMethod( "CameraStereo", "void enableStereoLeft()",
			 asMETHODPR(CameraStereo,enableStereoLeft,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isStereoLeftEnabled() const
		r = engine->RegisterObjectMethod( "CameraStereo", "bool isStereoLeftEnabled()",
			 asMETHODPR(CameraStereo,isStereoLeftEnabled,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void enableStereoRight()
		r = engine->RegisterObjectMethod( "CameraStereo", "void enableStereoRight()",
			 asMETHODPR(CameraStereo,enableStereoRight,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isStereoRightEnabled() const
		r = engine->RegisterObjectMethod( "CameraStereo", "bool isStereoRightEnabled()",
			 asMETHODPR(CameraStereo,isStereoRightEnabled,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		// METHOD: void disableStereo()
		r = engine->RegisterObjectMethod( "CameraStereo", "void disableStereo()",
			 asMETHODPR(CameraStereo,disableStereo,(),void), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: bool isStereoEnabled() const
		r = engine->RegisterObjectMethod( "CameraStereo", "bool isStereoEnabled()",
			 asMETHODPR(CameraStereo,isStereoEnabled,()const,bool), asCALL_THISCALL ); assert( r >= 0 );


		//  virtual void getNearClipCoordinates( Vec3f *topLeft, Vec3f *topRight, Vec3f *bottomLeft, Vec3f *bottomRight ) const
		//  virtual void getFarClipCoordinates( Vec3f *topLeft, Vec3f *topRight, Vec3f *bottomLeft, Vec3f *bottomRight ) const

		// METHOD: virtual const Matrix44f& getProjectionMatrix() const
		r = engine->RegisterObjectMethod( "CameraStereo", "const Matrix44f& getProjectionMatrix()",
			 asMETHODPR(CameraStereo,getProjectionMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: virtual const Matrix44f& getModelViewMatrix() const
		r = engine->RegisterObjectMethod( "CameraStereo", "const Matrix44f& getModelViewMatrix()",
			 asMETHODPR(CameraStereo,getModelViewMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );

		// METHOD: virtual const Matrix44f& getInverseModelViewMatrix() const
		r = engine->RegisterObjectMethod( "CameraStereo", "const Matrix44f& getInverseModelViewMatrix()",
			 asMETHODPR(CameraStereo,getInverseModelViewMatrix,()const,const Matrix44f&), asCALL_THISCALL ); assert( r >= 0 );


	}
}
