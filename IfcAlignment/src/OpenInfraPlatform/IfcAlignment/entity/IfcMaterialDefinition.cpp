/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcMaterialDefinition.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcRelAssociatesMaterial.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcMaterialDefinition 
		IfcMaterialDefinition::IfcMaterialDefinition() { m_entity_enum = IFCMATERIALDEFINITION; }
		IfcMaterialDefinition::IfcMaterialDefinition( int id ) { m_id = id; m_entity_enum = IFCMATERIALDEFINITION; }
		IfcMaterialDefinition::~IfcMaterialDefinition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialDefinition::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcMaterialDefinition> other = dynamic_pointer_cast<IfcMaterialDefinition>(other_entity);
			if( !other) { return; }
		}
		void IfcMaterialDefinition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALDEFINITION" << "(";
			stream << ");";
		}
		void IfcMaterialDefinition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialDefinition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
		}
		void IfcMaterialDefinition::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcMaterialDefinition::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
