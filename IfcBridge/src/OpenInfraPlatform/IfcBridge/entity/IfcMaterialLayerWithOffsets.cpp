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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcLayerSetDirectionEnum.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcLogical.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialLayerSet.h"
#include "include/IfcMaterialLayerWithOffsets.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcNonNegativeLengthMeasure.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcMaterialLayerWithOffsets 
		IfcMaterialLayerWithOffsets::IfcMaterialLayerWithOffsets() { m_entity_enum = IFCMATERIALLAYERWITHOFFSETS; }
		IfcMaterialLayerWithOffsets::IfcMaterialLayerWithOffsets( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYERWITHOFFSETS; }
		IfcMaterialLayerWithOffsets::~IfcMaterialLayerWithOffsets() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialLayerWithOffsets::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcMaterialLayerWithOffsets> other = dynamic_pointer_cast<IfcMaterialLayerWithOffsets>(other_entity);
			if( !other) { return; }
			m_Material = other->m_Material;
			m_LayerThickness = other->m_LayerThickness;
			m_IsVentilated = other->m_IsVentilated;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Category = other->m_Category;
			m_Priority = other->m_Priority;
			m_OffsetDirection = other->m_OffsetDirection;
			m_OffsetValues = other->m_OffsetValues;
		}
		void IfcMaterialLayerWithOffsets::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLAYERWITHOFFSETS" << "(";
			if( m_Material ) { stream << "#" << m_Material->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LayerThickness ) { m_LayerThickness->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_IsVentilated ) { m_IsVentilated->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Priority ) { m_Priority->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OffsetDirection ) { m_OffsetDirection->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList( stream, m_OffsetValues );
			stream << ");";
		}
		void IfcMaterialLayerWithOffsets::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialLayerWithOffsets::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialLayerWithOffsets, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcMaterialLayerWithOffsets, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Material, map );
			m_LayerThickness = IfcNonNegativeLengthMeasure::readStepData( args[1] );
			m_IsVentilated = IfcLogical::readStepData( args[2] );
			m_Name = IfcLabel::readStepData( args[3] );
			m_Description = IfcText::readStepData( args[4] );
			m_Category = IfcLabel::readStepData( args[5] );
			m_Priority = IfcNormalisedRatioMeasure::readStepData( args[6] );
			m_OffsetDirection = IfcLayerSetDirectionEnum::readStepData( args[7] );
			readTypeOfRealList( args[8], m_OffsetValues );
		}
		void IfcMaterialLayerWithOffsets::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcMaterialLayer::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterialLayerWithOffsets::unlinkSelf()
		{
			IfcMaterialLayer::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
