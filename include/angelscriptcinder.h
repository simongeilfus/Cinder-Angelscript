#pragma once

#include <iostream>

class asIScriptEngine;

namespace as {

	void registerCinder( asIScriptEngine* engine, bool useNamespaces = false );
    
    // cinder

	//! Arcball.h
	void registerCinderArcballType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderArcballImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Area.h
	void registerCinderAreaType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderAreaImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! AxisAlignedBox.h
	void registerCinderAxisAlignedBox3fType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderAxisAlignedBox3fImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! BSpline.h
	template<typename T>
	void registerCinderBSplineType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderBSplineImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Camera.h
	void registerCinderCameraType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraPerspType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraPerspImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraOrthoType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraOrthoImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraStereoType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderCameraStereoImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Channel.h
	template<typename T>
	void registerCinderChannelTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderChannelTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Clipboard.h
	void registerCinderClipboardType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderClipboardImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Color.h
	template<typename T>
	void registerCinderColorTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderColorTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderColorATType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderColorATImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Easing.h


	//! Font.h
	void registerCinderFontType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderFontImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Frustum.h
	template<typename T>
	void registerCinderFrustumType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderFrustumImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Matrix22.h
	template<typename T>
	void registerCinderMatrix22Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderMatrix22Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Matrix33.h
	template<typename T>
	void registerCinderMatrix33Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderMatrix33Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Matrix44.h
	template<typename T>
	void registerCinderMatrix44Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderMatrix44Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! MatrixAffine2.h
	template<typename T>
	void registerCinderMatrixAffine2Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderMatrixAffine2Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! MayaCamUI.h
	void registerCinderMayaCamUIType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderMayaCamUIImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! ObjLoader.h
	void registerCinderObjLoaderType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderObjLoaderImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Path2d.h
	void registerCinderPath2dType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderPath2dImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Perlin.h
	void registerCinderPerlinType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderPerlinImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Plane.h
	template<typename T>
	void registerCinderPlaneType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderPlaneImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! PolyLine.h
	template<typename T>
	void registerCinderPolyLineType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderPolyLineImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Quaternion.h
	template<typename T>
	void registerCinderQuaternionType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderQuaternionImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Rand.h
	void registerCinderRandType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderRandImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Ray.h
	void registerCinderRayType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderRayImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Rect.h
	template<typename T>
	void registerCinderRectTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderRectTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	void registerCinderRectMappingType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderRectMappingImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Shape2d.h
	void registerCinderShape2dType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderShape2dImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Sphere.h
	void registerCinderSphereType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderSphereImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Surface.h
	template<typename T>
	void registerCinderSurfaceTType( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderSurfaceTImpl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );


	//! Text.h
	void registerCinderTextLayoutType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTextLayoutImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTextBoxType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTextBoxImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Timer.h
	void registerCinderTimerType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTimerImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Triangulate.h
	void registerCinderTriangulatorType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTriangulatorImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! TriMesh.h
	void registerCinderTriMeshType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTriMeshImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTriMesh2dType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTriMesh2dImpl( asIScriptEngine* engine, bool useNamespaces = false );


	//! Vector.h
	template<typename T>
	void registerCinderVec2Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderVec2Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderVec3Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderVec3Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderVec4Type( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );
	template<typename T>
	void registerCinderVec4Impl( asIScriptEngine* engine, const std::string &name, const std::string &type, const std::string &suffix = "", bool useNamespaces = false );

    
    // cinder/app/*
    
    
    
	//! FileDropEvent.h
	void registerCinderFileDropEventType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderFileDropEventImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
	//! KeyEvent.h
	void registerCinderKeyEventType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderKeyEventImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
	//! MouseEvent.h
	void registerCinderMouseEventType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderMouseEventImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
    // cinder/gl/*
    
    
	//! DisplayList.h
	void registerCinderDisplayListType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderDisplayListImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
	//! Fbo.h
	void registerCinderRenderbufferType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderRenderbufferImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderFboFormatType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderFboFormatImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderFboType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderFboImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
	//! GlslProg.h
	void registerCinderGlslProgType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderGlslProgImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
	//! Texture.h
	void registerCinderTextureFormatType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTextureFormatImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTextureType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderTextureImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    
	//! Vbo.h
	void registerCinderVboType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderVboImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderVboMeshLayoutType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderVboMeshLayoutImpl( asIScriptEngine* engine, bool useNamespaces = false );
	//void registerCinderVboMeshVertexIterType( asIScriptEngine* engine, bool useNamespaces = false );
	//void registerCinderVboMeshVertexIterImpl( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderVboMeshType( asIScriptEngine* engine, bool useNamespaces = false );
	void registerCinderVboMeshImpl( asIScriptEngine* engine, bool useNamespaces = false );

    
    
    
    void registerCinderImageIoImpl( asIScriptEngine* engine, bool useNamespaces = false );
    
    //! gl.h
    void registerCinderGl( asIScriptEngine* engine, bool useNamespaces = false );
}
