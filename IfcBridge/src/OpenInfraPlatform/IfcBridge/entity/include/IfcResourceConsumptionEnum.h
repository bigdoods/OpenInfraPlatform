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
		// TYPE IfcResourceConsumptionEnum = ENUMERATION OF	(CONSUMED	,PARTIALLYCONSUMED	,NOTCONSUMED	,OCCUPIED	,PARTIALLYOCCUPIED	,NOTOCCUPIED	,USERDEFINED	,NOTDEFINED);
		class IfcResourceConsumptionEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcResourceConsumptionEnumEnum
			{
				ENUM_CONSUMED,
				ENUM_PARTIALLYCONSUMED,
				ENUM_NOTCONSUMED,
				ENUM_OCCUPIED,
				ENUM_PARTIALLYOCCUPIED,
				ENUM_NOTOCCUPIED,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcResourceConsumptionEnum();
			IfcResourceConsumptionEnum( IfcResourceConsumptionEnumEnum e ) { m_enum = e; }
			~IfcResourceConsumptionEnum();
			virtual const char* classname() const { return "IfcResourceConsumptionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcResourceConsumptionEnum> readStepData( std::string& arg );
			IfcResourceConsumptionEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

