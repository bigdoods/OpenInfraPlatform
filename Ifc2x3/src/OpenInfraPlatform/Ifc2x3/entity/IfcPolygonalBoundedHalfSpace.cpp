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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcBoundedCurve.h"
#include "include/IfcPolygonalBoundedHalfSpace.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPolygonalBoundedHalfSpace 
		IfcPolygonalBoundedHalfSpace::IfcPolygonalBoundedHalfSpace() { m_entity_enum = IFCPOLYGONALBOUNDEDHALFSPACE; }
		IfcPolygonalBoundedHalfSpace::IfcPolygonalBoundedHalfSpace( int id ) { m_id = id; m_entity_enum = IFCPOLYGONALBOUNDEDHALFSPACE; }
		IfcPolygonalBoundedHalfSpace::~IfcPolygonalBoundedHalfSpace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPolygonalBoundedHalfSpace::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPolygonalBoundedHalfSpace> other = dynamic_pointer_cast<IfcPolygonalBoundedHalfSpace>(other_entity);
			if( !other) { return; }
			m_BaseSurface = other->m_BaseSurface;
			m_AgreementFlag = other->m_AgreementFlag;
			m_Position = other->m_Position;
			m_PolygonalBoundary = other->m_PolygonalBoundary;
		}
		void IfcPolygonalBoundedHalfSpace::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPOLYGONALBOUNDEDHALFSPACE" << "(";
			if( m_BaseSurface ) { stream << "#" << m_BaseSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AgreementFlag == false ) { stream << ".F."; }
			else if( m_AgreementFlag == true ) { stream << ".T."; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_PolygonalBoundary ) { stream << "#" << m_PolygonalBoundary->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPolygonalBoundedHalfSpace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPolygonalBoundedHalfSpace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPolygonalBoundedHalfSpace, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcPolygonalBoundedHalfSpace, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BaseSurface, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_AgreementFlag = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_AgreementFlag = true; }
			readEntityReference( args[2], m_Position, map );
			readEntityReference( args[3], m_PolygonalBoundary, map );
		}
		void IfcPolygonalBoundedHalfSpace::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcHalfSpaceSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPolygonalBoundedHalfSpace::unlinkSelf()
		{
			IfcHalfSpaceSolid::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
