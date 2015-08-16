/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcTunnelException.h"
#include "include/IfcDerivedMeasureValue.h"
#include "include/IfcSoundPowerLevelMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcSoundPowerLevelMeasure 
		IfcSoundPowerLevelMeasure::IfcSoundPowerLevelMeasure() {}
		IfcSoundPowerLevelMeasure::IfcSoundPowerLevelMeasure( double value ) { m_value = value; }
		IfcSoundPowerLevelMeasure::~IfcSoundPowerLevelMeasure() {}
		void IfcSoundPowerLevelMeasure::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSOUNDPOWERLEVELMEASURE("; }
			//supertype as attribute: double m_value
			stream << m_value;
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSoundPowerLevelMeasure> IfcSoundPowerLevelMeasure::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSoundPowerLevelMeasure>(); }
			shared_ptr<IfcSoundPowerLevelMeasure> type_object( new IfcSoundPowerLevelMeasure() );
			//supertype as attribute: double m_value
			type_object->m_value = atof( arg.c_str() );
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform