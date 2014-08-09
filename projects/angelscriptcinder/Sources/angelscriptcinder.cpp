#include "angelscriptcinder.h"
#include "RegistrationHelper.h"
#include <angelscript.h>


#include "cinder/Vector.h"

using namespace std;
using namespace ci;

namespace as {

	void registerCinder( asIScriptEngine* engine, bool useNamespaces )
	{

		// register type first (sort of forward declaration hack)
		registerCinderArcballType( engine, useNamespaces );
		registerCinderAreaType( engine, useNamespaces );
		registerCinderAxisAlignedBox3fType( engine, useNamespaces );
		registerCinderBSplineType<Vec2f>( engine, "BSpline2f", "Vec2f", "f", useNamespaces );
		registerCinderBSplineType<Vec3f>( engine, "BSpline3f", "Vec3f", "f", useNamespaces );
		registerCinderCameraType( engine, useNamespaces );
		registerCinderCameraPerspType( engine, useNamespaces );
		registerCinderCameraOrthoType( engine, useNamespaces );
		registerCinderCameraStereoType( engine, useNamespaces );
		registerCinderChannelTType<uint8_t>( engine, "Channel", "uint8", "", useNamespaces );
		registerCinderChannelTType<float>( engine, "Channel32f", "float", "f", useNamespaces );
		registerCinderClipboardType( engine, useNamespaces );
		registerCinderColorTType<float>( engine, "Color", "float", "f", useNamespaces );
		registerCinderColorATType<float>( engine, "ColorA", "float", "f", useNamespaces );
		registerCinderFontType( engine, useNamespaces );
		registerCinderFrustumType<float>( engine, "Frustumf", "float", "f", useNamespaces );
		registerCinderFrustumType<double>( engine, "Frustumd", "double", "d", useNamespaces );
		registerCinderMatrix22Type<float>( engine, "Matrix22f", "float", "f", useNamespaces );
		registerCinderMatrix22Type<double>( engine, "Matrix22d", "double", "d", useNamespaces );
		registerCinderMatrix33Type<float>( engine, "Matrix33f", "float", "f", useNamespaces );
		registerCinderMatrix33Type<double>( engine, "Matrix33d", "double", "d", useNamespaces );
		registerCinderMatrix44Type<float>( engine, "Matrix44f", "float", "f", useNamespaces );
		registerCinderMatrix44Type<double>( engine, "Matrix44d", "double", "d", useNamespaces );
		registerCinderMatrixAffine2Type<float>( engine, "MatrixAffine2f", "float", "f", useNamespaces );
		registerCinderMatrixAffine2Type<double>( engine, "MatrixAffine2d", "double", "d", useNamespaces );
		registerCinderMayaCamUIType( engine, useNamespaces );
		//registerCinderObjLoaderType( engine, useNamespaces );
		registerCinderPath2dType( engine, useNamespaces );
		registerCinderPerlinType( engine, useNamespaces );
		registerCinderPlaneType<float>( engine, "Planef", "float", "f", useNamespaces );
		registerCinderPlaneType<double>( engine, "Planed", "double", "d", useNamespaces );
		registerCinderPolyLineType<Vec2f>( engine, "PolyLine2f", "Vec2f", "f", useNamespaces );
		registerCinderPolyLineType<Vec2d>( engine, "PolyLine2d", "Vec2d", "d", useNamespaces );
		registerCinderPolyLineType<Vec3f>( engine, "PolyLine3f", "Vec3f", "f", useNamespaces );
		registerCinderQuaternionType<float>( engine, "Quatf", "float", "f", useNamespaces );
		registerCinderQuaternionType<double>( engine, "Quatd", "double", "d", useNamespaces );
		registerCinderRandType( engine, useNamespaces );
		registerCinderRayType( engine, useNamespaces );
		registerCinderRectTType<float>( engine, "Rectf", "float", "f", useNamespaces );
		registerCinderRectTType<double>( engine, "Rectd", "double", "d", useNamespaces );
		registerCinderRectMappingType( engine, useNamespaces );
		registerCinderShape2dType( engine, useNamespaces );
		registerCinderSphereType( engine, useNamespaces );
		registerCinderSurfaceTType<uint8_t>( engine, "Surface", "uint8", "", useNamespaces );
		registerCinderSurfaceTType<float>( engine, "Surface32f", "float", "f", useNamespaces );
		registerCinderTextLayoutType( engine, useNamespaces );
		registerCinderTextBoxType( engine, useNamespaces );
		registerCinderTimerType( engine, useNamespaces );
		registerCinderTriangulatorType( engine, useNamespaces );
		registerCinderTriMeshType( engine, useNamespaces );
		registerCinderTriMesh2dType( engine, useNamespaces );
		registerCinderVec2Type<int>( engine, "Vec2i", "int", "i", useNamespaces );
		registerCinderVec2Type<float>( engine, "Vec2f", "float", "f", useNamespaces );
		registerCinderVec2Type<double>( engine, "Vec2d", "double", "d", useNamespaces );
		registerCinderVec3Type<int>( engine, "Vec3i", "int", "i", useNamespaces );
		registerCinderVec3Type<float>( engine, "Vec3f", "float", "f", useNamespaces );
		registerCinderVec3Type<double>( engine, "Vec3d", "double", "d", useNamespaces );
		registerCinderVec4Type<int>( engine, "Vec4i", "int", "i", useNamespaces );
		registerCinderVec4Type<float>( engine, "Vec4f", "float", "f", useNamespaces );
		registerCinderVec4Type<double>( engine, "Vec4d", "double", "d", useNamespaces );
        
		registerCinderFileDropEventType( engine, useNamespaces );
		registerCinderKeyEventType( engine, useNamespaces );
		registerCinderMouseEventType( engine, useNamespaces );
        
		registerCinderDisplayListType( engine, useNamespaces );
		registerCinderRenderbufferType( engine, useNamespaces );
		registerCinderFboFormatType( engine, useNamespaces );
		registerCinderFboType( engine, useNamespaces );
		registerCinderGlslProgType( engine, useNamespaces );
		registerCinderTextureFormatType( engine, useNamespaces );
		registerCinderTextureType( engine, useNamespaces );
		registerCinderVboType( engine, useNamespaces );
		registerCinderVboMeshLayoutType( engine, useNamespaces );
		//registerCinderVboMeshVertexIterType( engine, useNamespaces );
		registerCinderVboMeshType( engine, useNamespaces );

        
        
        
        
		// and their respective implementations only after
		registerCinderArcballImpl( engine, useNamespaces );
		registerCinderAreaImpl( engine, useNamespaces );
		registerCinderAxisAlignedBox3fImpl( engine, useNamespaces );
		registerCinderBSplineImpl<Vec2f>( engine, "BSpline2f", "Vec2f", "f", useNamespaces );
		registerCinderBSplineImpl<Vec3f>( engine, "BSpline3f", "Vec3f", "f", useNamespaces );
		registerCinderCameraImpl( engine, useNamespaces );
		registerCinderCameraPerspImpl( engine, useNamespaces );
		registerCinderCameraOrthoImpl( engine, useNamespaces );
		registerCinderCameraStereoImpl( engine, useNamespaces );
		registerCinderChannelTImpl<uint8_t>( engine, "Channel", "uint8", "", useNamespaces );
		registerCinderChannelTImpl<float>( engine, "Channel32f", "float", "f", useNamespaces );
		registerCinderClipboardImpl( engine, useNamespaces );
		registerCinderColorTImpl<float>( engine, "Color", "float", "f", useNamespaces );
		registerCinderColorATImpl<float>( engine, "ColorA", "float", "f", useNamespaces );
		registerCinderFontImpl( engine, useNamespaces );
		registerCinderFrustumImpl<float>( engine, "Frustumf", "float", "f", useNamespaces );
		registerCinderFrustumImpl<double>( engine, "Frustumd", "double", "d", useNamespaces );
		registerCinderMatrix22Impl<float>( engine, "Matrix22f", "float", "f", useNamespaces );
		registerCinderMatrix22Impl<double>( engine, "Matrix22d", "double", "d", useNamespaces );
		registerCinderMatrix33Impl<float>( engine, "Matrix33f", "float", "f", useNamespaces );
		registerCinderMatrix33Impl<double>( engine, "Matrix33d", "double", "d", useNamespaces );
		registerCinderMatrix44Impl<float>( engine, "Matrix44f", "float", "f", useNamespaces );
		registerCinderMatrix44Impl<double>( engine, "Matrix44d", "double", "d", useNamespaces );
		registerCinderMatrixAffine2Impl<float>( engine, "MatrixAffine2f", "float", "f", useNamespaces );
		registerCinderMatrixAffine2Impl<double>( engine, "MatrixAffine2d", "double", "d", useNamespaces );
		registerCinderMayaCamUIImpl( engine, useNamespaces );
		//registerCinderObjLoaderImpl( engine, useNamespaces );
		registerCinderPath2dImpl( engine, useNamespaces );
		registerCinderPerlinImpl( engine, useNamespaces );
		registerCinderPlaneImpl<float>( engine, "Planef", "float", "f", useNamespaces );
		registerCinderPlaneImpl<double>( engine, "Planed", "double", "d", useNamespaces );
		registerCinderPolyLineImpl<Vec2f>( engine, "PolyLine2f", "Vec2f", "f", useNamespaces );
		registerCinderPolyLineImpl<Vec2d>( engine, "PolyLine2d", "Vec2d", "d", useNamespaces );
		registerCinderPolyLineImpl<Vec3f>( engine, "PolyLine3f", "Vec3f", "f", useNamespaces );
		registerCinderQuaternionImpl<float>( engine, "Quatf", "float", "f", useNamespaces );
		registerCinderQuaternionImpl<double>( engine, "Quatd", "double", "d", useNamespaces );
		registerCinderRandImpl( engine, useNamespaces );
		registerCinderRayImpl( engine, useNamespaces );
		registerCinderRectTImpl<float>( engine, "Rectf", "float", "f", useNamespaces );
		registerCinderRectTImpl<double>( engine, "Rectd", "double", "d", useNamespaces );
		registerCinderRectMappingImpl( engine, useNamespaces );
		registerCinderShape2dImpl( engine, useNamespaces );
		registerCinderSphereImpl( engine, useNamespaces );
		registerCinderSurfaceTImpl<uint8_t>( engine, "Surface", "uint8", "", useNamespaces );
		registerCinderSurfaceTImpl<float>( engine, "Surface32f", "float", "f", useNamespaces );
		registerCinderTextLayoutImpl( engine, useNamespaces );
		registerCinderTextBoxImpl( engine, useNamespaces );
		registerCinderTimerImpl( engine, useNamespaces );
		registerCinderTriangulatorImpl( engine, useNamespaces );
		registerCinderTriMeshImpl( engine, useNamespaces );
		registerCinderTriMesh2dImpl( engine, useNamespaces );
		registerCinderVec2Impl<int>( engine, "Vec2i", "int", "i", useNamespaces );
		registerCinderVec2Impl<float>( engine, "Vec2f", "float", "f", useNamespaces );
		registerCinderVec2Impl<double>( engine, "Vec2d", "double", "d", useNamespaces );
		registerCinderVec3Impl<int>( engine, "Vec3i", "int", "i", useNamespaces );
		registerCinderVec3Impl<float>( engine, "Vec3f", "float", "f", useNamespaces );
		registerCinderVec3Impl<double>( engine, "Vec3d", "double", "d", useNamespaces );
		registerCinderVec4Impl<int>( engine, "Vec4i", "int", "i", useNamespaces );
		registerCinderVec4Impl<float>( engine, "Vec4f", "float", "f", useNamespaces );
		registerCinderVec4Impl<double>( engine, "Vec4d", "double", "d", useNamespaces );
        
		registerCinderFileDropEventImpl( engine, useNamespaces );
		registerCinderKeyEventImpl( engine, useNamespaces );
		registerCinderMouseEventImpl( engine, useNamespaces );
        
		registerCinderDisplayListImpl( engine, useNamespaces );
		registerCinderRenderbufferImpl( engine, useNamespaces );
		registerCinderFboFormatImpl( engine, useNamespaces );
		registerCinderFboImpl( engine, useNamespaces );
		registerCinderGlslProgImpl( engine, useNamespaces );
		registerCinderTextureFormatImpl( engine, useNamespaces );
		registerCinderTextureImpl( engine, useNamespaces );
		registerCinderVboImpl( engine, useNamespaces );
		registerCinderVboMeshLayoutImpl( engine, useNamespaces );
		//registerCinderVboMeshVertexIterImpl( engine, useNamespaces );
		registerCinderVboMeshImpl( engine, useNamespaces );
        
        registerCinderGl( engine, useNamespaces );
        
        registerCinderImageIoImpl( engine, useNamespaces );
        
        
        int r = engine->RegisterObjectBehaviour( "Vec2f", asBEHAVE_IMPLICIT_VALUE_CAST, "Vec2i f() const", asFUNCTION((RegistrationHelper::cast<Vec2f,Vec2i>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
        r = engine->RegisterObjectBehaviour( "Vec2i", asBEHAVE_IMPLICIT_VALUE_CAST, "Vec2f f() const", asFUNCTION((RegistrationHelper::cast<Vec2i,Vec2f>)), asCALL_CDECL_OBJLAST); assert( r >= 0 );
	}

}
