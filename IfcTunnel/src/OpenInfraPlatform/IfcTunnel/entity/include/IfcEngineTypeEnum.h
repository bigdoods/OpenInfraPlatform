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
		// TYPE IfcEngineTypeEnum = ENUMERATION OF	(EXTERNALCOMBUSTION	,INTERNALCOMBUSTION	,USERDEFINED	,NOTDEFINED);
		class IfcEngineTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcEngineTypeEnumEnum
			{
				ENUM_EXTERNALCOMBUSTION,
				ENUM_INTERNALCOMBUSTION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEngineTypeEnum();
			IfcEngineTypeEnum( IfcEngineTypeEnumEnum e ) { m_enum = e; }
			~IfcEngineTypeEnum();
			virtual const char* classname() const { return "IfcEngineTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEngineTypeEnum> readStepData( std::string& arg );
			IfcEngineTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

