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
#include "include/IfcAxis2Placement.h"
#include "include/IfcLocalPlacement.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcProduct.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcLocalPlacement 
		IfcLocalPlacement::IfcLocalPlacement() { m_entity_enum = IFCLOCALPLACEMENT; }
		IfcLocalPlacement::IfcLocalPlacement( int id ) { m_id = id; m_entity_enum = IFCLOCALPLACEMENT; }
		IfcLocalPlacement::~IfcLocalPlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLocalPlacement::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcLocalPlacement> other = dynamic_pointer_cast<IfcLocalPlacement>(other_entity);
			if( !other) { return; }
			m_PlacementRelTo = other->m_PlacementRelTo;
			m_RelativePlacement = other->m_RelativePlacement;
		}
		void IfcLocalPlacement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLOCALPLACEMENT" << "(";
			if( m_PlacementRelTo ) { stream << "#" << m_PlacementRelTo->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelativePlacement ) { m_RelativePlacement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLocalPlacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLocalPlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLocalPlacement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcLocalPlacement, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_PlacementRelTo, map );
			m_RelativePlacement = IfcAxis2Placement::readStepData( args[1], map );
		}
		void IfcLocalPlacement::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcObjectPlacement::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcLocalPlacement> ptr_self = dynamic_pointer_cast<IfcLocalPlacement>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcLocalPlacement::setInverseCounterparts: type mismatch" ); }
			if( m_PlacementRelTo )
			{
				m_PlacementRelTo->m_ReferencedByPlacements_inverse.push_back( ptr_self );
			}
		}
		void IfcLocalPlacement::unlinkSelf()
		{
			IfcObjectPlacement::unlinkSelf();
			if( m_PlacementRelTo )
			{
				std::vector<weak_ptr<IfcLocalPlacement> >& ReferencedByPlacements_inverse = m_PlacementRelTo->m_ReferencedByPlacements_inverse;
				std::vector<weak_ptr<IfcLocalPlacement> >::iterator it_ReferencedByPlacements_inverse;
				for( it_ReferencedByPlacements_inverse = ReferencedByPlacements_inverse.begin(); it_ReferencedByPlacements_inverse != ReferencedByPlacements_inverse.end(); ++it_ReferencedByPlacements_inverse)
				{
					shared_ptr<IfcLocalPlacement> self_candidate( *it_ReferencedByPlacements_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ReferencedByPlacements_inverse.erase( it_ReferencedByPlacements_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
