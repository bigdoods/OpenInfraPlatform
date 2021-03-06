/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcSimpleValue.h"
#include "include/IfcLogical.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcLogical 
		IfcLogical::IfcLogical() {}
		IfcLogical::IfcLogical( bool value ) { m_value = value; }
		IfcLogical::~IfcLogical() {}
		void IfcLogical::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLOGICAL("; }
			//supertype as attribute: bool m_value
			if( m_value == false )
			{
				stream << ".F.";
			}
			else if( m_value == true )
			{
				stream << ".T.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcLogical> IfcLogical::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLogical>(); }
			shared_ptr<IfcLogical> type_object( new IfcLogical() );
			//supertype as attribute: bool m_value
			if( _stricmp( arg.c_str(), ".F." ) == 0 )
			{
				type_object->m_value = false;
			}
			else if( _stricmp( arg.c_str(), ".T." ) == 0 )
			{
				type_object->m_value = true;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
