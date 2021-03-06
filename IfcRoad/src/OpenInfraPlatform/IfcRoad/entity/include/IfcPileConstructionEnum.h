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

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcPileConstructionEnum = ENUMERATION OF	(CAST_IN_PLACE	,COMPOSITE	,PRECAST_CONCRETE	,PREFAB_STEEL	,USERDEFINED	,NOTDEFINED);
		class IfcPileConstructionEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcPileConstructionEnumEnum
			{
				ENUM_CAST_IN_PLACE,
				ENUM_COMPOSITE,
				ENUM_PRECAST_CONCRETE,
				ENUM_PREFAB_STEEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPileConstructionEnum();
			IfcPileConstructionEnum( IfcPileConstructionEnumEnum e ) { m_enum = e; }
			~IfcPileConstructionEnum();
			virtual const char* classname() const { return "IfcPileConstructionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPileConstructionEnum> readStepData( std::string& arg );
			IfcPileConstructionEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

