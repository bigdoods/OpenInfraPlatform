/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcCurveStyleFontPattern.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPositiveLengthMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcCurveStyleFontPattern 
		IfcCurveStyleFontPattern::IfcCurveStyleFontPattern() { m_entity_enum = IFCCURVESTYLEFONTPATTERN; }
		IfcCurveStyleFontPattern::IfcCurveStyleFontPattern( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLEFONTPATTERN; }
		IfcCurveStyleFontPattern::~IfcCurveStyleFontPattern() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveStyleFontPattern::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcCurveStyleFontPattern> other = dynamic_pointer_cast<IfcCurveStyleFontPattern>(other_entity);
			if( !other) { return; }
			m_VisibleSegmentLength = other->m_VisibleSegmentLength;
			m_InvisibleSegmentLength = other->m_InvisibleSegmentLength;
		}
		void IfcCurveStyleFontPattern::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVESTYLEFONTPATTERN" << "(";
			if( m_VisibleSegmentLength ) { m_VisibleSegmentLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InvisibleSegmentLength ) { m_InvisibleSegmentLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCurveStyleFontPattern::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveStyleFontPattern::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveStyleFontPattern, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCurveStyleFontPattern, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_VisibleSegmentLength = IfcLengthMeasure::readStepData( args[0] );
			m_InvisibleSegmentLength = IfcPositiveLengthMeasure::readStepData( args[1] );
		}
		void IfcCurveStyleFontPattern::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveStyleFontPattern::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
