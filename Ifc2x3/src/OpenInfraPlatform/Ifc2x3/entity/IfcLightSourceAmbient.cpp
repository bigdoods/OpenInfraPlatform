/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcColourRgb.h"
#include "include/IfcLabel.h"
#include "include/IfcLightSourceAmbient.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcLightSourceAmbient 
		IfcLightSourceAmbient::IfcLightSourceAmbient() { m_entity_enum = IFCLIGHTSOURCEAMBIENT; }
		IfcLightSourceAmbient::IfcLightSourceAmbient( int id ) { m_id = id; m_entity_enum = IFCLIGHTSOURCEAMBIENT; }
		IfcLightSourceAmbient::~IfcLightSourceAmbient() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLightSourceAmbient::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcLightSourceAmbient> other = dynamic_pointer_cast<IfcLightSourceAmbient>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_LightColour = other->m_LightColour;
			m_AmbientIntensity = other->m_AmbientIntensity;
			m_Intensity = other->m_Intensity;
		}
		void IfcLightSourceAmbient::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIGHTSOURCEAMBIENT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LightColour ) { stream << "#" << m_LightColour->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AmbientIntensity ) { m_AmbientIntensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Intensity ) { m_Intensity->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLightSourceAmbient::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLightSourceAmbient::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLightSourceAmbient, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcLightSourceAmbient, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readEntityReference( args[1], m_LightColour, map );
			m_AmbientIntensity = IfcNormalisedRatioMeasure::readStepData( args[2] );
			m_Intensity = IfcNormalisedRatioMeasure::readStepData( args[3] );
		}
		void IfcLightSourceAmbient::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcLightSource::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLightSourceAmbient::unlinkSelf()
		{
			IfcLightSource::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
