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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRectangularPyramid.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcRectangularPyramid 
		IfcRectangularPyramid::IfcRectangularPyramid() { m_entity_enum = IFCRECTANGULARPYRAMID; }
		IfcRectangularPyramid::IfcRectangularPyramid( int id ) { m_id = id; m_entity_enum = IFCRECTANGULARPYRAMID; }
		IfcRectangularPyramid::~IfcRectangularPyramid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRectangularPyramid::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcRectangularPyramid> other = dynamic_pointer_cast<IfcRectangularPyramid>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
			m_XLength = other->m_XLength;
			m_YLength = other->m_YLength;
			m_Height = other->m_Height;
		}
		void IfcRectangularPyramid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRECTANGULARPYRAMID" << "(";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_XLength ) { m_XLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_YLength ) { m_YLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Height ) { m_Height->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRectangularPyramid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRectangularPyramid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRectangularPyramid, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcRectangularPyramid, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Position, map );
			m_XLength = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_YLength = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_Height = IfcPositiveLengthMeasure::readStepData( args[3] );
		}
		void IfcRectangularPyramid::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcCsgPrimitive3D::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRectangularPyramid::unlinkSelf()
		{
			IfcCsgPrimitive3D::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
