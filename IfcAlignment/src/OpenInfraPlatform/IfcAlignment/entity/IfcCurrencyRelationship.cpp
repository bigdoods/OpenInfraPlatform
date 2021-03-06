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
#include "include/IfcCurrencyRelationship.h"
#include "include/IfcDateTime.h"
#include "include/IfcLabel.h"
#include "include/IfcLibraryInformation.h"
#include "include/IfcMonetaryUnit.h"
#include "include/IfcPositiveRatioMeasure.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcCurrencyRelationship 
		IfcCurrencyRelationship::IfcCurrencyRelationship() { m_entity_enum = IFCCURRENCYRELATIONSHIP; }
		IfcCurrencyRelationship::IfcCurrencyRelationship( int id ) { m_id = id; m_entity_enum = IFCCURRENCYRELATIONSHIP; }
		IfcCurrencyRelationship::~IfcCurrencyRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurrencyRelationship::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcCurrencyRelationship> other = dynamic_pointer_cast<IfcCurrencyRelationship>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatingMonetaryUnit = other->m_RelatingMonetaryUnit;
			m_RelatedMonetaryUnit = other->m_RelatedMonetaryUnit;
			m_ExchangeRate = other->m_ExchangeRate;
			m_RateDateTime = other->m_RateDateTime;
			m_RateSource = other->m_RateSource;
		}
		void IfcCurrencyRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURRENCYRELATIONSHIP" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingMonetaryUnit ) { stream << "#" << m_RelatingMonetaryUnit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedMonetaryUnit ) { stream << "#" << m_RelatedMonetaryUnit->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ExchangeRate ) { m_ExchangeRate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RateDateTime ) { m_RateDateTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RateSource ) { stream << "#" << m_RateSource->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCurrencyRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurrencyRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurrencyRelationship, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcCurrencyRelationship, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			readEntityReference( args[2], m_RelatingMonetaryUnit, map );
			readEntityReference( args[3], m_RelatedMonetaryUnit, map );
			m_ExchangeRate = IfcPositiveRatioMeasure::readStepData( args[4] );
			m_RateDateTime = IfcDateTime::readStepData( args[5] );
			readEntityReference( args[6], m_RateSource, map );
		}
		void IfcCurrencyRelationship::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcResourceLevelRelationship::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurrencyRelationship::unlinkSelf()
		{
			IfcResourceLevelRelationship::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
