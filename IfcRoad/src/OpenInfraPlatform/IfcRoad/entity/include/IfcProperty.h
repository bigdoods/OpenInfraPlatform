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
#include "IfcPropertyAbstraction.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcIdentifier;
		class IfcText;
		class IfcPropertySet;
		class IfcResourceApprovalRelationship;
		class IfcResourceConstraintRelationship;
		class IfcPropertyDependencyRelationship;
		class IfcComplexProperty;
		//ENTITY
		class IfcProperty : public IfcPropertyAbstraction
		{
		public:
			IfcProperty();
			IfcProperty( int id );
			~IfcProperty();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcProperty"; }


			// IfcPropertyAbstraction -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >		m_HasExternalReferences_inverse;

			// IfcProperty -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>									m_Name;
			shared_ptr<IfcText>											m_Description;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcPropertySet> >						m_PartOfPset_inverse;
			std::vector<weak_ptr<IfcResourceApprovalRelationship> >		m_HasApprovals_inverse;
			std::vector<weak_ptr<IfcResourceConstraintRelationship> >	m_HasConstraints_inverse;
			std::vector<weak_ptr<IfcPropertyDependencyRelationship> >	m_PropertyForDependance_inverse;
			std::vector<weak_ptr<IfcPropertyDependencyRelationship> >	m_PropertyDependsOn_inverse;
			std::vector<weak_ptr<IfcComplexProperty> >					m_PartOfComplex_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

