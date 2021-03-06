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
#include "include/IfcAxis2Placement2D.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcDirection.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcAxis2Placement2D 
		IfcAxis2Placement2D::IfcAxis2Placement2D() { m_entity_enum = IFCAXIS2PLACEMENT2D; }
		IfcAxis2Placement2D::IfcAxis2Placement2D( int id ) { m_id = id; m_entity_enum = IFCAXIS2PLACEMENT2D; }
		IfcAxis2Placement2D::~IfcAxis2Placement2D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAxis2Placement2D::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcAxis2Placement2D> other = dynamic_pointer_cast<IfcAxis2Placement2D>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_RefDirection = other->m_RefDirection;
		}
		void IfcAxis2Placement2D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAXIS2PLACEMENT2D" << "(";
			if( m_Location ) { stream << "#" << m_Location->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RefDirection ) { stream << "#" << m_RefDirection->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAxis2Placement2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAxis2Placement2D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAxis2Placement2D, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcAxis2Placement2D, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Location, map );
			readEntityReference( args[1], m_RefDirection, map );
		}
		void IfcAxis2Placement2D::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcPlacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAxis2Placement2D::unlinkSelf()
		{
			IfcPlacement::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
