/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBuilding.h"
#include "include/IfcElementCompositionEnum.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcPostalAddress.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAggregates.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelContainedInSpatialStructure.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByObject.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByType.h"
#include "include/IfcRelNests.h"
#include "include/IfcRelReferencedInSpatialStructure.h"
#include "include/IfcRelServicesBuildings.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcBuilding 
		IfcBuilding::IfcBuilding() { m_entity_enum = IFCBUILDING; }
		IfcBuilding::IfcBuilding( int id ) { m_id = id; m_entity_enum = IFCBUILDING; }
		IfcBuilding::~IfcBuilding() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBuilding::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcBuilding> other = dynamic_pointer_cast<IfcBuilding>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_LongName = other->m_LongName;
			m_CompositionType = other->m_CompositionType;
			m_ElevationOfRefHeight = other->m_ElevationOfRefHeight;
			m_ElevationOfTerrain = other->m_ElevationOfTerrain;
			m_BuildingAddress = other->m_BuildingAddress;
		}
		void IfcBuilding::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBUILDING" << "(";
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
			if( m_ObjectPlacement ) { stream << "#" << m_ObjectPlacement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Representation ) { stream << "#" << m_Representation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LongName ) { m_LongName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CompositionType ) { m_CompositionType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ElevationOfRefHeight ) { m_ElevationOfRefHeight->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ElevationOfTerrain ) { m_ElevationOfTerrain->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_BuildingAddress ) { stream << "#" << m_BuildingAddress->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBuilding::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBuilding::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<12 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBuilding, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>12 ){ std::cout << "Wrong parameter count for entity IfcBuilding, expecting 12, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_LongName = IfcLabel::readStepData( args[7] );
			m_CompositionType = IfcElementCompositionEnum::readStepData( args[8] );
			m_ElevationOfRefHeight = IfcLengthMeasure::readStepData( args[9] );
			m_ElevationOfTerrain = IfcLengthMeasure::readStepData( args[10] );
			readEntityReference( args[11], m_BuildingAddress, map );
		}
		void IfcBuilding::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcSpatialStructureElement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBuilding::unlinkSelf()
		{
			IfcSpatialStructureElement::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform