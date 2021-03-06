/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcCondenserTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcCondenserTypeEnum 
		IfcCondenserTypeEnum::IfcCondenserTypeEnum() {}
		IfcCondenserTypeEnum::~IfcCondenserTypeEnum() {}
		void IfcCondenserTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONDENSERTYPEENUM("; }
			if( m_enum == ENUM_AIRCOOLED )
			{
				stream << ".AIRCOOLED.";
			}
			else if( m_enum == ENUM_EVAPORATIVECOOLED )
			{
				stream << ".EVAPORATIVECOOLED.";
			}
			else if( m_enum == ENUM_WATERCOOLED )
			{
				stream << ".WATERCOOLED.";
			}
			else if( m_enum == ENUM_WATERCOOLEDBRAZEDPLATE )
			{
				stream << ".WATERCOOLEDBRAZEDPLATE.";
			}
			else if( m_enum == ENUM_WATERCOOLEDSHELLCOIL )
			{
				stream << ".WATERCOOLEDSHELLCOIL.";
			}
			else if( m_enum == ENUM_WATERCOOLEDSHELLTUBE )
			{
				stream << ".WATERCOOLEDSHELLTUBE.";
			}
			else if( m_enum == ENUM_WATERCOOLEDTUBEINTUBE )
			{
				stream << ".WATERCOOLEDTUBEINTUBE.";
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
		shared_ptr<IfcCondenserTypeEnum> IfcCondenserTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCondenserTypeEnum>(); }
			shared_ptr<IfcCondenserTypeEnum> type_object( new IfcCondenserTypeEnum() );
			if( _stricmp( arg.c_str(), ".AIRCOOLED." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_AIRCOOLED;
			}
			else if( _stricmp( arg.c_str(), ".EVAPORATIVECOOLED." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_EVAPORATIVECOOLED;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLED." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_WATERCOOLED;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLEDBRAZEDPLATE." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_WATERCOOLEDBRAZEDPLATE;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLEDSHELLCOIL." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_WATERCOOLEDSHELLCOIL;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLEDSHELLTUBE." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_WATERCOOLEDSHELLTUBE;
			}
			else if( _stricmp( arg.c_str(), ".WATERCOOLEDTUBEINTUBE." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_WATERCOOLEDTUBEINTUBE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCondenserTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
