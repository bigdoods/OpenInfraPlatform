/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcRotationalStiffnessSelect.h"
#include "include/IfcRotationalStiffnessMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcRotationalStiffnessMeasure 
		IfcRotationalStiffnessMeasure::IfcRotationalStiffnessMeasure() {}
		IfcRotationalStiffnessMeasure::IfcRotationalStiffnessMeasure( double value ) { m_value = value; }
		IfcRotationalStiffnessMeasure::~IfcRotationalStiffnessMeasure() {}
		void IfcRotationalStiffnessMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCROTATIONALSTIFFNESSMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcRotationalStiffnessMeasure> IfcRotationalStiffnessMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRotationalStiffnessMeasure>(); }
			shared_ptr<IfcRotationalStiffnessMeasure> type_object( new IfcRotationalStiffnessMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
