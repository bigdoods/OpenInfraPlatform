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
#include "IfcPresentationItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLabel;
		//ENTITY
		class IfcPreDefinedItem : public IfcPresentationItem
		{
		public:
			IfcPreDefinedItem();
			IfcPreDefinedItem( int id );
			~IfcPreDefinedItem();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPreDefinedItem"; }


			// IfcPresentationItem -----------------------------------------------------------

			// IfcPreDefinedItem -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>							m_Name;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

