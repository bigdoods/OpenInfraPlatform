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
#include "include/IfcConnectionGeometry.h"
#include "include/IfcElement.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelConnectsElements.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRelConnectsElements 
		IfcRelConnectsElements::IfcRelConnectsElements() { m_entity_enum = IFCRELCONNECTSELEMENTS; }
		IfcRelConnectsElements::IfcRelConnectsElements( int id ) { m_id = id; m_entity_enum = IFCRELCONNECTSELEMENTS; }
		IfcRelConnectsElements::~IfcRelConnectsElements() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelConnectsElements::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRelConnectsElements> other = dynamic_pointer_cast<IfcRelConnectsElements>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_ConnectionGeometry = other->m_ConnectionGeometry;
			m_RelatingElement = other->m_RelatingElement;
			m_RelatedElement = other->m_RelatedElement;
		}
		void IfcRelConnectsElements::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELCONNECTSELEMENTS" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConnectionGeometry ) { stream << "#" << m_ConnectionGeometry->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingElement ) { stream << "#" << m_RelatingElement->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_RelatedElement ) { stream << "#" << m_RelatedElement->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelConnectsElements::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelConnectsElements::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelConnectsElements, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRelConnectsElements, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReference( args[4], m_ConnectionGeometry, map );
			readEntityReference( args[5], m_RelatingElement, map );
			readEntityReference( args[6], m_RelatedElement, map );
		}
		void IfcRelConnectsElements::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcRelConnects::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelConnectsElements> ptr_self = dynamic_pointer_cast<IfcRelConnectsElements>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcRelConnectsElements::setInverseCounterparts: type mismatch" ); }
			if( m_RelatedElement )
			{
				m_RelatedElement->m_ConnectedFrom_inverse.push_back( ptr_self );
			}
			if( m_RelatingElement )
			{
				m_RelatingElement->m_ConnectedTo_inverse.push_back( ptr_self );
			}
		}
		void IfcRelConnectsElements::unlinkSelf()
		{
			IfcRelConnects::unlinkSelf();
			if( m_RelatedElement )
			{
				std::vector<weak_ptr<IfcRelConnectsElements> >& ConnectedFrom_inverse = m_RelatedElement->m_ConnectedFrom_inverse;
				std::vector<weak_ptr<IfcRelConnectsElements> >::iterator it_ConnectedFrom_inverse;
				for( it_ConnectedFrom_inverse = ConnectedFrom_inverse.begin(); it_ConnectedFrom_inverse != ConnectedFrom_inverse.end(); ++it_ConnectedFrom_inverse)
				{
					shared_ptr<IfcRelConnectsElements> self_candidate( *it_ConnectedFrom_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ConnectedFrom_inverse.erase( it_ConnectedFrom_inverse );
						break;
					}
				}
			}
			if( m_RelatingElement )
			{
				std::vector<weak_ptr<IfcRelConnectsElements> >& ConnectedTo_inverse = m_RelatingElement->m_ConnectedTo_inverse;
				std::vector<weak_ptr<IfcRelConnectsElements> >::iterator it_ConnectedTo_inverse;
				for( it_ConnectedTo_inverse = ConnectedTo_inverse.begin(); it_ConnectedTo_inverse != ConnectedTo_inverse.end(); ++it_ConnectedTo_inverse)
				{
					shared_ptr<IfcRelConnectsElements> self_candidate( *it_ConnectedTo_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ConnectedTo_inverse.erase( it_ConnectedTo_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
