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
#include "include/IfcConnectionGeometry.h"
#include "include/IfcElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcInternalOrExternalEnum.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPhysicalOrVirtualEnum.h"
#include "include/IfcRelSpaceBoundary1stLevel.h"
#include "include/IfcSpaceBoundarySelect.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcRelSpaceBoundary1stLevel 
		IfcRelSpaceBoundary1stLevel::IfcRelSpaceBoundary1stLevel() { m_entity_enum = IFCRELSPACEBOUNDARY1STLEVEL; }
		IfcRelSpaceBoundary1stLevel::IfcRelSpaceBoundary1stLevel( int id ) { m_id = id; m_entity_enum = IFCRELSPACEBOUNDARY1STLEVEL; }
		IfcRelSpaceBoundary1stLevel::~IfcRelSpaceBoundary1stLevel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelSpaceBoundary1stLevel::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcRelSpaceBoundary1stLevel> other = dynamic_pointer_cast<IfcRelSpaceBoundary1stLevel>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingSpace = other->m_RelatingSpace;
			m_RelatedBuildingElement = other->m_RelatedBuildingElement;
			m_ConnectionGeometry = other->m_ConnectionGeometry;
			m_PhysicalOrVirtualBoundary = other->m_PhysicalOrVirtualBoundary;
			m_InternalOrExternalBoundary = other->m_InternalOrExternalBoundary;
			m_ParentBoundary = other->m_ParentBoundary;
		}
		void IfcRelSpaceBoundary1stLevel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELSPACEBOUNDARY1STLEVEL" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingSpace ) { m_RelatingSpace->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedBuildingElement ) { stream << "#" << m_RelatedBuildingElement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ConnectionGeometry ) { stream << "#" << m_ConnectionGeometry->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PhysicalOrVirtualBoundary ) { m_PhysicalOrVirtualBoundary->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InternalOrExternalBoundary ) { m_InternalOrExternalBoundary->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ParentBoundary ) { stream << "#" << m_ParentBoundary->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelSpaceBoundary1stLevel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelSpaceBoundary1stLevel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelSpaceBoundary1stLevel, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcRelSpaceBoundary1stLevel, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_RelatingSpace = IfcSpaceBoundarySelect::readStepData( args[4], map );
			readEntityReference( args[5], m_RelatedBuildingElement, map );
			readEntityReference( args[6], m_ConnectionGeometry, map );
			m_PhysicalOrVirtualBoundary = IfcPhysicalOrVirtualEnum::readStepData( args[7] );
			m_InternalOrExternalBoundary = IfcInternalOrExternalEnum::readStepData( args[8] );
			readEntityReference( args[9], m_ParentBoundary, map );
		}
		void IfcRelSpaceBoundary1stLevel::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcRelSpaceBoundary::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelSpaceBoundary1stLevel> ptr_self = dynamic_pointer_cast<IfcRelSpaceBoundary1stLevel>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcRelSpaceBoundary1stLevel::setInverseCounterparts: type mismatch" ); }
			if( m_ParentBoundary )
			{
				m_ParentBoundary->m_InnerBoundaries_inverse.push_back( ptr_self );
			}
		}
		void IfcRelSpaceBoundary1stLevel::unlinkSelf()
		{
			IfcRelSpaceBoundary::unlinkSelf();
			if( m_ParentBoundary )
			{
				std::vector<weak_ptr<IfcRelSpaceBoundary1stLevel> >& InnerBoundaries_inverse = m_ParentBoundary->m_InnerBoundaries_inverse;
				std::vector<weak_ptr<IfcRelSpaceBoundary1stLevel> >::iterator it_InnerBoundaries_inverse;
				for( it_InnerBoundaries_inverse = InnerBoundaries_inverse.begin(); it_InnerBoundaries_inverse != InnerBoundaries_inverse.end(); ++it_InnerBoundaries_inverse)
				{
					shared_ptr<IfcRelSpaceBoundary1stLevel> self_candidate( *it_InnerBoundaries_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						InnerBoundaries_inverse.erase( it_InnerBoundaries_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
