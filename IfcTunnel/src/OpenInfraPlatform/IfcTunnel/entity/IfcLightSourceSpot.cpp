/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcColourRgb.h"
#include "include/IfcDirection.h"
#include "include/IfcLabel.h"
#include "include/IfcLightSourceSpot.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPositivePlaneAngleMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcReal.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcLightSourceSpot 
		IfcLightSourceSpot::IfcLightSourceSpot() { m_entity_enum = IFCLIGHTSOURCESPOT; }
		IfcLightSourceSpot::IfcLightSourceSpot( int id ) { m_id = id; m_entity_enum = IFCLIGHTSOURCESPOT; }
		IfcLightSourceSpot::~IfcLightSourceSpot() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLightSourceSpot::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcLightSourceSpot> other = dynamic_pointer_cast<IfcLightSourceSpot>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_LightColour = other->m_LightColour;
			m_AmbientIntensity = other->m_AmbientIntensity;
			m_Intensity = other->m_Intensity;
			m_Position = other->m_Position;
			m_Radius = other->m_Radius;
			m_ConstantAttenuation = other->m_ConstantAttenuation;
			m_DistanceAttenuation = other->m_DistanceAttenuation;
			m_QuadricAttenuation = other->m_QuadricAttenuation;
			m_Orientation = other->m_Orientation;
			m_ConcentrationExponent = other->m_ConcentrationExponent;
			m_SpreadAngle = other->m_SpreadAngle;
			m_BeamWidthAngle = other->m_BeamWidthAngle;
		}
		void IfcLightSourceSpot::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIGHTSOURCESPOT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LightColour ) { stream << "#" << m_LightColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AmbientIntensity ) { m_AmbientIntensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Intensity ) { m_Intensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Radius ) { m_Radius->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConstantAttenuation ) { m_ConstantAttenuation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DistanceAttenuation ) { m_DistanceAttenuation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_QuadricAttenuation ) { m_QuadricAttenuation->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Orientation ) { stream << "#" << m_Orientation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ConcentrationExponent ) { m_ConcentrationExponent->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SpreadAngle ) { m_SpreadAngle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BeamWidthAngle ) { m_BeamWidthAngle->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLightSourceSpot::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLightSourceSpot::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<13 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLightSourceSpot, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>13 ){ std::cout << "Wrong parameter count for entity IfcLightSourceSpot, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_LightColour, map );
			m_AmbientIntensity = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_Intensity = IfcNormalisedRatioMeasure::readStepData( args[3] );
			readEntityReference( args[4], m_Position, map );
			m_Radius = IfcPositiveLengthMeasure::readStepData( args[5] );
			m_ConstantAttenuation = IfcReal::readStepData( args[6] );
			m_DistanceAttenuation = IfcReal::readStepData( args[7] );
			m_QuadricAttenuation = IfcReal::readStepData( args[8] );
			readEntityReference( args[9], m_Orientation, map );
			m_ConcentrationExponent = IfcReal::readStepData( args[10] );
			m_SpreadAngle = IfcPositivePlaneAngleMeasure::readStepData( args[11] );
			m_BeamWidthAngle = IfcPositivePlaneAngleMeasure::readStepData( args[12] );
		}
		void IfcLightSourceSpot::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcLightSourcePositional::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLightSourceSpot::unlinkSelf()
		{
			IfcLightSourcePositional::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
