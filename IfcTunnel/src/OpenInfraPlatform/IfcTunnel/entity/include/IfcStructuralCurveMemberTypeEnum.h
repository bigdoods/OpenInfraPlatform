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
		// TYPE IfcStructuralCurveMemberTypeEnum = ENUMERATION OF	(RIGID_JOINED_MEMBER	,PIN_JOINED_MEMBER	,CABLE	,TENSION_MEMBER	,COMPRESSION_MEMBER	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralCurveMemberTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcStructuralCurveMemberTypeEnumEnum
			{
				ENUM_RIGID_JOINED_MEMBER,
				ENUM_PIN_JOINED_MEMBER,
				ENUM_CABLE,
				ENUM_TENSION_MEMBER,
				ENUM_COMPRESSION_MEMBER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStructuralCurveMemberTypeEnum();
			IfcStructuralCurveMemberTypeEnum( IfcStructuralCurveMemberTypeEnumEnum e ) { m_enum = e; }
			~IfcStructuralCurveMemberTypeEnum();
			virtual const char* classname() const { return "IfcStructuralCurveMemberTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStructuralCurveMemberTypeEnum> readStepData( std::string& arg );
			IfcStructuralCurveMemberTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

