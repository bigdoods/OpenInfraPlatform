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
		// TYPE IfcBuildingElementPartTypeEnum = ENUMERATION OF	(INSULATION	,PRECASTPANEL	,USERDEFINED	,NOTDEFINED);
		class IfcBuildingElementPartTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBuildingElementPartTypeEnumEnum
			{
				ENUM_INSULATION,
				ENUM_PRECASTPANEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcBuildingElementPartTypeEnum();
			IfcBuildingElementPartTypeEnum( IfcBuildingElementPartTypeEnumEnum e ) { m_enum = e; }
			~IfcBuildingElementPartTypeEnum();
			virtual const char* classname() const { return "IfcBuildingElementPartTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBuildingElementPartTypeEnum> readStepData( std::string& arg );
			IfcBuildingElementPartTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

