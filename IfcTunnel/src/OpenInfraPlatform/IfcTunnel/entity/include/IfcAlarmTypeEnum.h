/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcAlarmTypeEnum = ENUMERATION OF	(BELL	,BREAKGLASSBUTTON	,LIGHT	,MANUALPULLBOX	,SIREN	,WHISTLE	,USERDEFINED	,NOTDEFINED);
		class IfcAlarmTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcAlarmTypeEnumEnum
			{
				ENUM_BELL,
				ENUM_BREAKGLASSBUTTON,
				ENUM_LIGHT,
				ENUM_MANUALPULLBOX,
				ENUM_SIREN,
				ENUM_WHISTLE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAlarmTypeEnum();
			IfcAlarmTypeEnum( IfcAlarmTypeEnumEnum e ) { m_enum = e; }
			~IfcAlarmTypeEnum();
			virtual const char* classname() const { return "IfcAlarmTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAlarmTypeEnum> readStepData( std::string& arg );
			IfcAlarmTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

