/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcBlock.h"
#include "include/IfcPositiveLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcBlock 
		IfcBlock::IfcBlock() { m_entity_enum = IFCBLOCK; }
		IfcBlock::IfcBlock( int id ) { m_id = id; m_entity_enum = IFCBLOCK; }
		IfcBlock::~IfcBlock() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBlock::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcBlock> other = dynamic_pointer_cast<IfcBlock>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
			m_XLength = other->m_XLength;
			m_YLength = other->m_YLength;
			m_ZLength = other->m_ZLength;
		}
		void IfcBlock::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBLOCK" << "(";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_XLength ) { m_XLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_YLength ) { m_YLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ZLength ) { m_ZLength->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBlock::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBlock::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBlock, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcBlock, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Position, map );
			m_XLength = IfcPositiveLengthMeasure::readStepData( args[1] );
			m_YLength = IfcPositiveLengthMeasure::readStepData( args[2] );
			m_ZLength = IfcPositiveLengthMeasure::readStepData( args[3] );
		}
		void IfcBlock::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCsgPrimitive3D::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBlock::unlinkSelf()
		{
			IfcCsgPrimitive3D::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
