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
		// TYPE IfcComplexPropertyTemplateTypeEnum = ENUMERATION OF	(P_COMPLEX	,Q_COMPLEX);
		class IfcComplexPropertyTemplateTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcComplexPropertyTemplateTypeEnumEnum
			{
				ENUM_P_COMPLEX,
				ENUM_Q_COMPLEX
			};

			IfcComplexPropertyTemplateTypeEnum();
			IfcComplexPropertyTemplateTypeEnum( IfcComplexPropertyTemplateTypeEnumEnum e ) { m_enum = e; }
			~IfcComplexPropertyTemplateTypeEnum();
			virtual const char* classname() const { return "IfcComplexPropertyTemplateTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcComplexPropertyTemplateTypeEnum> readStepData( std::string& arg );
			IfcComplexPropertyTemplateTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

