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
#include "IfcExtendedProperties.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcMaterialDefinition;
		//ENTITY
		class IfcMaterialProperties : public IfcExtendedProperties
		{
		public:
			IfcMaterialProperties();
			IfcMaterialProperties( int id );
			~IfcMaterialProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterialProperties"; }


			// IfcPropertyAbstraction -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;

			// IfcExtendedProperties -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  std::vector<shared_ptr<IfcProperty> >		m_Properties;

			// IfcMaterialProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMaterialDefinition>			m_Material;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

