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
		// TYPE IfcTaskDurationEnum = ENUMERATION OF	(ELAPSEDTIME	,WORKTIME	,NOTDEFINED);
		class IfcTaskDurationEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcTaskDurationEnumEnum
			{
				ENUM_ELAPSEDTIME,
				ENUM_WORKTIME,
				ENUM_NOTDEFINED
			};

			IfcTaskDurationEnum();
			IfcTaskDurationEnum( IfcTaskDurationEnumEnum e ) { m_enum = e; }
			~IfcTaskDurationEnum();
			virtual const char* classname() const { return "IfcTaskDurationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTaskDurationEnum> readStepData( std::string& arg );
			IfcTaskDurationEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
