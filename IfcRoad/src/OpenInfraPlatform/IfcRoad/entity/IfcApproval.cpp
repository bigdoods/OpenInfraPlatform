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
#include "include/IfcActorSelect.h"
#include "include/IfcApproval.h"
#include "include/IfcApprovalRelationship.h"
#include "include/IfcDateTime.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcRelAssociatesApproval.h"
#include "include/IfcResourceApprovalRelationship.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcApproval 
		IfcApproval::IfcApproval() { m_entity_enum = IFCAPPROVAL; }
		IfcApproval::IfcApproval( int id ) { m_id = id; m_entity_enum = IFCAPPROVAL; }
		IfcApproval::~IfcApproval() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcApproval::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcApproval> other = dynamic_pointer_cast<IfcApproval>(other_entity);
			if( !other) { return; }
			m_Identifier = other->m_Identifier;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_TimeOfApproval = other->m_TimeOfApproval;
			m_Status = other->m_Status;
			m_Level = other->m_Level;
			m_Qualifier = other->m_Qualifier;
			m_RequestingApproval = other->m_RequestingApproval;
			m_GivingApproval = other->m_GivingApproval;
		}
		void IfcApproval::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPROVAL" << "(";
			if( m_Identifier ) { m_Identifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TimeOfApproval ) { m_TimeOfApproval->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Status ) { m_Status->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Level ) { m_Level->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Qualifier ) { m_Qualifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RequestingApproval ) { m_RequestingApproval->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_GivingApproval ) { m_GivingApproval->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcApproval::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcApproval::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<9 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcApproval, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>9 ){ std::cout << "Wrong parameter count for entity IfcApproval, expecting 9, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Identifier = IfcIdentifier::readStepData( args[0] );
			m_Name = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
			m_TimeOfApproval = IfcDateTime::readStepData( args[3] );
			m_Status = IfcLabel::readStepData( args[4] );
			m_Level = IfcLabel::readStepData( args[5] );
			m_Qualifier = IfcText::readStepData( args[6] );
			m_RequestingApproval = IfcActorSelect::readStepData( args[7], map );
			m_GivingApproval = IfcActorSelect::readStepData( args[8], map );
		}
		void IfcApproval::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcApproval::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
