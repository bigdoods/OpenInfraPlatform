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
#include "include/IfcAppliedValue.h"
#include "include/IfcAppliedValueSelect.h"
#include "include/IfcArithmeticOperatorEnum.h"
#include "include/IfcDate.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcAppliedValue 
		IfcAppliedValue::IfcAppliedValue() { m_entity_enum = IFCAPPLIEDVALUE; }
		IfcAppliedValue::IfcAppliedValue( int id ) { m_id = id; m_entity_enum = IFCAPPLIEDVALUE; }
		IfcAppliedValue::~IfcAppliedValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAppliedValue::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcAppliedValue> other = dynamic_pointer_cast<IfcAppliedValue>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_AppliedValue = other->m_AppliedValue;
			m_UnitBasis = other->m_UnitBasis;
			m_ApplicableDate = other->m_ApplicableDate;
			m_FixedUntilDate = other->m_FixedUntilDate;
			m_Category = other->m_Category;
			m_Condition = other->m_Condition;
			m_ArithmeticOperator = other->m_ArithmeticOperator;
			m_Components = other->m_Components;
		}
		void IfcAppliedValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPLIEDVALUE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_AppliedValue ) { m_AppliedValue->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_UnitBasis ) { stream << "#" << m_UnitBasis->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ApplicableDate ) { m_ApplicableDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FixedUntilDate ) { m_FixedUntilDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Category ) { m_Category->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Condition ) { m_Condition->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ArithmeticOperator ) { m_ArithmeticOperator->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Components );
			stream << ");";
		}
		void IfcAppliedValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAppliedValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAppliedValue, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcAppliedValue, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_AppliedValue = IfcAppliedValueSelect::readStepData( args[2], map );
			readEntityReference( args[3], m_UnitBasis, map );
			m_ApplicableDate = IfcDate::readStepData( args[4] );
			m_FixedUntilDate = IfcDate::readStepData( args[5] );
			m_Category = IfcLabel::readStepData( args[6] );
			m_Condition = IfcLabel::readStepData( args[7] );
			m_ArithmeticOperator = IfcArithmeticOperatorEnum::readStepData( args[8] );
			readEntityReferenceList( args[9], m_Components, map );
		}
		void IfcAppliedValue::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcAppliedValue::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform