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
#include "IfcClassificationReferenceSelect.h"
#include "IfcClassificationSelect.h"
#include "IfcExternalInformation.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcLabel;
		class IfcDate;
		class IfcText;
		class IfcURIReference;
		class IfcIdentifier;
		class IfcRelAssociatesClassification;
		class IfcClassificationReference;
		//ENTITY
		class IfcClassification : public IfcClassificationReferenceSelect, public IfcClassificationSelect, public IfcExternalInformation
		{
		public:
			IfcClassification();
			IfcClassification( int id );
			~IfcClassification();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcClassification"; }


			// IfcExternalInformation -----------------------------------------------------------

			// IfcClassification -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>										m_Source;					//optional
			shared_ptr<IfcLabel>										m_Edition;					//optional
			shared_ptr<IfcDate>										m_EditionDate;				//optional
			shared_ptr<IfcLabel>										m_Name;
			shared_ptr<IfcText>										m_Description;				//optional
			shared_ptr<IfcURIReference>								m_Location;					//optional
			std::vector<shared_ptr<IfcIdentifier> >					m_ReferenceTokens;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelAssociatesClassification> >	m_ClassificationForObjects_inverse;
			std::vector<weak_ptr<IfcClassificationReference> >		m_HasReferences_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

