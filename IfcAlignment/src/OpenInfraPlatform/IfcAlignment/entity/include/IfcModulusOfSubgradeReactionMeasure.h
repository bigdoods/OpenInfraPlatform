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
#include "IfcDerivedMeasureValue.h"
#include "IfcModulusOfSubgradeReactionSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcModulusOfSubgradeReactionMeasure = REAL;
		class IfcModulusOfSubgradeReactionMeasure : public IfcDerivedMeasureValue, public IfcModulusOfSubgradeReactionSelect, public IfcAlignmentP6Type
		{
		public:
			IfcModulusOfSubgradeReactionMeasure();
			IfcModulusOfSubgradeReactionMeasure( double value );
			~IfcModulusOfSubgradeReactionMeasure();
			virtual const char* classname() const { return "IfcModulusOfSubgradeReactionMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcModulusOfSubgradeReactionMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

