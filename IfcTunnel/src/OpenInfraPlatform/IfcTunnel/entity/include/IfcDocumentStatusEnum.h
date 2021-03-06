/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcDocumentStatusEnum = ENUMERATION OF	(DRAFT	,FINALDRAFT	,FINAL	,REVISION	,NOTDEFINED);
		class IfcDocumentStatusEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDocumentStatusEnumEnum
			{
				ENUM_DRAFT,
				ENUM_FINALDRAFT,
				ENUM_FINAL,
				ENUM_REVISION,
				ENUM_NOTDEFINED
			};

			IfcDocumentStatusEnum();
			IfcDocumentStatusEnum( IfcDocumentStatusEnumEnum e ) { m_enum = e; }
			~IfcDocumentStatusEnum();
			virtual const char* classname() const { return "IfcDocumentStatusEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDocumentStatusEnum> readStepData( std::string& arg );
			IfcDocumentStatusEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

