/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/Ifc2x3Exception.h"
#include "include/IfcDataOriginEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcDataOriginEnum 
		IfcDataOriginEnum::IfcDataOriginEnum() {}
		IfcDataOriginEnum::~IfcDataOriginEnum() {}
		void IfcDataOriginEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDATAORIGINENUM("; }
			if( m_enum == ENUM_MEASURED )
			{
				stream << ".MEASURED.";
			}
			else if( m_enum == ENUM_PREDICTED )
			{
				stream << ".PREDICTED.";
			}
			else if( m_enum == ENUM_SIMULATED )
			{
				stream << ".SIMULATED.";
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
		shared_ptr<IfcDataOriginEnum> IfcDataOriginEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDataOriginEnum>(); }
			shared_ptr<IfcDataOriginEnum> type_object( new IfcDataOriginEnum() );
			if( _stricmp( arg.c_str(), ".MEASURED." ) == 0 )
			{
				type_object->m_enum = IfcDataOriginEnum::ENUM_MEASURED;
			}
			else if( _stricmp( arg.c_str(), ".PREDICTED." ) == 0 )
			{
				type_object->m_enum = IfcDataOriginEnum::ENUM_PREDICTED;
			}
			else if( _stricmp( arg.c_str(), ".SIMULATED." ) == 0 )
			{
				type_object->m_enum = IfcDataOriginEnum::ENUM_SIMULATED;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDataOriginEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDataOriginEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
