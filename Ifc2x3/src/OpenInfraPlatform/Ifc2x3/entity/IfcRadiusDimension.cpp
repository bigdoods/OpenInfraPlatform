/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcDraughtingCalloutElement.h"
#include "include/IfcDraughtingCalloutRelationship.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRadiusDimension.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcRadiusDimension 
		IfcRadiusDimension::IfcRadiusDimension() { m_entity_enum = IFCRADIUSDIMENSION; }
		IfcRadiusDimension::IfcRadiusDimension( int id ) { m_id = id; m_entity_enum = IFCRADIUSDIMENSION; }
		IfcRadiusDimension::~IfcRadiusDimension() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRadiusDimension::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcRadiusDimension> other = dynamic_pointer_cast<IfcRadiusDimension>(other_entity);
			if( !other) { return; }
			m_Contents = other->m_Contents;
		}
		void IfcRadiusDimension::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRADIUSDIMENSION" << "(";
			writeTypeList( stream, m_Contents, true );
			stream << ");";
		}
		void IfcRadiusDimension::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRadiusDimension::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRadiusDimension, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcRadiusDimension, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_Contents, map );
		}
		void IfcRadiusDimension::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcDimensionCurveDirectedCallout::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRadiusDimension::unlinkSelf()
		{
			IfcDimensionCurveDirectedCallout::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
