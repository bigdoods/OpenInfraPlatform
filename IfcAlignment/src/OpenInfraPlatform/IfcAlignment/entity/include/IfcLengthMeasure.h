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
#include "IfcBendingParameterSelect.h"
#include "IfcMeasureValue.h"
#include "IfcSizeSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcLengthMeasure = REAL;
		class IfcLengthMeasure : public IfcBendingParameterSelect, public IfcMeasureValue, public IfcSizeSelect, public IfcAlignmentP6Type
		{
		public:
			IfcLengthMeasure();
			IfcLengthMeasure( double value );
			~IfcLengthMeasure();
			virtual const char* classname() const { return "IfcLengthMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLengthMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

