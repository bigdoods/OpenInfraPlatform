/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcLampTypeEnum = ENUMERATION OF	(COMPACTFLUORESCENT	,FLUORESCENT	,HIGHPRESSUREMERCURY	,HIGHPRESSURESODIUM	,METALHALIDE	,TUNGSTENFILAMENT	,USERDEFINED	,NOTDEFINED);
		class IfcLampTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcLampTypeEnumEnum
			{
				ENUM_COMPACTFLUORESCENT,
				ENUM_FLUORESCENT,
				ENUM_HIGHPRESSUREMERCURY,
				ENUM_HIGHPRESSURESODIUM,
				ENUM_METALHALIDE,
				ENUM_TUNGSTENFILAMENT,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcLampTypeEnum();
			IfcLampTypeEnum( IfcLampTypeEnumEnum e ) { m_enum = e; }
			~IfcLampTypeEnum();
			virtual const char* classname() const { return "IfcLampTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLampTypeEnum> readStepData( std::string& arg );
			IfcLampTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

