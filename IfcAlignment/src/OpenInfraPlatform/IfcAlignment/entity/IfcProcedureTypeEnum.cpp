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
#include "include/IfcProcedureTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcProcedureTypeEnum 
		IfcProcedureTypeEnum::IfcProcedureTypeEnum() {}
		IfcProcedureTypeEnum::~IfcProcedureTypeEnum() {}
		void IfcProcedureTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROCEDURETYPEENUM("; }
			if( m_enum == ENUM_ADVICE_CAUTION )
			{
				stream << ".ADVICE_CAUTION.";
			}
			else if( m_enum == ENUM_ADVICE_NOTE )
			{
				stream << ".ADVICE_NOTE.";
			}
			else if( m_enum == ENUM_ADVICE_WARNING )
			{
				stream << ".ADVICE_WARNING.";
			}
			else if( m_enum == ENUM_CALIBRATION )
			{
				stream << ".CALIBRATION.";
			}
			else if( m_enum == ENUM_DIAGNOSTIC )
			{
				stream << ".DIAGNOSTIC.";
			}
			else if( m_enum == ENUM_SHUTDOWN )
			{
				stream << ".SHUTDOWN.";
			}
			else if( m_enum == ENUM_STARTUP )
			{
				stream << ".STARTUP.";
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
		shared_ptr<IfcProcedureTypeEnum> IfcProcedureTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProcedureTypeEnum>(); }
			shared_ptr<IfcProcedureTypeEnum> type_object( new IfcProcedureTypeEnum() );
			if( _stricmp( arg.c_str(), ".ADVICE_CAUTION." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_ADVICE_CAUTION;
			}
			else if( _stricmp( arg.c_str(), ".ADVICE_NOTE." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_ADVICE_NOTE;
			}
			else if( _stricmp( arg.c_str(), ".ADVICE_WARNING." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_ADVICE_WARNING;
			}
			else if( _stricmp( arg.c_str(), ".CALIBRATION." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_CALIBRATION;
			}
			else if( _stricmp( arg.c_str(), ".DIAGNOSTIC." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_DIAGNOSTIC;
			}
			else if( _stricmp( arg.c_str(), ".SHUTDOWN." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_SHUTDOWN;
			}
			else if( _stricmp( arg.c_str(), ".STARTUP." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_STARTUP;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcProcedureTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
