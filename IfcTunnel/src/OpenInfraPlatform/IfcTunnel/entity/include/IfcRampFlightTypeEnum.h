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
		// TYPE IfcRampFlightTypeEnum = ENUMERATION OF	(STRAIGHT	,SPIRAL	,USERDEFINED	,NOTDEFINED);
		class IfcRampFlightTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcRampFlightTypeEnumEnum
			{
				ENUM_STRAIGHT,
				ENUM_SPIRAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcRampFlightTypeEnum();
			IfcRampFlightTypeEnum( IfcRampFlightTypeEnumEnum e ) { m_enum = e; }
			~IfcRampFlightTypeEnum();
			virtual const char* classname() const { return "IfcRampFlightTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRampFlightTypeEnum> readStepData( std::string& arg );
			IfcRampFlightTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

