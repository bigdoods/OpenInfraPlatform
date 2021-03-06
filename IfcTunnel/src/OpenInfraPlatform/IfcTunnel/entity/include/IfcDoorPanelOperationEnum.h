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
		// TYPE IfcDoorPanelOperationEnum = ENUMERATION OF	(SWINGING	,DOUBLE_ACTING	,SLIDING	,FOLDING	,REVOLVING	,ROLLINGUP	,FIXEDPANEL	,USERDEFINED	,NOTDEFINED);
		class IfcDoorPanelOperationEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDoorPanelOperationEnumEnum
			{
				ENUM_SWINGING,
				ENUM_DOUBLE_ACTING,
				ENUM_SLIDING,
				ENUM_FOLDING,
				ENUM_REVOLVING,
				ENUM_ROLLINGUP,
				ENUM_FIXEDPANEL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDoorPanelOperationEnum();
			IfcDoorPanelOperationEnum( IfcDoorPanelOperationEnumEnum e ) { m_enum = e; }
			~IfcDoorPanelOperationEnum();
			virtual const char* classname() const { return "IfcDoorPanelOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDoorPanelOperationEnum> readStepData( std::string& arg );
			IfcDoorPanelOperationEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

