/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcWorkCalendarTypeEnum = ENUMERATION OF	(FIRSTSHIFT	,SECONDSHIFT	,THIRDSHIFT	,USERDEFINED	,NOTDEFINED);
		class IfcWorkCalendarTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcWorkCalendarTypeEnumEnum
			{
				ENUM_FIRSTSHIFT,
				ENUM_SECONDSHIFT,
				ENUM_THIRDSHIFT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcWorkCalendarTypeEnum();
			IfcWorkCalendarTypeEnum( IfcWorkCalendarTypeEnumEnum e ) { m_enum = e; }
			~IfcWorkCalendarTypeEnum();
			virtual const char* classname() const { return "IfcWorkCalendarTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcWorkCalendarTypeEnum> readStepData( std::string& arg );
			IfcWorkCalendarTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

