/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcAnalysisTheoryTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcAnalysisTheoryTypeEnum 
		IfcAnalysisTheoryTypeEnum::IfcAnalysisTheoryTypeEnum() {}
		IfcAnalysisTheoryTypeEnum::~IfcAnalysisTheoryTypeEnum() {}
		void IfcAnalysisTheoryTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCANALYSISTHEORYTYPEENUM("; }
			if( m_enum == ENUM_FIRST_ORDER_THEORY )
			{
				stream << ".FIRST_ORDER_THEORY.";
			}
			else if( m_enum == ENUM_SECOND_ORDER_THEORY )
			{
				stream << ".SECOND_ORDER_THEORY.";
			}
			else if( m_enum == ENUM_THIRD_ORDER_THEORY )
			{
				stream << ".THIRD_ORDER_THEORY.";
			}
			else if( m_enum == ENUM_FULL_NONLINEAR_THEORY )
			{
				stream << ".FULL_NONLINEAR_THEORY.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcAnalysisTheoryTypeEnum> IfcAnalysisTheoryTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcAnalysisTheoryTypeEnum>(); }
			shared_ptr<IfcAnalysisTheoryTypeEnum> type_object( new IfcAnalysisTheoryTypeEnum() );
			if( _stricmp( arg.c_str(), ".FIRST_ORDER_THEORY." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisTheoryTypeEnum::ENUM_FIRST_ORDER_THEORY;
			}
			else if( _stricmp( arg.c_str(), ".SECOND_ORDER_THEORY." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisTheoryTypeEnum::ENUM_SECOND_ORDER_THEORY;
			}
			else if( _stricmp( arg.c_str(), ".THIRD_ORDER_THEORY." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisTheoryTypeEnum::ENUM_THIRD_ORDER_THEORY;
			}
			else if( _stricmp( arg.c_str(), ".FULL_NONLINEAR_THEORY." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisTheoryTypeEnum::ENUM_FULL_NONLINEAR_THEORY;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisTheoryTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcAnalysisTheoryTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
