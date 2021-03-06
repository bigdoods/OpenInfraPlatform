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
		// TYPE IfcPerformanceHistoryTypeEnum = ENUMERATION OF	(USERDEFINED	,NOTDEFINED);
		class IfcPerformanceHistoryTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcPerformanceHistoryTypeEnumEnum
			{
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPerformanceHistoryTypeEnum();
			IfcPerformanceHistoryTypeEnum( IfcPerformanceHistoryTypeEnumEnum e ) { m_enum = e; }
			~IfcPerformanceHistoryTypeEnum();
			virtual const char* classname() const { return "IfcPerformanceHistoryTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPerformanceHistoryTypeEnum> readStepData( std::string& arg );
			IfcPerformanceHistoryTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

