/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcFaceSurface.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		//ENTITY
		class IfcAdvancedFace : public IfcFaceSurface
		{
		public:
			IfcAdvancedFace();
			IfcAdvancedFace( int id );
			~IfcAdvancedFace();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAdvancedFace"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcTopologicalRepresentationItem -----------------------------------------------------------

			// IfcFace -----------------------------------------------------------
			// attributes:
			//  std::vector<shared_ptr<IfcFaceBound> >		m_Bounds;
			// inverse attributes:
			//  std::vector<weak_ptr<IfcTextureMap> >		m_HasTextureMaps_inverse;

			// IfcFaceSurface -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcSurface>						m_FaceSurface;
			//  shared_ptr<IfcBoolean>						m_SameSense;

			// IfcAdvancedFace -----------------------------------------------------------
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

