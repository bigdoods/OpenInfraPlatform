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
		// TYPE IfcCurveInterpolationEnum = ENUMERATION OF	(LINEAR	,LOG_LINEAR	,LOG_LOG	,NOTDEFINED);
		class IfcCurveInterpolationEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCurveInterpolationEnumEnum
			{
				ENUM_LINEAR,
				ENUM_LOG_LINEAR,
				ENUM_LOG_LOG,
				ENUM_NOTDEFINED
			};

			IfcCurveInterpolationEnum();
			IfcCurveInterpolationEnum( IfcCurveInterpolationEnumEnum e ) { m_enum = e; }
			~IfcCurveInterpolationEnum();
			virtual const char* classname() const { return "IfcCurveInterpolationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCurveInterpolationEnum> readStepData( std::string& arg );
			IfcCurveInterpolationEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

