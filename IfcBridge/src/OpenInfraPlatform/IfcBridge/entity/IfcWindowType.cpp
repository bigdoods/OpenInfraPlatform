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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPropertySetDefinition.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcRepresentationMap.h"
#include "include/IfcText.h"
#include "include/IfcWindowType.h"
#include "include/IfcWindowTypeEnum.h"
#include "include/IfcWindowTypePartitioningEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcWindowType 
		IfcWindowType::IfcWindowType() { m_entity_enum = IFCWINDOWTYPE; }
		IfcWindowType::IfcWindowType( int id ) { m_id = id; m_entity_enum = IFCWINDOWTYPE; }
		IfcWindowType::~IfcWindowType() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcWindowType::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcWindowType> other = dynamic_pointer_cast<IfcWindowType>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ApplicableOccurrence = other->m_ApplicableOccurrence;
			m_HasPropertySets = other->m_HasPropertySets;
			m_RepresentationMaps = other->m_RepresentationMaps;
			m_Tag = other->m_Tag;
			m_ElementType = other->m_ElementType;
			m_PredefinedType = other->m_PredefinedType;
			m_PartitioningType = other->m_PartitioningType;
			m_ParameterTakesPrecedence = other->m_ParameterTakesPrecedence;
		}
		void IfcWindowType::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCWINDOWTYPE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicableOccurrence ) { m_ApplicableOccurrence->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_HasPropertySets );
			stream << ",";
			writeEntityList( stream, m_RepresentationMaps );
			stream << ",";
			if( m_Tag ) { m_Tag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ElementType ) { m_ElementType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_PartitioningType ) { m_PartitioningType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ParameterTakesPrecedence == false ) { stream << ".F."; }
			else if( m_ParameterTakesPrecedence == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcWindowType::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcWindowType::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcWindowType, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcWindowType, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ApplicableOccurrence = IfcIdentifier::readStepData( args[4] );
			readEntityReferenceList( args[5], m_HasPropertySets, map );
			readEntityReferenceList( args[6], m_RepresentationMaps, map );
			m_Tag = IfcLabel::readStepData( args[7] );
			m_ElementType = IfcLabel::readStepData( args[8] );
			m_PredefinedType = IfcWindowTypeEnum::readStepData( args[9] );
			m_PartitioningType = IfcWindowTypePartitioningEnum::readStepData( args[10] );
			if( _stricmp( args[11].c_str(), ".F." ) == 0 ) { m_ParameterTakesPrecedence = false; }
			else if( _stricmp( args[11].c_str(), ".T." ) == 0 ) { m_ParameterTakesPrecedence = true; }
		}
		void IfcWindowType::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcBuildingElementType::setInverseCounterparts( ptr_self_entity );
		}
		void IfcWindowType::unlinkSelf()
		{
			IfcBuildingElementType::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform