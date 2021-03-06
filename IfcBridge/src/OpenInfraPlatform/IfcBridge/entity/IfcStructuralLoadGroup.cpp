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
#include "include/IfcActionSourceTypeEnum.h"
#include "include/IfcActionTypeEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcLoadGroupTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRatioMeasure.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToGroup.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcStructuralAnalysisModel.h"
#include "include/IfcStructuralLoadGroup.h"
#include "include/IfcStructuralResultGroup.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcStructuralLoadGroup 
		IfcStructuralLoadGroup::IfcStructuralLoadGroup() { m_entity_enum = IFCSTRUCTURALLOADGROUP; }
		IfcStructuralLoadGroup::IfcStructuralLoadGroup( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADGROUP; }
		IfcStructuralLoadGroup::~IfcStructuralLoadGroup() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadGroup::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcStructuralLoadGroup> other = dynamic_pointer_cast<IfcStructuralLoadGroup>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_PredefinedType = other->m_PredefinedType;
			m_ActionType = other->m_ActionType;
			m_ActionSource = other->m_ActionSource;
			m_Coefficient = other->m_Coefficient;
			m_Purpose = other->m_Purpose;
		}
		void IfcStructuralLoadGroup::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADGROUP" << "(";
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
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActionType ) { m_ActionType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActionSource ) { m_ActionSource->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Coefficient ) { m_Coefficient->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Purpose ) { m_Purpose->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadGroup::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadGroup::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadGroup, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadGroup, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			m_PredefinedType = IfcLoadGroupTypeEnum::readStepData( args[5] );
			m_ActionType = IfcActionTypeEnum::readStepData( args[6] );
			m_ActionSource = IfcActionSourceTypeEnum::readStepData( args[7] );
			m_Coefficient = IfcRatioMeasure::readStepData( args[8] );
			m_Purpose = IfcLabel::readStepData( args[9] );
		}
		void IfcStructuralLoadGroup::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGroup::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadGroup::unlinkSelf()
		{
			IfcGroup::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
