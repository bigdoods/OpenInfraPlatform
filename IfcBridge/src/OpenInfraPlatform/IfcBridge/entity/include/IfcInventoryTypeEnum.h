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
		// TYPE IfcInventoryTypeEnum = ENUMERATION OF	(ASSETINVENTORY	,SPACEINVENTORY	,FURNITUREINVENTORY	,USERDEFINED	,NOTDEFINED);
		class IfcInventoryTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcInventoryTypeEnumEnum
			{
				ENUM_ASSETINVENTORY,
				ENUM_SPACEINVENTORY,
				ENUM_FURNITUREINVENTORY,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcInventoryTypeEnum();
			IfcInventoryTypeEnum( IfcInventoryTypeEnumEnum e ) { m_enum = e; }
			~IfcInventoryTypeEnum();
			virtual const char* classname() const { return "IfcInventoryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcInventoryTypeEnum> readStepData( std::string& arg );
			IfcInventoryTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

