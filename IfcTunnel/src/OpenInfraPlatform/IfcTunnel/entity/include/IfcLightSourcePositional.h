/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"
#include "IfcLightSource.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcCartesianPoint;
		class IfcPositiveLengthMeasure;
		class IfcReal;
		//ENTITY
		class IfcLightSourcePositional : public IfcLightSource
		{
		public:
			IfcLightSourcePositional();
			IfcLightSourcePositional( int id );
			~IfcLightSourcePositional();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLightSourcePositional"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcLightSource -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcColourRgb>						m_LightColour;
			//  shared_ptr<IfcNormalisedRatioMeasure>		m_AmbientIntensity;			//optional
			//  shared_ptr<IfcNormalisedRatioMeasure>		m_Intensity;				//optional

			// IfcLightSourcePositional -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCartesianPoint>				m_Position;
			shared_ptr<IfcPositiveLengthMeasure>			m_Radius;
			shared_ptr<IfcReal>							m_ConstantAttenuation;
			shared_ptr<IfcReal>							m_DistanceAttenuation;
			shared_ptr<IfcReal>							m_QuadricAttenuation;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

