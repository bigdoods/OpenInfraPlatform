/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"
#include "IfcShapeModel.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		//ENTITY
		class IfcTopologyRepresentation : public IfcShapeModel
		{
		public:
			IfcTopologyRepresentation();
			IfcTopologyRepresentation( int id );
			~IfcTopologyRepresentation();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTopologyRepresentation"; }


			// IfcRepresentation -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcRepresentationContext>			m_ContextOfItems;
			//  shared_ptr<IfcLabel>							m_RepresentationIdentifier;	//optional
			//  shared_ptr<IfcLabel>							m_RepresentationType;		//optional
			//  std::vector<shared_ptr<IfcRepresentationItem> >	m_Items;
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRepresentationMap> >	m_RepresentationMap_inverse;
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignments_inverse;
			//  std::vector<weak_ptr<IfcProductRepresentation> >	m_OfProductRepresentation_inverse;

			// IfcShapeModel -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcShapeAspect> >		m_OfShapeAspect_inverse;

			// IfcTopologyRepresentation -----------------------------------------------------------
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

