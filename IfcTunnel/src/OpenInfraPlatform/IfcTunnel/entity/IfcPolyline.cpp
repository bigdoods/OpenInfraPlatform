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
#include "include/IfcPolyline.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcPolyline 
		IfcPolyline::IfcPolyline() { m_entity_enum = IFCPOLYLINE; }
		IfcPolyline::IfcPolyline( int id ) { m_id = id; m_entity_enum = IFCPOLYLINE; }
		IfcPolyline::~IfcPolyline() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPolyline::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcPolyline> other = dynamic_pointer_cast<IfcPolyline>(other_entity);
			if( !other) { return; }
			m_Points = other->m_Points;
		}
		void IfcPolyline::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPOLYLINE" << "(";
			writeEntityList( stream, m_Points );
			stream << ");";
		}
		void IfcPolyline::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPolyline::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPolyline, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPolyline, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_Points, map );
		}
		void IfcPolyline::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcBoundedCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPolyline::unlinkSelf()
		{
			IfcBoundedCurve::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
