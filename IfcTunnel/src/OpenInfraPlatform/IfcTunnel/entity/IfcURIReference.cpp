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
#include "include/IfcURIReference.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcURIReference 
		IfcURIReference::IfcURIReference() {}
		IfcURIReference::IfcURIReference( std::string value ) { m_value = value; }
		IfcURIReference::~IfcURIReference() {}
		void IfcURIReference::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCURIREFERENCE("; }
			//supertype as attribute: std::string m_value
			stream << "'" << encodeStepString( m_value ) << "'";
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcURIReference> IfcURIReference::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcURIReference>(); }
			shared_ptr<IfcURIReference> type_object( new IfcURIReference() );
			//supertype as attribute: std::string m_value
			type_object->m_value = arg;
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
