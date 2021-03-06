/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcCartesianPointList2D.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcCartesianPointList2D 
		IfcCartesianPointList2D::IfcCartesianPointList2D() { m_entity_enum = IFCCARTESIANPOINTLIST2D; }
		IfcCartesianPointList2D::IfcCartesianPointList2D( int id ) { m_id = id; m_entity_enum = IFCCARTESIANPOINTLIST2D; }
		IfcCartesianPointList2D::~IfcCartesianPointList2D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCartesianPointList2D::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcCartesianPointList2D> other = dynamic_pointer_cast<IfcCartesianPointList2D>(other_entity);
			if( !other) { return; }
			m_CoordList = other->m_CoordList;
		}
		void IfcCartesianPointList2D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCARTESIANPOINTLIST2D" << "(";
			writeTypeOfRealList2D( stream, m_CoordList );
			stream << ");";
		}
		void IfcCartesianPointList2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCartesianPointList2D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCartesianPointList2D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCartesianPointList2D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList2D( args[0], m_CoordList );
		}
		void IfcCartesianPointList2D::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcCartesianPointList::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCartesianPointList2D::unlinkSelf()
		{
			IfcCartesianPointList::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
