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
#include "IfcCoordinateReferenceSystem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcIdentifier;
		class IfcNamedUnit;
		//ENTITY
		class IfcProjectedCRS : public IfcCoordinateReferenceSystem
		{
		public:
			IfcProjectedCRS();
			IfcProjectedCRS( int id );
			~IfcProjectedCRS();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcProjectedCRS"; }


			// IfcCoordinateReferenceSystem -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  shared_ptr<IfcIdentifier>					m_GeodeticDatum;
			//  shared_ptr<IfcIdentifier>					m_VerticalDatum;			//optional

			// IfcProjectedCRS -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>					m_MapProjection;			//optional
			shared_ptr<IfcIdentifier>					m_MapZone;					//optional
			shared_ptr<IfcNamedUnit>						m_MapUnit;					//optional
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

