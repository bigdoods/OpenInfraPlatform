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
		// TYPE IfcBuildingSystemTypeEnum = ENUMERATION OF	(FENESTRATION	,FOUNDATION	,LOADBEARING	,OUTERSHELL	,SHADING	,TRANSPORT	,USERDEFINED	,NOTDEFINED);
		class IfcBuildingSystemTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcBuildingSystemTypeEnumEnum
			{
				ENUM_FENESTRATION,
				ENUM_FOUNDATION,
				ENUM_LOADBEARING,
				ENUM_OUTERSHELL,
				ENUM_SHADING,
				ENUM_TRANSPORT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBuildingSystemTypeEnum();
			IfcBuildingSystemTypeEnum( IfcBuildingSystemTypeEnumEnum e ) { m_enum = e; }
			~IfcBuildingSystemTypeEnum();
			virtual const char* classname() const { return "IfcBuildingSystemTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBuildingSystemTypeEnum> readStepData( std::string& arg );
			IfcBuildingSystemTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

