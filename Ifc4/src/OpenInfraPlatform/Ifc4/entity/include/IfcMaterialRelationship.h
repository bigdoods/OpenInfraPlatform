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
#include "IfcResourceLevelRelationship.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcMaterial;
		class IfcLabel;
		//ENTITY
		class IfcMaterialRelationship : public IfcResourceLevelRelationship
		{
		public:
			IfcMaterialRelationship();
			IfcMaterialRelationship( int id );
			~IfcMaterialRelationship();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterialRelationship"; }


			// IfcResourceLevelRelationship -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcMaterialRelationship -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcMaterial>						m_RelatingMaterial;
			std::vector<shared_ptr<IfcMaterial> >		m_RelatedMaterials;
			shared_ptr<IfcLabel>							m_Expression;				//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

