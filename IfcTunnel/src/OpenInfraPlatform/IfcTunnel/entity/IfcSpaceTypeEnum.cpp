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
#include "include/IfcSpaceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcSpaceTypeEnum 
		IfcSpaceTypeEnum::IfcSpaceTypeEnum() {}
		IfcSpaceTypeEnum::~IfcSpaceTypeEnum() {}
		void IfcSpaceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSPACETYPEENUM("; }
			if( m_enum == ENUM_SPACE )
			{
				stream << ".SPACE.";
			}
			else if( m_enum == ENUM_PARKING )
			{
				stream << ".PARKING.";
			}
			else if( m_enum == ENUM_GFA )
			{
				stream << ".GFA.";
			}
			else if( m_enum == ENUM_INTERNAL )
			{
				stream << ".INTERNAL.";
			}
			else if( m_enum == ENUM_EXTERNAL )
			{
				stream << ".EXTERNAL.";
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
		shared_ptr<IfcSpaceTypeEnum> IfcSpaceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSpaceTypeEnum>(); }
			shared_ptr<IfcSpaceTypeEnum> type_object( new IfcSpaceTypeEnum() );
			if( _stricmp( arg.c_str(), ".SPACE." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_SPACE;
			}
			else if( _stricmp( arg.c_str(), ".PARKING." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_PARKING;
			}
			else if( _stricmp( arg.c_str(), ".GFA." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_GFA;
			}
			else if( _stricmp( arg.c_str(), ".INTERNAL." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_INTERNAL;
			}
			else if( _stricmp( arg.c_str(), ".EXTERNAL." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_EXTERNAL;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpaceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
