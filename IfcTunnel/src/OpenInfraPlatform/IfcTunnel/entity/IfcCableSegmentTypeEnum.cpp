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
#include "include/IfcCableSegmentTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcCableSegmentTypeEnum 
		IfcCableSegmentTypeEnum::IfcCableSegmentTypeEnum() {}
		IfcCableSegmentTypeEnum::~IfcCableSegmentTypeEnum() {}
		void IfcCableSegmentTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCABLESEGMENTTYPEENUM("; }
			if( m_enum == ENUM_BUSBARSEGMENT )
			{
				stream << ".BUSBARSEGMENT.";
			}
			else if( m_enum == ENUM_CABLESEGMENT )
			{
				stream << ".CABLESEGMENT.";
			}
			else if( m_enum == ENUM_CONDUCTORSEGMENT )
			{
				stream << ".CONDUCTORSEGMENT.";
			}
			else if( m_enum == ENUM_CORESEGMENT )
			{
				stream << ".CORESEGMENT.";
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
		shared_ptr<IfcCableSegmentTypeEnum> IfcCableSegmentTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCableSegmentTypeEnum>(); }
			shared_ptr<IfcCableSegmentTypeEnum> type_object( new IfcCableSegmentTypeEnum() );
			if( _stricmp( arg.c_str(), ".BUSBARSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableSegmentTypeEnum::ENUM_BUSBARSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".CABLESEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableSegmentTypeEnum::ENUM_CABLESEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".CONDUCTORSEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableSegmentTypeEnum::ENUM_CONDUCTORSEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".CORESEGMENT." ) == 0 )
			{
				type_object->m_enum = IfcCableSegmentTypeEnum::ENUM_CORESEGMENT;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableSegmentTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableSegmentTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
