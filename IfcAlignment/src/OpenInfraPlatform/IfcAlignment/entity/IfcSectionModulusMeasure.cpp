/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcSectionModulusMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcSectionModulusMeasure 
		IfcSectionModulusMeasure::IfcSectionModulusMeasure() {}
		IfcSectionModulusMeasure::IfcSectionModulusMeasure( double value ) { m_value = value; }
		IfcSectionModulusMeasure::~IfcSectionModulusMeasure() {}
		void IfcSectionModulusMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSECTIONMODULUSMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSectionModulusMeasure> IfcSectionModulusMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSectionModulusMeasure>(); }
			shared_ptr<IfcSectionModulusMeasure> type_object( new IfcSectionModulusMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
