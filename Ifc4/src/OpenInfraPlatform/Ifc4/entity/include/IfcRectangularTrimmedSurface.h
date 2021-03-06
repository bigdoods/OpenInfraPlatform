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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcBoundedSurface.h"
#include "ifcParameterValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcSurface;
		//class IfcParameterValue;
		//class IfcBoolean;
		//ENTITY
		class IfcRectangularTrimmedSurface : public IfcBoundedSurface
		{
		public:
			IfcRectangularTrimmedSurface();
			IfcRectangularTrimmedSurface( int id );
			~IfcRectangularTrimmedSurface();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRectangularTrimmedSurface"; }


			// IfcRepresentationItem -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
			//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

			// IfcGeometricRepresentationItem -----------------------------------------------------------

			// IfcSurface -----------------------------------------------------------

			// IfcBoundedSurface -----------------------------------------------------------

			// IfcRectangularTrimmedSurface -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcSurface>						m_BasisSurface;
			shared_ptr<IfcParameterValue>				m_U1;
			shared_ptr<IfcParameterValue>				m_V1;
			shared_ptr<IfcParameterValue>				m_U2;
			shared_ptr<IfcParameterValue>				m_V2;
			bool										m_Usense;
			bool										m_Vsense;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

