/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <map>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "include/IfcBoolean.h"
#include "include/IfcModulusOfLinearSubgradeReactionMeasure.h"
#include "include/IfcModulusOfTranslationalSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcModulusOfTranslationalSubgradeReactionSelect 
		IfcModulusOfTranslationalSubgradeReactionSelect::IfcModulusOfTranslationalSubgradeReactionSelect() {}
		IfcModulusOfTranslationalSubgradeReactionSelect::~IfcModulusOfTranslationalSubgradeReactionSelect() {}
		shared_ptr<IfcModulusOfTranslationalSubgradeReactionSelect> IfcModulusOfTranslationalSubgradeReactionSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcModulusOfTranslationalSubgradeReactionSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcRoadEntity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcModulusOfTranslationalSubgradeReactionSelect> type_object = dynamic_pointer_cast<IfcModulusOfTranslationalSubgradeReactionSelect>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw IfcRoadException( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcModulusOfTranslationalSubgradeReactionSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcModulusOfTranslationalSubgradeReactionSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCBOOLEAN")== 0 )
				{
					return IfcBoolean::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCMODULUSOFLINEARSUBGRADEREACTIONMEASURE")== 0 )
				{
					return IfcModulusOfLinearSubgradeReactionMeasure::readStepData( inline_arg );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC4::IfcModulusOfTranslationalSubgradeReactionSelect::readStepData" << std::endl;
				throw IfcRoadException( strs.str() );
			}
			return shared_ptr<IfcModulusOfTranslationalSubgradeReactionSelect>();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
