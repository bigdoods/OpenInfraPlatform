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
#include "include/IfcColourRgb.h"
#include "include/IfcSurfaceStyleShading.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcSurfaceStyleShading 
		IfcSurfaceStyleShading::IfcSurfaceStyleShading() { m_entity_enum = IFCSURFACESTYLESHADING; }
		IfcSurfaceStyleShading::IfcSurfaceStyleShading( int id ) { m_id = id; m_entity_enum = IFCSURFACESTYLESHADING; }
		IfcSurfaceStyleShading::~IfcSurfaceStyleShading() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceStyleShading::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcSurfaceStyleShading> other = dynamic_pointer_cast<IfcSurfaceStyleShading>(other_entity);
			if( !other) { return; }
			m_SurfaceColour = other->m_SurfaceColour;
		}
		void IfcSurfaceStyleShading::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACESTYLESHADING" << "(";
			if( m_SurfaceColour ) { stream << "#" << m_SurfaceColour->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceStyleShading::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceStyleShading::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceStyleShading, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcSurfaceStyleShading, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SurfaceColour, map );
		}
		void IfcSurfaceStyleShading::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceStyleShading::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
