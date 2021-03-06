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
		// TYPE IfcAnalysisModelTypeEnum = ENUMERATION OF	(IN_PLANE_LOADING_2D	,OUT_PLANE_LOADING_2D	,LOADING_3D	,USERDEFINED	,NOTDEFINED);
		class IfcAnalysisModelTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcAnalysisModelTypeEnumEnum
			{
				ENUM_IN_PLANE_LOADING_2D,
				ENUM_OUT_PLANE_LOADING_2D,
				ENUM_LOADING_3D,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAnalysisModelTypeEnum();
			IfcAnalysisModelTypeEnum( IfcAnalysisModelTypeEnumEnum e ) { m_enum = e; }
			~IfcAnalysisModelTypeEnum();
			virtual const char* classname() const { return "IfcAnalysisModelTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAnalysisModelTypeEnum> readStepData( std::string& arg );
			IfcAnalysisModelTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

