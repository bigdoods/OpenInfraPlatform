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
#include "IfcFillStyleSelect.h"
#include "IfcExternalReference.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		//ENTITY
		class IfcExternallyDefinedHatchStyle : public IfcFillStyleSelect, public IfcExternalReference
		{
		public:
			IfcExternallyDefinedHatchStyle();
			IfcExternallyDefinedHatchStyle( int id );
			~IfcExternallyDefinedHatchStyle();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcExternallyDefinedHatchStyle"; }


			// IfcExternalReference -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcURIReference>					m_Location;					//optional
			//  shared_ptr<IfcIdentifier>					m_Identification;			//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_ExternalReferenceForResources_inverse;

			// IfcExternallyDefinedHatchStyle -----------------------------------------------------------
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

