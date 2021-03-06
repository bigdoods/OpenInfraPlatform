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
		// TYPE IfcAddressTypeEnum = ENUMERATION OF	(OFFICE	,SITE	,HOME	,DISTRIBUTIONPOINT	,USERDEFINED);
		class IfcAddressTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcAddressTypeEnumEnum
			{
				ENUM_OFFICE,
				ENUM_SITE,
				ENUM_HOME,
				ENUM_DISTRIBUTIONPOINT,
				ENUM_USERDEFINED
			};

			IfcAddressTypeEnum();
			IfcAddressTypeEnum( IfcAddressTypeEnumEnum e ) { m_enum = e; }
			~IfcAddressTypeEnum();
			virtual const char* classname() const { return "IfcAddressTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAddressTypeEnum> readStepData( std::string& arg );
			IfcAddressTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

