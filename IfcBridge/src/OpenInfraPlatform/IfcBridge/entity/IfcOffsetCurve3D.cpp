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
#include "include/IfcCurve.h"
#include "include/IfcDirection.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcOffsetCurve3D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcOffsetCurve3D 
		IfcOffsetCurve3D::IfcOffsetCurve3D() { m_entity_enum = IFCOFFSETCURVE3D; }
		IfcOffsetCurve3D::IfcOffsetCurve3D( int id ) { m_id = id; m_entity_enum = IFCOFFSETCURVE3D; }
		IfcOffsetCurve3D::~IfcOffsetCurve3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOffsetCurve3D::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcOffsetCurve3D> other = dynamic_pointer_cast<IfcOffsetCurve3D>(other_entity);
			if( !other) { return; }
			m_BasisCurve = other->m_BasisCurve;
			m_Distance = other->m_Distance;
			m_SelfIntersect = other->m_SelfIntersect;
			m_RefDirection = other->m_RefDirection;
		}
		void IfcOffsetCurve3D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOFFSETCURVE3D" << "(";
			if( m_BasisCurve ) { stream << "#" << m_BasisCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Distance ) { m_Distance->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SelfIntersect == false ) { stream << ".F."; }
			else if( m_SelfIntersect == true ) { stream << ".T."; }
			stream << ",";
			if( m_RefDirection ) { stream << "#" << m_RefDirection->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcOffsetCurve3D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOffsetCurve3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOffsetCurve3D, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcOffsetCurve3D, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisCurve, map );
			m_Distance = IfcLengthMeasure::readStepData( args[1] );
			if( _stricmp( args[2].c_str(), ".F." ) == 0 ) { m_SelfIntersect = false; }
			else if( _stricmp( args[2].c_str(), ".T." ) == 0 ) { m_SelfIntersect = true; }
			readEntityReference( args[3], m_RefDirection, map );
		}
		void IfcOffsetCurve3D::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOffsetCurve3D::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
