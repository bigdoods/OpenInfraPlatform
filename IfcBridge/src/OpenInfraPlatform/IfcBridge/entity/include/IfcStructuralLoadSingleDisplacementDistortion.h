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
#include "IfcStructuralLoadSingleDisplacement.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcCurvatureMeasure;
		//ENTITY
		class IfcStructuralLoadSingleDisplacementDistortion : public IfcStructuralLoadSingleDisplacement
		{
		public:
			IfcStructuralLoadSingleDisplacementDistortion();
			IfcStructuralLoadSingleDisplacementDistortion( int id );
			~IfcStructuralLoadSingleDisplacementDistortion();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcStructuralLoadSingleDisplacementDistortion"; }


			// IfcStructuralLoad -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcStructuralLoadOrResult -----------------------------------------------------------

			// IfcStructuralLoadStatic -----------------------------------------------------------

			// IfcStructuralLoadSingleDisplacement -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLengthMeasure>					m_DisplacementX;			//optional
			//  shared_ptr<IfcLengthMeasure>					m_DisplacementY;			//optional
			//  shared_ptr<IfcLengthMeasure>					m_DisplacementZ;			//optional
			//  shared_ptr<IfcPlaneAngleMeasure>				m_RotationalDisplacementRX;	//optional
			//  shared_ptr<IfcPlaneAngleMeasure>				m_RotationalDisplacementRY;	//optional
			//  shared_ptr<IfcPlaneAngleMeasure>				m_RotationalDisplacementRZ;	//optional

			// IfcStructuralLoadSingleDisplacementDistortion -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCurvatureMeasure>				m_Distortion;				//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

