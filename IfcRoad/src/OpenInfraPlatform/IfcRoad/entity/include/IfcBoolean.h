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
#include "IfcModulusOfRotationalSubgradeReactionSelect.h"
#include "IfcModulusOfSubgradeReactionSelect.h"
#include "IfcModulusOfTranslationalSubgradeReactionSelect.h"
#include "IfcRotationalStiffnessSelect.h"
#include "IfcSimpleValue.h"
#include "IfcTranslationalStiffnessSelect.h"
#include "IfcWarpingStiffnessSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcBoolean = BOOLEAN;
		class IfcBoolean : public IfcModulusOfRotationalSubgradeReactionSelect, public IfcModulusOfSubgradeReactionSelect, public IfcModulusOfTranslationalSubgradeReactionSelect, public IfcRotationalStiffnessSelect, public IfcSimpleValue, public IfcTranslationalStiffnessSelect, public IfcWarpingStiffnessSelect, public IfcRoadType
		{
		public:
			IfcBoolean();
			IfcBoolean( bool value );
			~IfcBoolean();
			virtual const char* classname() const { return "IfcBoolean"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBoolean> readStepData( std::string& arg );
			bool m_value;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

