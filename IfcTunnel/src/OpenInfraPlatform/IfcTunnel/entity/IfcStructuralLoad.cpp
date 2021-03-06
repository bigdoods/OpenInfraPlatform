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
#include "include/IfcLabel.h"
#include "include/IfcStructuralLoad.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcStructuralLoad 
		IfcStructuralLoad::IfcStructuralLoad() { m_entity_enum = IFCSTRUCTURALLOAD; }
		IfcStructuralLoad::IfcStructuralLoad( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOAD; }
		IfcStructuralLoad::~IfcStructuralLoad() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoad::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcStructuralLoad> other = dynamic_pointer_cast<IfcStructuralLoad>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcStructuralLoad::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOAD" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoad::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoad::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoad, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoad, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcStructuralLoad::setInverseCounterparts( shared_ptr<IfcTunnelEntity> )
		{
		}
		void IfcStructuralLoad::unlinkSelf()
		{
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
