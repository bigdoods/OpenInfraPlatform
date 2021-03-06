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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcPermeableCoveringOperationEnum = ENUMERATION OF	(GRILL	,LOUVER	,SCREEN	,USERDEFINED	,NOTDEFINED);
		class IfcPermeableCoveringOperationEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcPermeableCoveringOperationEnumEnum
			{
				ENUM_GRILL,
				ENUM_LOUVER,
				ENUM_SCREEN,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPermeableCoveringOperationEnum();
			IfcPermeableCoveringOperationEnum( IfcPermeableCoveringOperationEnumEnum e ) { m_enum = e; }
			~IfcPermeableCoveringOperationEnum();
			virtual const char* classname() const { return "IfcPermeableCoveringOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPermeableCoveringOperationEnum> readStepData( std::string& arg );
			IfcPermeableCoveringOperationEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

