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
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcObjectTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRelAssignsToResource.h"
#include "include/IfcResource.h"
#include "include/IfcResourceSelect.h"
#include "include/IfcText.h"
#include "include/IfcTypeResource.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcRelAssignsToResource 
		IfcRelAssignsToResource::IfcRelAssignsToResource() { m_entity_enum = IFCRELASSIGNSTORESOURCE; }
		IfcRelAssignsToResource::IfcRelAssignsToResource( int id ) { m_id = id; m_entity_enum = IFCRELASSIGNSTORESOURCE; }
		IfcRelAssignsToResource::~IfcRelAssignsToResource() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRelAssignsToResource::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcRelAssignsToResource> other = dynamic_pointer_cast<IfcRelAssignsToResource>(other_entity);
			if( !other) { return; }
			m_GlobalId = other->m_GlobalId;
			m_OwnerHistory = other->m_OwnerHistory;
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_RelatedObjects = other->m_RelatedObjects;
			m_RelatedObjectsType = other->m_RelatedObjectsType;
			m_RelatingResource = other->m_RelatingResource;
		}
		void IfcRelAssignsToResource::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRELASSIGNSTORESOURCE" << "(";
			if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_RelatedObjects );
			stream << ",";
			if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RelatingResource ) { m_RelatingResource->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRelAssignsToResource::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRelAssignsToResource::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssignsToResource, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcRelAssignsToResource, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_GlobalId = IfcGloballyUniqueId::readStepData( args[0] );
			readEntityReference( args[1], m_OwnerHistory, map );
			m_Name = IfcLabel::readStepData( args[2] );
			m_Description = IfcText::readStepData( args[3] );
			readEntityReferenceList( args[4], m_RelatedObjects, map );
			m_RelatedObjectsType = IfcObjectTypeEnum::readStepData( args[5] );
			m_RelatingResource = IfcResourceSelect::readStepData( args[6], map );
		}
		void IfcRelAssignsToResource::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcRelAssigns::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcRelAssignsToResource> ptr_self = dynamic_pointer_cast<IfcRelAssignsToResource>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcRelAssignsToResource::setInverseCounterparts: type mismatch" ); }
			shared_ptr<IfcResource>  RelatingResource_IfcResource = dynamic_pointer_cast<IfcResource>( m_RelatingResource );
			if( RelatingResource_IfcResource )
			{
				RelatingResource_IfcResource->m_ResourceOf_inverse.push_back( ptr_self );
			}
			shared_ptr<IfcTypeResource>  RelatingResource_IfcTypeResource = dynamic_pointer_cast<IfcTypeResource>( m_RelatingResource );
			if( RelatingResource_IfcTypeResource )
			{
				RelatingResource_IfcTypeResource->m_ResourceOf_inverse.push_back( ptr_self );
			}
		}
		void IfcRelAssignsToResource::unlinkSelf()
		{
			IfcRelAssigns::unlinkSelf();
			shared_ptr<IfcResource>  RelatingResource_IfcResource = dynamic_pointer_cast<IfcResource>( m_RelatingResource );
			if( RelatingResource_IfcResource )
			{
				std::vector<weak_ptr<IfcRelAssignsToResource> >& ResourceOf_inverse = RelatingResource_IfcResource->m_ResourceOf_inverse;
				std::vector<weak_ptr<IfcRelAssignsToResource> >::iterator it_ResourceOf_inverse;
				for( it_ResourceOf_inverse = ResourceOf_inverse.begin(); it_ResourceOf_inverse != ResourceOf_inverse.end(); ++it_ResourceOf_inverse)
				{
					shared_ptr<IfcRelAssignsToResource> self_candidate( *it_ResourceOf_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ResourceOf_inverse.erase( it_ResourceOf_inverse );
						break;
					}
				}
			}
			shared_ptr<IfcTypeResource>  RelatingResource_IfcTypeResource = dynamic_pointer_cast<IfcTypeResource>( m_RelatingResource );
			if( RelatingResource_IfcTypeResource )
			{
				std::vector<weak_ptr<IfcRelAssignsToResource> >& ResourceOf_inverse = RelatingResource_IfcTypeResource->m_ResourceOf_inverse;
				std::vector<weak_ptr<IfcRelAssignsToResource> >::iterator it_ResourceOf_inverse;
				for( it_ResourceOf_inverse = ResourceOf_inverse.begin(); it_ResourceOf_inverse != ResourceOf_inverse.end(); ++it_ResourceOf_inverse)
				{
					shared_ptr<IfcRelAssignsToResource> self_candidate( *it_ResourceOf_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						ResourceOf_inverse.erase( it_ResourceOf_inverse );
						break;
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
