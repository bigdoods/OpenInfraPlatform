/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcBoundingBox.h"
#include "include/IfcBoxedHalfSpace.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcBoxedHalfSpace 
		IfcBoxedHalfSpace::IfcBoxedHalfSpace() { m_entity_enum = IFCBOXEDHALFSPACE; }
		IfcBoxedHalfSpace::IfcBoxedHalfSpace( int id ) { m_id = id; m_entity_enum = IFCBOXEDHALFSPACE; }
		IfcBoxedHalfSpace::~IfcBoxedHalfSpace() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoxedHalfSpace::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcBoxedHalfSpace> other = dynamic_pointer_cast<IfcBoxedHalfSpace>(other_entity);
			if( !other) { return; }
			m_BaseSurface = other->m_BaseSurface;
			m_AgreementFlag = other->m_AgreementFlag;
			m_Enclosure = other->m_Enclosure;
		}
		void IfcBoxedHalfSpace::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOXEDHALFSPACE" << "(";
			if( m_BaseSurface ) { stream << "#" << m_BaseSurface->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_AgreementFlag ) { m_AgreementFlag->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Enclosure ) { stream << "#" << m_Enclosure->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBoxedHalfSpace::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoxedHalfSpace::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBoxedHalfSpace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcBoxedHalfSpace, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BaseSurface, map );
			m_AgreementFlag = IfcBoolean::readStepData( args[1] );
			readEntityReference( args[2], m_Enclosure, map );
		}
		void IfcBoxedHalfSpace::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcHalfSpaceSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoxedHalfSpace::unlinkSelf()
		{
			IfcHalfSpaceSolid::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
