/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"
#include "IfcRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcPositiveRatioMeasure = IfcRatioMeasure;
		class IfcPositiveRatioMeasure : public IfcRatioMeasure
		{
		public:
			IfcPositiveRatioMeasure();
			~IfcPositiveRatioMeasure();
			virtual const char* classname() const { return "IfcPositiveRatioMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPositiveRatioMeasure> readStepData( std::string& arg );
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

