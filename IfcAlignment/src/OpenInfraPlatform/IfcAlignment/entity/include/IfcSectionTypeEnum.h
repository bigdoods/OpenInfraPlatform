/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSectionTypeEnum = ENUMERATION OF	(UNIFORM	,TAPERED);
		class IfcSectionTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcSectionTypeEnumEnum
			{
				ENUM_UNIFORM,
				ENUM_TAPERED
			};

			IfcSectionTypeEnum();
			IfcSectionTypeEnum( IfcSectionTypeEnumEnum e ) { m_enum = e; }
			~IfcSectionTypeEnum();
			virtual const char* classname() const { return "IfcSectionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSectionTypeEnum> readStepData( std::string& arg );
			IfcSectionTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

