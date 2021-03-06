/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../model/IfcBridgeException.h"
#include "include/IfcControllerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcControllerTypeEnum 
		IfcControllerTypeEnum::IfcControllerTypeEnum() {}
		IfcControllerTypeEnum::~IfcControllerTypeEnum() {}
		void IfcControllerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCONTROLLERTYPEENUM("; }
			if( m_enum == ENUM_FLOATING )
			{
				stream << ".FLOATING.";
			}
			else if( m_enum == ENUM_PROGRAMMABLE )
			{
				stream << ".PROGRAMMABLE.";
			}
			else if( m_enum == ENUM_PROPORTIONAL )
			{
				stream << ".PROPORTIONAL.";
			}
			else if( m_enum == ENUM_MULTIPOSITION )
			{
				stream << ".MULTIPOSITION.";
			}
			else if( m_enum == ENUM_TWOPOSITION )
			{
				stream << ".TWOPOSITION.";
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
		shared_ptr<IfcControllerTypeEnum> IfcControllerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcControllerTypeEnum>(); }
			shared_ptr<IfcControllerTypeEnum> type_object( new IfcControllerTypeEnum() );
			if( _stricmp( arg.c_str(), ".FLOATING." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_FLOATING;
			}
			else if( _stricmp( arg.c_str(), ".PROGRAMMABLE." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_PROGRAMMABLE;
			}
			else if( _stricmp( arg.c_str(), ".PROPORTIONAL." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_PROPORTIONAL;
			}
			else if( _stricmp( arg.c_str(), ".MULTIPOSITION." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_MULTIPOSITION;
			}
			else if( _stricmp( arg.c_str(), ".TWOPOSITION." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_TWOPOSITION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcControllerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
