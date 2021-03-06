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

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDoorTypeEnum = ENUMERATION OF	(DOOR	,GATE	,TRAPDOOR	,USERDEFINED	,NOTDEFINED);
		class IfcDoorTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcDoorTypeEnumEnum
			{
				ENUM_DOOR,
				ENUM_GATE,
				ENUM_TRAPDOOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorTypeEnum();
			IfcDoorTypeEnum( IfcDoorTypeEnumEnum e ) { m_enum = e; }
			~IfcDoorTypeEnum();
			virtual const char* classname() const { return "IfcDoorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorTypeEnum> readStepData( std::string& arg );
			IfcDoorTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

