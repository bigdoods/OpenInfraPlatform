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
		// TYPE IfcDayInMonthNumber = INTEGER;
		class IfcDayInMonthNumber : public IfcTunnelType
		{
		public:
			IfcDayInMonthNumber();
			IfcDayInMonthNumber( int value );
			~IfcDayInMonthNumber();
			virtual const char* classname() const { return "IfcDayInMonthNumber"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDayInMonthNumber> readStepData( std::string& arg );
			int m_value;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

