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
#include "IfcParameterizedProfileDef.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcPositiveLengthMeasure;
		class IfcNonNegativeLengthMeasure;
		//ENTITY
		class IfcZShapeProfileDef : public IfcParameterizedProfileDef
		{
		public:
			IfcZShapeProfileDef();
			IfcZShapeProfileDef( int id );
			~IfcZShapeProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcZShapeProfileDef"; }


			// IfcProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcProfileTypeEnum>				m_ProfileType;
			//  shared_ptr<IfcLabel>							m_ProfileName;				//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
			//  std::vector<weak_ptr<IfcProfileProperties> >	m_HasProperties_inverse;

			// IfcParameterizedProfileDef -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcAxis2Placement2D>				m_Position;					//optional

			// IfcZShapeProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_Depth;
			shared_ptr<IfcPositiveLengthMeasure>			m_FlangeWidth;
			shared_ptr<IfcPositiveLengthMeasure>			m_WebThickness;
			shared_ptr<IfcPositiveLengthMeasure>			m_FlangeThickness;
			shared_ptr<IfcNonNegativeLengthMeasure>		m_FilletRadius;				//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_EdgeRadius;				//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

