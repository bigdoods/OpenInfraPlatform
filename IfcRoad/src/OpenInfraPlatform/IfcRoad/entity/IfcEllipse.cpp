/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcAxis2Placement.h"
#include "include/IfcEllipse.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcEllipse 
		IfcEllipse::IfcEllipse() { m_entity_enum = IFCELLIPSE; }
		IfcEllipse::IfcEllipse( int id ) { m_id = id; m_entity_enum = IFCELLIPSE; }
		IfcEllipse::~IfcEllipse() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEllipse::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcEllipse> other = dynamic_pointer_cast<IfcEllipse>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
			m_SemiAxis1 = other->m_SemiAxis1;
			m_SemiAxis2 = other->m_SemiAxis2;
		}
		void IfcEllipse::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCELLIPSE" << "(";
			if( m_Position ) { m_Position->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_SemiAxis1 ) { m_SemiAxis1->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SemiAxis2 ) { m_SemiAxis2->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcEllipse::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEllipse::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEllipse, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcEllipse, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Position = IfcAxis2Placement::readStepData( args[0], map );
			m_SemiAxis1 = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_SemiAxis2 = IfcPositiveLengthMeasure::readStepData( args[2] );
		}
		void IfcEllipse::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcConic::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEllipse::unlinkSelf()
		{
			IfcConic::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
