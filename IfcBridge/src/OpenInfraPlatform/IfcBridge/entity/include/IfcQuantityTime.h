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
#include "IfcPhysicalSimpleQuantity.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcTimeMeasure;
		class IfcLabel;
		//ENTITY
		class IfcQuantityTime : public IfcPhysicalSimpleQuantity
		{
		public:
			IfcQuantityTime();
			IfcQuantityTime( int id );
			~IfcQuantityTime();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcQuantityTime"; }


			// IfcPhysicalQuantity -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;
			//  shared_ptr<IfcText>							m_Description;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReferences_inverse;
			//  std::vector<weak_ptr<IfcPhysicalComplexQuantity> >	m_PartOfComplex_inverse;

			// IfcPhysicalSimpleQuantity -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcNamedUnit>						m_Unit;						//optional

			// IfcQuantityTime -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcTimeMeasure>					m_TimeValue;
			shared_ptr<IfcLabel>							m_Formula;					//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

