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
#include "include/IfcActorSelect.h"
#include "include/IfcCalendarDate.h"
#include "include/IfcCostValue.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcInventory.h"
#include "include/IfcInventoryTypeEnum.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPerson.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToGroup.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcInventory 
		IfcInventory::IfcInventory() { m_entity_enum = IFCINVENTORY; }
		IfcInventory::IfcInventory( int id ) { m_id = id; m_entity_enum = IFCINVENTORY; }
		IfcInventory::~IfcInventory() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcInventory::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcInventory> other = dynamic_pointer_cast<IfcInventory>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_InventoryType = other->m_InventoryType;
			m_Jurisdiction = other->m_Jurisdiction;
			m_ResponsiblePersons = other->m_ResponsiblePersons;
			m_LastUpdateDate = other->m_LastUpdateDate;
			m_CurrentValue = other->m_CurrentValue;
			m_OriginalValue = other->m_OriginalValue;
		}
		void IfcInventory::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCINVENTORY" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ObjectType ) { m_ObjectType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InventoryType ) { m_InventoryType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Jurisdiction ) { m_Jurisdiction->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_ResponsiblePersons );
			stream << ",";
			if( m_LastUpdateDate ) { stream << "#" << m_LastUpdateDate->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CurrentValue ) { stream << "#" << m_CurrentValue->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_OriginalValue ) { stream << "#" << m_OriginalValue->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcInventory::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcInventory::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<11 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcInventory, expecting 11, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>11 ){ std::cout << "Wrong parameter count for entity IfcInventory, expecting 11, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_InventoryType = IfcInventoryTypeEnum::readStepData( args[5] );
			m_Jurisdiction = IfcActorSelect::readStepData( args[6], map );
			readEntityReferenceList( args[7], m_ResponsiblePersons, map );
			readEntityReference( args[8], m_LastUpdateDate, map );
			readEntityReference( args[9], m_CurrentValue, map );
			readEntityReference( args[10], m_OriginalValue, map );
		}
		void IfcInventory::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcGroup::setInverseCounterparts( ptr_self_entity );
		}
		void IfcInventory::unlinkSelf()
		{
			IfcGroup::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
