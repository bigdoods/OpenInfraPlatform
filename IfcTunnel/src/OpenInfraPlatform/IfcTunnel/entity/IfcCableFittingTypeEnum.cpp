/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcCableFittingTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcCableFittingTypeEnum 
		IfcCableFittingTypeEnum::IfcCableFittingTypeEnum() {}
		IfcCableFittingTypeEnum::~IfcCableFittingTypeEnum() {}
		void IfcCableFittingTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCABLEFITTINGTYPEENUM("; }
			if( m_enum == ENUM_CONNECTOR )
			{
				stream << ".CONNECTOR.";
			}
			else if( m_enum == ENUM_ENTRY )
			{
				stream << ".ENTRY.";
			}
			else if( m_enum == ENUM_EXIT )
			{
				stream << ".EXIT.";
			}
			else if( m_enum == ENUM_JUNCTION )
			{
				stream << ".JUNCTION.";
			}
			else if( m_enum == ENUM_TRANSITION )
			{
				stream << ".TRANSITION.";
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
		shared_ptr<IfcCableFittingTypeEnum> IfcCableFittingTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCableFittingTypeEnum>(); }
			shared_ptr<IfcCableFittingTypeEnum> type_object( new IfcCableFittingTypeEnum() );
			if( _stricmp( arg.c_str(), ".CONNECTOR." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_CONNECTOR;
			}
			else if( _stricmp( arg.c_str(), ".ENTRY." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_ENTRY;
			}
			else if( _stricmp( arg.c_str(), ".EXIT." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_EXIT;
			}
			else if( _stricmp( arg.c_str(), ".JUNCTION." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_JUNCTION;
			}
			else if( _stricmp( arg.c_str(), ".TRANSITION." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_TRANSITION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableFittingTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
