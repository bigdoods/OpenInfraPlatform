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
#include "IfcSpatialStructureElement.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcCompoundPlaneAngleMeasure;
		class IfcLengthMeasure;
		class IfcLabel;
		class IfcPostalAddress;
		//ENTITY
		class IfcSite : public IfcSpatialStructureElement
		{
		public:
			IfcSite();
			IfcSite( int id );
			~IfcSite();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSite"; }


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

			// IfcObject -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_ObjectType;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_IsDeclaredBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByObject> >	m_Declares_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByType> >	m_IsTypedBy_inverse;
			//  std::vector<weak_ptr<IfcRelDefinesByProperties> >	m_IsDefinedBy_inverse;

			// IfcProduct -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcObjectPlacement>				m_ObjectPlacement;			//optional
			//  shared_ptr<IfcProductRepresentation>			m_Representation;			//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssignsToProduct> >	m_ReferencedBy_inverse;

			// IfcSpatialElement -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_LongName;					//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelContainedInSpatialStructure> >	m_ContainsElements_inverse;
			//  std::vector<weak_ptr<IfcRelServicesBuildings> >	m_ServicedBySystems_inverse;
			//  std::vector<weak_ptr<IfcRelReferencedInSpatialStructure> >	m_ReferencesElements_inverse;

			// IfcSpatialStructureElement -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcElementCompositionEnum>		m_CompositionType;			//optional

			// IfcSite -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCompoundPlaneAngleMeasure>		m_RefLatitude;				//optional
			shared_ptr<IfcCompoundPlaneAngleMeasure>		m_RefLongitude;				//optional
			shared_ptr<IfcLengthMeasure>					m_RefElevation;				//optional
			shared_ptr<IfcLabel>							m_LandTitleNumber;			//optional
			shared_ptr<IfcPostalAddress>					m_SiteAddress;				//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

