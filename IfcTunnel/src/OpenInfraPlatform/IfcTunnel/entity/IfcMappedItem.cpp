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
#include "include/IfcCartesianTransformationOperator.h"
#include "include/IfcMappedItem.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMappedItem 
		IfcMappedItem::IfcMappedItem() { m_entity_enum = IFCMAPPEDITEM; }
		IfcMappedItem::IfcMappedItem( int id ) { m_id = id; m_entity_enum = IFCMAPPEDITEM; }
		IfcMappedItem::~IfcMappedItem() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMappedItem::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcMappedItem> other = dynamic_pointer_cast<IfcMappedItem>(other_entity);
			if( !other) { return; }
			m_MappingSource = other->m_MappingSource;
			m_MappingTarget = other->m_MappingTarget;
		}
		void IfcMappedItem::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMAPPEDITEM" << "(";
			if( m_MappingSource ) { stream << "#" << m_MappingSource->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_MappingTarget ) { stream << "#" << m_MappingTarget->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMappedItem::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMappedItem::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMappedItem, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcMappedItem, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_MappingSource, map );
			readEntityReference( args[1], m_MappingTarget, map );
		}
		void IfcMappedItem::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcRepresentationItem::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcMappedItem> ptr_self = dynamic_pointer_cast<IfcMappedItem>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcMappedItem::setInverseCounterparts: type mismatch" ); }
			if( m_MappingSource )
			{
				m_MappingSource->m_MapUsage_inverse.push_back( ptr_self );
			}
		}
		void IfcMappedItem::unlinkSelf()
		{
			IfcRepresentationItem::unlinkSelf();
			if( m_MappingSource )
			{
				std::vector<weak_ptr<IfcMappedItem> >& MapUsage_inverse = m_MappingSource->m_MapUsage_inverse;
				std::vector<weak_ptr<IfcMappedItem> >::iterator it_MapUsage_inverse;
				for( it_MapUsage_inverse = MapUsage_inverse.begin(); it_MapUsage_inverse != MapUsage_inverse.end(); ++it_MapUsage_inverse)
				{
					shared_ptr<IfcMappedItem> self_candidate( *it_MapUsage_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						MapUsage_inverse.erase( it_MapUsage_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
