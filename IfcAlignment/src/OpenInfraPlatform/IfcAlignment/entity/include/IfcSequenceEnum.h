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
		// TYPE IfcSequenceEnum = ENUMERATION OF	(START_START	,START_FINISH	,FINISH_START	,FINISH_FINISH	,USERDEFINED	,NOTDEFINED);
		class IfcSequenceEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcSequenceEnumEnum
			{
				ENUM_START_START,
				ENUM_START_FINISH,
				ENUM_FINISH_START,
				ENUM_FINISH_FINISH,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSequenceEnum();
			IfcSequenceEnum( IfcSequenceEnumEnum e ) { m_enum = e; }
			~IfcSequenceEnum();
			virtual const char* classname() const { return "IfcSequenceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSequenceEnum> readStepData( std::string& arg );
			IfcSequenceEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

