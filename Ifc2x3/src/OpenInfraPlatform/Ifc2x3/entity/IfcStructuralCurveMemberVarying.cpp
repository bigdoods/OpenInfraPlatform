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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectPlacement.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcProductRepresentation.h"
#include "include/IfcRelAssigns.h"
#include "include/IfcRelAssignsToProduct.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelConnectsStructuralActivity.h"
#include "include/IfcRelConnectsStructuralElement.h"
#include "include/IfcRelConnectsStructuralMember.h"
#include "include/IfcRelDecomposes.h"
#include "include/IfcRelDefines.h"
#include "include/IfcStructuralCurveMemberVarying.h"
#include "include/IfcStructuralCurveTypeEnum.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStructuralCurveMemberVarying 
		IfcStructuralCurveMemberVarying::IfcStructuralCurveMemberVarying() { m_entity_enum = IFCSTRUCTURALCURVEMEMBERVARYING; }
		IfcStructuralCurveMemberVarying::IfcStructuralCurveMemberVarying( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALCURVEMEMBERVARYING; }
		IfcStructuralCurveMemberVarying::~IfcStructuralCurveMemberVarying() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralCurveMemberVarying::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStructuralCurveMemberVarying> other = dynamic_pointer_cast<IfcStructuralCurveMemberVarying>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ObjectType = other->m_ObjectType;
			m_ObjectPlacement = other->m_ObjectPlacement;
			m_Representation = other->m_Representation;
			m_PredefinedType = other->m_PredefinedType;
		}
		void IfcStructuralCurveMemberVarying::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALCURVEMEMBERVARYING" << "(";
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
			if( m_PredefinedType ) { m_PredefinedType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralCurveMemberVarying::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralCurveMemberVarying::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralCurveMemberVarying, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcStructuralCurveMemberVarying, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			m_ObjectType = IfcLabel::readStepData( args[4] );
			readEntityReference( args[5], m_ObjectPlacement, map );
			readEntityReference( args[6], m_Representation, map );
			m_PredefinedType = IfcStructuralCurveTypeEnum::readStepData( args[7] );
		}
		void IfcStructuralCurveMemberVarying::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcStructuralCurveMember::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralCurveMemberVarying::unlinkSelf()
		{
			IfcStructuralCurveMember::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
