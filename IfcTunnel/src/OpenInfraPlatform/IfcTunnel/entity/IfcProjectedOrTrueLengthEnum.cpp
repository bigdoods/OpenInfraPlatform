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
#include "include/IfcProjectedOrTrueLengthEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcProjectedOrTrueLengthEnum 
		IfcProjectedOrTrueLengthEnum::IfcProjectedOrTrueLengthEnum() {}
		IfcProjectedOrTrueLengthEnum::~IfcProjectedOrTrueLengthEnum() {}
		void IfcProjectedOrTrueLengthEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROJECTEDORTRUELENGTHENUM("; }
			if( m_enum == ENUM_PROJECTED_LENGTH )
			{
				stream << ".PROJECTED_LENGTH.";
			}
			else if( m_enum == ENUM_TRUE_LENGTH )
			{
				stream << ".TRUE_LENGTH.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcProjectedOrTrueLengthEnum> IfcProjectedOrTrueLengthEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProjectedOrTrueLengthEnum>(); }
			shared_ptr<IfcProjectedOrTrueLengthEnum> type_object( new IfcProjectedOrTrueLengthEnum() );
			if( _stricmp( arg.c_str(), ".PROJECTED_LENGTH." ) == 0 )
			{
				type_object->m_enum = IfcProjectedOrTrueLengthEnum::ENUM_PROJECTED_LENGTH;
			}
			else if( _stricmp( arg.c_str(), ".TRUE_LENGTH." ) == 0 )
			{
				type_object->m_enum = IfcProjectedOrTrueLengthEnum::ENUM_TRUE_LENGTH;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
