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
#include "IfcParameterizedProfileDef.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcPositiveLengthMeasure;
		class IfcNonNegativeLengthMeasure;
		class IfcPlaneAngleMeasure;
		//ENTITY
		class IfcLShapeProfileDef : public IfcParameterizedProfileDef
		{
		public:
			IfcLShapeProfileDef();
			IfcLShapeProfileDef( int id );
			~IfcLShapeProfileDef();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLShapeProfileDef"; }


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

			// IfcLShapeProfileDef -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPositiveLengthMeasure>			m_Depth;
			shared_ptr<IfcPositiveLengthMeasure>			m_Width;					//optional
			shared_ptr<IfcPositiveLengthMeasure>			m_Thickness;
			shared_ptr<IfcNonNegativeLengthMeasure>		m_FilletRadius;				//optional
			shared_ptr<IfcNonNegativeLengthMeasure>		m_EdgeRadius;				//optional
			shared_ptr<IfcPlaneAngleMeasure>				m_LegSlope;					//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

