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
		// TYPE IfcCableFittingTypeEnum = ENUMERATION OF	(CONNECTOR	,ENTRY	,EXIT	,JUNCTION	,TRANSITION	,USERDEFINED	,NOTDEFINED);
		class IfcCableFittingTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcCableFittingTypeEnumEnum
			{
				ENUM_CONNECTOR,
				ENUM_ENTRY,
				ENUM_EXIT,
				ENUM_JUNCTION,
				ENUM_TRANSITION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCableFittingTypeEnum();
			IfcCableFittingTypeEnum( IfcCableFittingTypeEnumEnum e ) { m_enum = e; }
			~IfcCableFittingTypeEnum();
			virtual const char* classname() const { return "IfcCableFittingTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCableFittingTypeEnum> readStepData( std::string& arg );
			IfcCableFittingTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

