/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcTypeProduct.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcDoorStyleOperationEnum;
		class IfcDoorStyleConstructionEnum;
		class IfcBoolean;
		//ENTITY
		class IfcDoorStyle : public IfcTypeProduct
		{
		public:
			IfcDoorStyle();
			IfcDoorStyle( int id );
			~IfcDoorStyle();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDoorStyle"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcObjectDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssigns> >		m_HasAssignments_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >			m_Nests_inverse;
			//  std::vector<weak_ptr<IfcRelNests> >			m_IsNestedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDeclares> >		m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >		m_IsDecomposedBy_inverse;
			//  std::vector<weak_ptr<IfcRelAggregates> >		m_Decomposes_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >		m_HasAssociations_inverse;

			// IfcTypeObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcIdentifier>					m_ApplicableOccurrence;		//optional
			//  std::vector<shared_ptr<IfcPropertySetDefinition> >	m_HasPropertySets;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByType> >	m_Types_inverse;

			// IfcTypeProduct -----------------------------------------------------------
			// attributes:
			//  std::vector<shared_ptr<IfcRepresentationMap> >	m_RepresentationMaps;		//optional
			//  shared_ptr<IfcLabel>							m_Tag;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToProduct> >	m_ReferencedBy_inverse;

			// IfcDoorStyle -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDoorStyleOperationEnum>		m_OperationType;
			shared_ptr<IfcDoorStyleConstructionEnum>		m_ConstructionType;
			shared_ptr<IfcBoolean>						m_ParameterTakesPrecedence;
			shared_ptr<IfcBoolean>						m_Sizeable;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

