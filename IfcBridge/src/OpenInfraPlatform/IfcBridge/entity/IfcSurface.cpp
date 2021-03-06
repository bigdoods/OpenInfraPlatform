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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcSurface 
		IfcSurface::IfcSurface() { m_entity_enum = IFCSURFACE; }
		IfcSurface::IfcSurface( int id ) { m_id = id; m_entity_enum = IFCSURFACE; }
		IfcSurface::~IfcSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurface::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcSurface> other = dynamic_pointer_cast<IfcSurface>(other_entity);
			if( !other) { return; }
		}
		void IfcSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACE" << "(";
			stream << ");";
		}
		void IfcSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
		}
		void IfcSurface::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurface::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
