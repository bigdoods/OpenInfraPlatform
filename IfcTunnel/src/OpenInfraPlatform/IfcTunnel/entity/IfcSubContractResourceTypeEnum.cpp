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
#include "include/IfcSubContractResourceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcSubContractResourceTypeEnum 
		IfcSubContractResourceTypeEnum::IfcSubContractResourceTypeEnum() {}
		IfcSubContractResourceTypeEnum::~IfcSubContractResourceTypeEnum() {}
		void IfcSubContractResourceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSUBCONTRACTRESOURCETYPEENUM("; }
			if( m_enum == ENUM_PURCHASE )
			{
				stream << ".PURCHASE.";
			}
			else if( m_enum == ENUM_WORK )
			{
				stream << ".WORK.";
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
		shared_ptr<IfcSubContractResourceTypeEnum> IfcSubContractResourceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSubContractResourceTypeEnum>(); }
			shared_ptr<IfcSubContractResourceTypeEnum> type_object( new IfcSubContractResourceTypeEnum() );
			if( _stricmp( arg.c_str(), ".PURCHASE." ) == 0 )
			{
				type_object->m_enum = IfcSubContractResourceTypeEnum::ENUM_PURCHASE;
			}
			else if( _stricmp( arg.c_str(), ".WORK." ) == 0 )
			{
				type_object->m_enum = IfcSubContractResourceTypeEnum::ENUM_WORK;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSubContractResourceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSubContractResourceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
