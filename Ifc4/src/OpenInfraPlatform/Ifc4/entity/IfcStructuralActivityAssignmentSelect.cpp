/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <map>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "include/IfcStructuralActivityAssignmentSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcStructuralActivityAssignmentSelect 
		IfcStructuralActivityAssignmentSelect::IfcStructuralActivityAssignmentSelect() {}
		IfcStructuralActivityAssignmentSelect::~IfcStructuralActivityAssignmentSelect() {}
		shared_ptr<IfcStructuralActivityAssignmentSelect> IfcStructuralActivityAssignmentSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcStructuralActivityAssignmentSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<Ifc4Entity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcStructuralActivityAssignmentSelect> type_object = dynamic_pointer_cast<IfcStructuralActivityAssignmentSelect>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw Ifc4Exception( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcStructuralActivityAssignmentSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcStructuralActivityAssignmentSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC4::IfcStructuralActivityAssignmentSelect::readStepData" << std::endl;
				throw Ifc4Exception( strs.str() );
			}
			return shared_ptr<IfcStructuralActivityAssignmentSelect>();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
