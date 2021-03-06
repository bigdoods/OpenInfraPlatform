/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcDimensionalExponents.h"
#include "include/IfcSIPrefix.h"
#include "include/IfcSIUnit.h"
#include "include/IfcSIUnitName.h"
#include "include/IfcUnitEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcSIUnit 
		IfcSIUnit::IfcSIUnit() { m_entity_enum = IFCSIUNIT; }
		IfcSIUnit::IfcSIUnit( int id ) { m_id = id; m_entity_enum = IFCSIUNIT; }
		IfcSIUnit::~IfcSIUnit() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSIUnit::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcSIUnit> other = dynamic_pointer_cast<IfcSIUnit>(other_entity);
			if( !other) { return; }
			m_Dimensions = other->m_Dimensions;
			m_UnitType = other->m_UnitType;
			m_Prefix = other->m_Prefix;
			m_Name = other->m_Name;
		}
		void IfcSIUnit::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSIUNIT" << "(";
			if( m_Dimensions ) { stream << "#" << m_Dimensions->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_UnitType ) { m_UnitType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Prefix ) { m_Prefix->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSIUnit::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSIUnit::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSIUnit, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcSIUnit, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Dimensions, map );
			m_UnitType = IfcUnitEnum::readStepData( args[1] );
			m_Prefix = IfcSIPrefix::readStepData( args[2] );
			m_Name = IfcSIUnitName::readStepData( args[3] );
		}
		void IfcSIUnit::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcNamedUnit::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSIUnit::unlinkSelf()
		{
			IfcNamedUnit::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
