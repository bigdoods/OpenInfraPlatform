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
		// TYPE IfcCoilTypeEnum = ENUMERATION OF	(DXCOOLINGCOIL	,ELECTRICHEATINGCOIL	,GASHEATINGCOIL	,HYDRONICCOIL	,STEAMHEATINGCOIL	,WATERCOOLINGCOIL	,WATERHEATINGCOIL	,USERDEFINED	,NOTDEFINED);
		class IfcCoilTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcCoilTypeEnumEnum
			{
				ENUM_DXCOOLINGCOIL,
				ENUM_ELECTRICHEATINGCOIL,
				ENUM_GASHEATINGCOIL,
				ENUM_HYDRONICCOIL,
				ENUM_STEAMHEATINGCOIL,
				ENUM_WATERCOOLINGCOIL,
				ENUM_WATERHEATINGCOIL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCoilTypeEnum();
			IfcCoilTypeEnum( IfcCoilTypeEnumEnum e ) { m_enum = e; }
			~IfcCoilTypeEnum();
			virtual const char* classname() const { return "IfcCoilTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCoilTypeEnum> readStepData( std::string& arg );
			IfcCoilTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

