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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcRatioMeasure.h"
#include "IfcColourOrFactor.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcNormalisedRatioMeasure = IfcRatioMeasure;
		class IfcNormalisedRatioMeasure : public IfcRatioMeasure, public IfcColourOrFactor
		{
		public:
			IfcNormalisedRatioMeasure();
			~IfcNormalisedRatioMeasure();
			virtual const char* classname() const { return "IfcNormalisedRatioMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcNormalisedRatioMeasure> readStepData( std::string& arg );
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

