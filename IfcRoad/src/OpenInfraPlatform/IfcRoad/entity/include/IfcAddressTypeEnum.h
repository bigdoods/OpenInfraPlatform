/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcAddressTypeEnum = ENUMERATION OF	(OFFICE	,SITE	,HOME	,DISTRIBUTIONPOINT	,USERDEFINED);
		class IfcAddressTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
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
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

