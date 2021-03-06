/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcControl.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcObjectTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssignsToControl.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcRelAssignsToControl 
		IfcRelAssignsToControl::IfcRelAssignsToControl() { m_entity_enum = IFCRELASSIGNSTOCONTROL; }
		IfcRelAssignsToControl::IfcRelAssignsToControl( int id ) { m_id = id; m_entity_enum = IFCRELASSIGNSTOCONTROL; }
		IfcRelAssignsToControl::~IfcRelAssignsToControl() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssignsToControl::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcRelAssignsToControl> other = dynamic_pointer_cast<IfcRelAssignsToControl>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatedObjectsType = other->m_RelatedObjectsType;
			m_RelatingControl = other->m_RelatingControl;
		}
		void IfcRelAssignsToControl::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSIGNSTOCONTROL" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedObjects );
			stream << ",";
			if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingControl ) { stream << "#" << m_RelatingControl->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssignsToControl::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssignsToControl::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssignsToControl, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRelAssignsToControl, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			m_RelatedObjectsType = IfcObjectTypeEnum::readStepData( args[5] );
			readEntityReference( args[6], m_RelatingControl, map );
		}
		void IfcRelAssignsToControl::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcRelAssigns::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssignsToControl> ptr_self = dynamic_pointer_cast<IfcRelAssignsToControl>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcRelAssignsToControl::setInverseCounterparts: type mismatch" ); }
			if( m_RelatingControl )
			{
				m_RelatingControl->m_Controls_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssignsToControl::unlinkSelf()
		{
			IfcRelAssigns::unlinkSelf();
			if( m_RelatingControl )
			{
				std::vector<weak_ptr<IfcRelAssignsToControl> >& Controls_inverse = m_RelatingControl->m_Controls_inverse;
				std::vector<weak_ptr<IfcRelAssignsToControl> >::iterator it_Controls_inverse;
				for( it_Controls_inverse = Controls_inverse.begin(); it_Controls_inverse != Controls_inverse.end(); ++it_Controls_inverse)
				{
					shared_ptr<IfcRelAssignsToControl> self_candidate( *it_Controls_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						Controls_inverse.erase( it_Controls_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
