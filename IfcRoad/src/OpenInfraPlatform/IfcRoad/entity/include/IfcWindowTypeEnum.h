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
		// TYPE IfcWindowTypeEnum = ENUMERATION OF	(WINDOW	,SKYLIGHT	,LIGHTDOME	,USERDEFINED	,NOTDEFINED);
		class IfcWindowTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcWindowTypeEnumEnum
			{
				ENUM_WINDOW,
				ENUM_SKYLIGHT,
				ENUM_LIGHTDOME,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWindowTypeEnum();
			IfcWindowTypeEnum( IfcWindowTypeEnumEnum e ) { m_enum = e; }
			~IfcWindowTypeEnum();
			virtual const char* classname() const { return "IfcWindowTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWindowTypeEnum> readStepData( std::string& arg );
			IfcWindowTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

