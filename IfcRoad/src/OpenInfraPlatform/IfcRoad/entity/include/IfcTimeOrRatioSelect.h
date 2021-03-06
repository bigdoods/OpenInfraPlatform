/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

// TYPE IfcTimeOrRatioSelect = SELECT	(IfcDuration	,IfcRatioMeasure);
namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcTimeOrRatioSelect : public IfcRoadAbstractSelect
		{
		public:
			IfcTimeOrRatioSelect();
			~IfcTimeOrRatioSelect();
			virtual const char* classname() const { return "IfcTimeOrRatioSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcTimeOrRatioSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

