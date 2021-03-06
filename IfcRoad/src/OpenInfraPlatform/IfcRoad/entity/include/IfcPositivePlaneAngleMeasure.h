/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcPlaneAngleMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPositivePlaneAngleMeasure = IfcPlaneAngleMeasure;
		class IfcPositivePlaneAngleMeasure : public IfcPlaneAngleMeasure
		{
		public:
			IfcPositivePlaneAngleMeasure();
			~IfcPositivePlaneAngleMeasure();
			virtual const char* classname() const { return "IfcPositivePlaneAngleMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPositivePlaneAngleMeasure> readStepData( std::string& arg );
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

