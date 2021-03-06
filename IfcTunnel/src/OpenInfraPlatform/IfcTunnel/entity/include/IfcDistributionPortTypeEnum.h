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
		// TYPE IfcDistributionPortTypeEnum = ENUMERATION OF	(CABLE	,CABLECARRIER	,DUCT	,PIPE	,USERDEFINED	,NOTDEFINED);
		class IfcDistributionPortTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDistributionPortTypeEnumEnum
			{
				ENUM_CABLE,
				ENUM_CABLECARRIER,
				ENUM_DUCT,
				ENUM_PIPE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDistributionPortTypeEnum();
			IfcDistributionPortTypeEnum( IfcDistributionPortTypeEnumEnum e ) { m_enum = e; }
			~IfcDistributionPortTypeEnum();
			virtual const char* classname() const { return "IfcDistributionPortTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDistributionPortTypeEnum> readStepData( std::string& arg );
			IfcDistributionPortTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

