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
#include "IfcExtrudedAreaSolid.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcProfileDef;
		//ENTITY
		class IfcExtrudedAreaSolidTapered : public IfcExtrudedAreaSolid
		{
		public:
			IfcExtrudedAreaSolidTapered();
			IfcExtrudedAreaSolidTapered( int id );
			~IfcExtrudedAreaSolidTapered();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcExtrudedAreaSolidTapered"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcSolidModel -----------------------------------------------------------

			// IfcSweptAreaSolid -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcProfileDef>					m_SweptArea;
			//  shared_ptr<IfcAxis2Placement3D>				m_Position;					//optional

			// IfcExtrudedAreaSolid -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDirection>						m_ExtrudedDirection;
			//  shared_ptr<IfcPositiveLengthMeasure>			m_Depth;

			// IfcExtrudedAreaSolidTapered -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcProfileDef>					m_EndSweptArea;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
