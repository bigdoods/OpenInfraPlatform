/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterial.h"
#include "include/IfcMaterialDefinitionRepresentation.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcMaterialRelationship.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcMaterial 
		IfcMaterial::IfcMaterial() { m_entity_enum = IFCMATERIAL; }
		IfcMaterial::IfcMaterial( int id ) { m_id = id; m_entity_enum = IFCMATERIAL; }
		IfcMaterial::~IfcMaterial() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterial::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcMaterial> other = dynamic_pointer_cast<IfcMaterial>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_Category = other->m_Category;
		}
		void IfcMaterial::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIAL" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterial::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterial::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterial, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcMaterial, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_Category = IfcLabel::readStepData( args[2] );
		}
		void IfcMaterial::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcMaterialDefinition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcMaterial::unlinkSelf()
		{
			IfcMaterialDefinition::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform