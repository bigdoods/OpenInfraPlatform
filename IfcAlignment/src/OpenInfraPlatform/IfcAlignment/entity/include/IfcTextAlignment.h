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
		// TYPE IfcTextAlignment = STRING;
		class IfcTextAlignment : public IfcAlignmentP6Type
		{
		public:
			IfcTextAlignment();
			IfcTextAlignment( std::string value );
			~IfcTextAlignment();
			virtual const char* classname() const { return "IfcTextAlignment"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTextAlignment> readStepData( std::string& arg );
			std::string m_value;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

