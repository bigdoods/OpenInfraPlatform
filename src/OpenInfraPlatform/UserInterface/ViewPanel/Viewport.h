/*! \verbatim
 *  \copyright		Copyright (c) 2015 Julian Amann. All rights reserved.
 *	\author			Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
 *	\brief			This file is part of the BlueFramework.
 *	\endverbatim
 */

#pragma once
#ifndef Blueform_UserInterface_Viewport_fbfab9db_0e02_4e25_a393_88c65a2ab542_h
#define Blueform_UserInterface_Viewport_fbfab9db_0e02_4e25_a393_88c65a2ab542_h

#include "../../../BlueFramework/GraphicsEngine/BlueMap.h"
#include "eView.h"
#include "Hud.h"
#include "OpenInfraPlatform/UserInterface/ViewPanel/RoadDesignVCP.h"
#include "OpenInfraPlatform/UserInterface/ViewPanel/RoadDesignVCL.h"
#include "OpenInfraPlatform/Infrastructure/Alignment/AlignmentModel.h"
#include "BlueFramework/Engine/ViewCube/ViewCube.h"
#include "BlueFramework/Engine/Camera/InfraCamera.h"
#include "BlueFramework/Engine/Camera/InfraCameraController.h"
#include "BlueFramework/Engine/Camera/SpectatorCamera.h"
#include "BlueFramework/Rasterizer/IRenderSystem.h"
#include "OpenInfraPlatform/IfcGeometryConverter/ConverterBuw.h"
#include <QWidget>
#include <QMouseEvent>
#include "OpenInfraPlatform/UserInterface/ViewPanel/Tool.h"
#include "OpenInfraPlatform/DataManagement/Data.h"

namespace OpenInfraPlatform
{
	namespace UserInterface
	{
		class Viewport : public QWidget
		{
			Q_OBJECT;

			typedef DataManagement::ChangeFlag ChangeFlag;

		public:			
			//---------------------------------------------------------------------------//
			// Events
			//---------------------------------------------------------------------------//

			boost::signals2::signal<void(buw::eViewCubeOrientation::Enum)> ViewCubeSelectionChanged;

		public:
			Viewport(const buw::renderWindowsDescription& rwd, QWidget* parent = 0);

			virtual ~Viewport();

			//! Draws the scene.
			void	paintEvent(QPaintEvent *);

			QPaintEngine* paintEngine() const;

			void	resizeEvent(QResizeEvent *);

			void	onChange();
			void	onChange(ChangeFlag changeFlag);
			void	onClear();

			void	forceRepaint();
			void    startContinuousRendering();
			void	stopContinuousRendering();
			
			eView	getView() const;
			void	setView(eView val);

			void	showCrossSection(const bool showCrossSection);
			void	showDesignCrossSection( const bool showDesignCrossSection );
			void	connectCrossSections(const bool connectCrossSections);
			void	doSolidCrossSections(const bool solidCrossSections);
			void	drawRoadTexture(const bool drawRoadTexture);

			void	enableCreatePoints( bool checked );

			std::vector<buw::vector3d> getAlignmentPoints();

			buw::vector3d	getOffset() const;

			void reloadShader();

			void storeGBuffer();

			// Quick hack for imporing bridge models
			bool bBridgeLoaded = false;
			void LoadBridge();

			void RenderBridge();

			//---------------------------------------------------------------------------//
			// Alignment
			//---------------------------------------------------------------------------//

			void	setHighlightDifferentAlignmentElements( const bool enable );
			void	setHighlightSelectedAlignmentSegment( const bool enable );
			
			//---------------------------------------------------------------------------//
			// Terrain
			//---------------------------------------------------------------------------//

			void	setHideTerrain(const bool checked );
			bool	getDrawTerrainWireframe() const;
			void	setDrawTerrainWireframe(const bool enable);
			void	enableTerrainTextured(const bool checked );
			void	enableTerrainGradientRamp(const bool enable);
			void	enableIsoLines(const bool enable);

			//---------------------------------------------------------------------------//
			// LaserScan
			//---------------------------------------------------------------------------//
			
			void	setUseUniformPointColor(const bool useUniformColor);
			void	setUseUniformPointSize(const bool useUniformSize);
			void	setPointSize(const float size);

			//---------------------------------------------------------------------------//
			// BlueMaps
			//---------------------------------------------------------------------------//

			void enableBlueMap(const bool checked);
			void applyBlueMapProperties(const buw::PropertySet& ps);

			//---------------------------------------------------------------------------//
			// Clear
			//---------------------------------------------------------------------------//

			void	setClearColor(const buw::color3f& color);	
	
			//---------------------------------------------------------------------------//
			// Common
			//---------------------------------------------------------------------------//

			buw::vector2i getSize() const;

			void setProjectionType(const buw::eProjectionType::Enum type);

			void saveAsScreenshot( const std::string& filename );

			void showFrameTimes(const bool show);

			//---------------------------------------------------------------------------//
			// Control
			//---------------------------------------------------------------------------//
			void				viewDirection(const buw::vector3f& direction);
			void				repositionCameraTarget();

			void setInfraCameraController(buw::ReferenceCounted<buw::InfraCameraController> controller);
			buw::ReferenceCounted<buw::InfraCameraController> getInfraCameraController();

		public Q_SLOTS:

			void drawNextFrame();

		protected:
			void leaveEvent ( QEvent * );

			//! Receive mouse press events for the widget.
			void mousePressEvent(QMouseEvent *event);

			//! Receives wheel events for the widget.
			void wheelEvent(QWheelEvent  * event);
			
			void mouseMoveEvent(QMouseEvent *event);

			//! Called whenever a key is pressed.
			void keyPressEvent(QKeyEvent *event);

			//! Called whenever a key is released.
			void keyReleaseEvent(QKeyEvent *event);

			//! Receives mouse release events for the widget.
			/*
				\param[in] event	Contains parameters that describe a mouse event.
			*/
			void mouseReleaseEvent(QMouseEvent *event);

		private:		
			void			updateFrustumProjection();
			void			createGraphicResources();
			void			createSkyboxResources();
			void			createDigitalElevationModel();

			void			createAlignment();
			void			createAlignmentHorizontal(buw::ReferenceCounted<buw::AlignmentModel> alignmentModel);
			void			createAlignmentVertical(buw::ReferenceCounted<OpenInfraPlatform::Infrastructure::AlignmentModel> alignmentModel);
			void			createAlignmentThreeDimensional();
			void			createIfcGeometry(buw::ReferenceCounted<IfcGeometryConverter::IfcGeometryModel> ifcGeometryModel);
			void			createBoundingBoxes(buw::vector3d min, buw::vector3d max);

			void			createAlignmentThreeDimensional_CrossSection();

			void			generatePickRay(int sx, int sy, buw::vector3f& o_start, buw::vector3f& o_end);

			float			getAspectRatio() const;

			void			createRenderSystem(const buw::renderWindowsDescription& rwd);

			void			fillVertexCacheUIElements();

			void			drawTerrain();

			buw::vector3f	unproject(const buw::vector3f &point);
			buw::vector3f	screenToWorld(const float x, const float y, const float z/*=0.0f*/);
			void			pick(int sx, int sy, buw::vector3f& o_start, buw::vector3f& o_end);

			void			drawFullScreenQuad();

			void			createPickBufferRenderTarget();
			void			createDeferredRenderTargets();

			void			fillGBuffer();

			void			createCpuReadTexture();;

			buw::vector4f	getPickBufferColor(const int x, const int y);
			buw::vector4f	getGBufferColor(const int x, const int y);

			void			storePickBuffer();

			void			onViewCubeSelectionChanged(buw::eViewCubeOrientation::Enum state);

			// road body
			buw::matrix44d getGlobalRotationMatrixOnStation(
				buw::ReferenceCounted<buw::Alignment2DBased3D> alignment, 
				buw::Stationing station);

			void drawCrossSection(
				buw::ReferenceCounted<buw::Alignment2DBased3D> alignment,
				buw::ReferenceCounted<buw::CrossSectionStatic> cs, 
				buw::vector3d offsetViewArea);

			void drawRoadBodyBetweenStation(
				buw::ReferenceCounted<buw::Alignment2DBased3D> alignment, 
				buw::ReferenceCounted<buw::CrossSectionStatic> cs, 
				buw::ReferenceCounted<buw::CrossSectionStatic> nextCs, 
				buw::vector3d offsetViewArea);

		private:
			buw::ReferenceCounted<buw::SkinnedMesh>				mesh_;

			buw::ReferenceCounted<ToolManager>					toolManager_;

			int									selectedAlignmentIndex_;
			int									hoveredAlignmentIndex_;

			// ViewCube
			buw::ReferenceCounted<buw::ViewCube>					viewCube_;
			buw::ReferenceCounted<buw::IDepthStencilState>		ddsDisableDepthTest_;
			buw::ReferenceCounted<buw::IRasterizerState>          rsDefault_;
			buw::ReferenceCounted<buw::IRasterizerState>			rsCullBackFaces_;
			bool								bShowViewCube_;
			bool								bContinuousRendering_;


			buw::ReferenceCounted<buw::ITexture2D>				cpuReadTexture_;

			// PickBuffer
			buw::vector4f						pickColor;	// is updated by each mouse move event
			buw::vector4f						clearPickColor;
			buw::ReferenceCounted<buw::IRenderTargetTexture2D>	renderTargetPickBuffer_;


			// GBuffer
			buw::ReferenceCounted<buw::IShader>					gBufferShader_;
			buw::ReferenceCounted<buw::IRenderTargetTexture2D>	renderTargetGBuffer_;

			// LaserScan
			bool								bUseUniformPointColor_;
			bool								bUseUniformPointSize_;
			float								pointSize_;

			// BlueMap
			buw::ReferenceCounted<buw::BlueMap>					blueMap_;
			bool								enableBlueMap_;
			
			buw::ReferenceCounted<Hud>							hud_;
			static const bool					bShowHud = false;

			// Clear
			bool								gradientClear_;
			buw::ReferenceCounted<buw::IDepthStencilState>		dssDefault_;
			buw::ReferenceCounted<buw::IDepthStencilState>		ddsDisableDepthWrite_;
			buw::ReferenceCounted<buw::IShader>					shaderGradientQuad_;
			buw::color3f						clearColor_;

			bool								bHighlightDifferentAlignmentElements_;
			bool								bHighlightSelectedAlignmentSegment_;

			// alignment editor
			bool								bCreatePoints_;
			buw::ReferenceCounted<buw::RoadDesignVCL>				vertexCacheAlignmentEditorLine_;
			buw::ReferenceCounted<buw::RoadDesignVCP>				vertexCacheAlignmentEditorPoint_;
			std::vector<buw::vector3d>			alignmentEditorPoints_;

			buw::ReferenceCounted<buw::VertexCachePointT<buw::VertexPosition3Color3>>	vertexCachePointLaserScan_;
			buw::ReferenceCounted<buw::IShader>					shaderLaserScan_;

			eView								view_;
			buw::eProjectionType::Enum			projectionType_;
			
			buw::ReferenceCounted<buw::IRenderSystem>				renderSystem_;
			buw::ReferenceCounted<buw::IRenderContext>			renderContext_;

			buw::ReferenceCounted<buw::VertexCacheTriangle>		vertexCacheAlignmentTriangle_;
			buw::ReferenceCounted<buw::IShader>					triangleShader_;
			buw::ReferenceCounted<buw::RoadDesignVCL>				vertexCacheAlignmentLine_;
			buw::ReferenceCounted<buw::RoadDesignVCP>				vertexCacheAlignmentPoint_;

			buw::ReferenceCounted<buw::VertexCacheTriangleT<VertexLayout>> vertexCacheIfcGeometry_;
			buw::ReferenceCounted<buw::RoadDesignVCL>				vertexCacheIfcPolylines_;

			buw::ReferenceCounted<buw::VertexCacheLine>			vertexCacheLineUIElements;
			buw::ReferenceCounted<buw::VertexCachePoint>			vertexCachePointDebug_;
			buw::ReferenceCounted<buw::VertexCacheLine>			vertexCacheLineDebug_;
			
			std::vector<buw::ReferenceCounted<buw::VertexCacheLine>>	vertexCacheLineBreakLines_;

			buw::ReferenceCounted<buw::IRasterizerState>			rsSolidFill_;
			buw::ReferenceCounted<buw::IRasterizerState>			rsWireframeFill_;
			buw::ReferenceCounted<buw::ISamplerState>				sampler_;

			// DigitalElevationModel
			bool								bTerrainTextured_;
			bool								bTerrainUseColorRamp_;
			bool								bTerrainDisplayIsoLines_;
			buw::ReferenceCounted<buw::ITexture2D>				terrainTexture_;
			buw::ReferenceCounted<buw::ITexture1D>				gradientRampTexture_;
			bool								bHideTerrain_;
			bool								bDrawTerrainWireframe_;
			buw::vector2f						heightRange_;

			buw::ReferenceCounted<buw::ISamplerState>				colorRampSampler_;
			
			std::vector<buw::ReferenceCounted<buw::IndexedMesh>>	meshesDigitalElevationModel_;
			buw::ReferenceCounted<buw::IShader>					shaderDigitalElevationModel_;
			buw::ReferenceCounted<buw::IShader>					shaderDigitalElevationModelColorRamp_;
			buw::ReferenceCounted<buw::IVertexLayout>				vertexLayoutDigitalElevationModel_;

			//  Text
			buw::ReferenceCounted<buw::SignedDistanceFont>		signedDistanceFont_;
			buw::ReferenceCounted<buw::Text>						text_;

			//---------------------------------------------------------------------------//
			// Camera control
			//---------------------------------------------------------------------------//
			buw::ReferenceCounted<buw::InfraCamera>				infraCamera_;
			buw::ReferenceCounted<buw::InfraCameraController>		infraCameraController_;
			unsigned long						lastTick_;
			buw::vector2f						lastMousePos_;

			// Skybox
			bool								drawSkybox_;
			buw::ReferenceCounted<buw::Skybox>					skybox_;

			//---------------------------------------------------------------------------//
			// CrossSections
			//---------------------------------------------------------------------------//
			bool								showCrossSection_;
			bool								showDesignCrossSection_;
			bool								connectCrossSections_;
			bool								doSolidCrossSections_;
			bool								drawRoadTexture_;

			buw::ReferenceCounted<buw::ITexture2D>															roadTexture_;
			buw::ReferenceCounted<buw::VertexCacheTriangleT<buw::VertexPosition3Color3Normal3Texture2>>		triangleCacheP3C3N3UV2_;
			buw::ReferenceCounted<buw::IShader>																triangleShaderP3C3N3UV2_;

			//---------------------------------------------------------------------------//
			// Diagnostics
			//---------------------------------------------------------------------------//
			buw::Timer	performanceTimer_;
			double		lastPreFrame_;
			long long	frameTime_;
			long long	sinceLastFrame_;
			bool		bShowFrameTimes_;
		}; // end class Viewport
	} // end namespace UserInterface
} // end namespace OpenInfraPlatform

namespace buw
{
	using OpenInfraPlatform::UserInterface::eView;
	using OpenInfraPlatform::UserInterface::Viewport;
}

#endif // end define Blueform_UserInterface_Viewport_fbfab9db_0e02_4e25_a393_88c65a2ab542_h