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
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMaterialLayer.h"
#include "include/IfcMaterialLayerSet.h"
#include "include/IfcMaterialProperties.h"
#include "include/IfcRelAssociatesMaterial.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcMaterialLayerSet 
		IfcMaterialLayerSet::IfcMaterialLayerSet() { m_entity_enum = IFCMATERIALLAYERSET; }
		IfcMaterialLayerSet::IfcMaterialLayerSet( int id ) { m_id = id; m_entity_enum = IFCMATERIALLAYERSET; }
		IfcMaterialLayerSet::~IfcMaterialLayerSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMaterialLayerSet::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcMaterialLayerSet> other = dynamic_pointer_cast<IfcMaterialLayerSet>(other_entity);
			if( !other) { return; }
			m_MaterialLayers = other->m_MaterialLayers;
			m_LayerSetName = other->m_LayerSetName;
			m_Description = other->m_Description;
		}
		void IfcMaterialLayerSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMATERIALLAYERSET" << "(";
			writeEntityList( stream, m_MaterialLayers );
			stream << ",";
			if( m_LayerSetName ) { m_LayerSetName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMaterialLayerSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMaterialLayerSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMaterialLayerSet, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcMaterialLayerSet, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_MaterialLayers, map );
			m_LayerSetName = IfcLabel::readStepData( args[1] );
			m_Description = IfcText::readStepData( args[2] );
		}
		void IfcMaterialLayerSet::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcMaterialDefinition::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcMaterialLayerSet> ptr_self = dynamic_pointer_cast<IfcMaterialLayerSet>( ptr_self_entity );
			if( !ptr_self ) { throw IfcTunnelException( "IfcMaterialLayerSet::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_MaterialLayers.size(); ++i )
			{
				if( m_MaterialLayers[i] )
				{
					m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse = ptr_self;
				}
			}
		}
		void IfcMaterialLayerSet::unlinkSelf()
		{
			IfcMaterialDefinition::unlinkSelf();
			for( int i=0; i<m_MaterialLayers.size(); ++i )
			{
				if( m_MaterialLayers[i] )
				{
					shared_ptr<IfcMaterialLayerSet> self_candidate( m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						weak_ptr<IfcMaterialLayerSet>& self_candidate_weak = m_MaterialLayers[i]->m_ToMaterialLayerSet_inverse;
						self_candidate_weak.reset();
					}
				}
			}
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
