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
#include "include/IfcLabel.h"
#include "include/IfcPreDefinedColour.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcPreDefinedColour 
		IfcPreDefinedColour::IfcPreDefinedColour() { m_entity_enum = IFCPREDEFINEDCOLOUR; }
		IfcPreDefinedColour::IfcPreDefinedColour( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDCOLOUR; }
		IfcPreDefinedColour::~IfcPreDefinedColour() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedColour::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcPreDefinedColour> other = dynamic_pointer_cast<IfcPreDefinedColour>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcPreDefinedColour::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDCOLOUR" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPreDefinedColour::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedColour::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPreDefinedColour, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPreDefinedColour, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcPreDefinedColour::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcPreDefinedItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedColour::unlinkSelf()
		{
			IfcPreDefinedItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
