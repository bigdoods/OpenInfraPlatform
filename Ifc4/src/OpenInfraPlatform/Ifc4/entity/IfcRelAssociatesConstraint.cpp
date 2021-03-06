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
#include "include/IfcConstraint.h"
#include "include/IfcDefinitionSelect.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssociatesConstraint.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRelAssociatesConstraint 
		IfcRelAssociatesConstraint::IfcRelAssociatesConstraint() { m_entity_enum = IFCRELASSOCIATESCONSTRAINT; }
		IfcRelAssociatesConstraint::IfcRelAssociatesConstraint( int id ) { m_id = id; m_entity_enum = IFCRELASSOCIATESCONSTRAINT; }
		IfcRelAssociatesConstraint::~IfcRelAssociatesConstraint() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssociatesConstraint::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRelAssociatesConstraint> other = dynamic_pointer_cast<IfcRelAssociatesConstraint>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_Intent = other->m_Intent;
			m_RelatingConstraint = other->m_RelatingConstraint;
		}
		void IfcRelAssociatesConstraint::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSOCIATESCONSTRAINT" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_RelatedObjects, true );
			stream << ",";
			if( m_Intent ) { m_Intent->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingConstraint ) { stream << "#" << m_RelatingConstraint->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssociatesConstraint::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssociatesConstraint::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssociatesConstraint, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRelAssociatesConstraint, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readSelectList( args[4], m_RelatedObjects, map );
			m_Intent = IfcLabel::readStepData( args[5] );
			readEntityReference( args[6], m_RelatingConstraint, map );
		}
		void IfcRelAssociatesConstraint::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcRelAssociates::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRelAssociatesConstraint::unlinkSelf()
		{
			IfcRelAssociates::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
