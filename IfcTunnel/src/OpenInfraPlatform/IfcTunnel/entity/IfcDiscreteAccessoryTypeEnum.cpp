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
#include "include/IfcDiscreteAccessoryTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcDiscreteAccessoryTypeEnum 
		IfcDiscreteAccessoryTypeEnum::IfcDiscreteAccessoryTypeEnum() {}
		IfcDiscreteAccessoryTypeEnum::~IfcDiscreteAccessoryTypeEnum() {}
		void IfcDiscreteAccessoryTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDISCRETEACCESSORYTYPEENUM("; }
			if( m_enum == ENUM_ANCHORPLATE )
			{
				stream << ".ANCHORPLATE.";
			}
			else if( m_enum == ENUM_BRACKET )
			{
				stream << ".BRACKET.";
			}
			else if( m_enum == ENUM_SHOE )
			{
				stream << ".SHOE.";
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
		shared_ptr<IfcDiscreteAccessoryTypeEnum> IfcDiscreteAccessoryTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDiscreteAccessoryTypeEnum>(); }
			shared_ptr<IfcDiscreteAccessoryTypeEnum> type_object( new IfcDiscreteAccessoryTypeEnum() );
			if( _stricmp( arg.c_str(), ".ANCHORPLATE." ) == 0 )
			{
				type_object->m_enum = IfcDiscreteAccessoryTypeEnum::ENUM_ANCHORPLATE;
			}
			else if( _stricmp( arg.c_str(), ".BRACKET." ) == 0 )
			{
				type_object->m_enum = IfcDiscreteAccessoryTypeEnum::ENUM_BRACKET;
			}
			else if( _stricmp( arg.c_str(), ".SHOE." ) == 0 )
			{
				type_object->m_enum = IfcDiscreteAccessoryTypeEnum::ENUM_SHOE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDiscreteAccessoryTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDiscreteAccessoryTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform