/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcRoleEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcRoleEnum 
		IfcRoleEnum::IfcRoleEnum() {}
		IfcRoleEnum::~IfcRoleEnum() {}
		void IfcRoleEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCROLEENUM("; }
			if( m_enum == ENUM_SUPPLIER )
			{
				stream << ".SUPPLIER.";
			}
			else if( m_enum == ENUM_MANUFACTURER )
			{
				stream << ".MANUFACTURER.";
			}
			else if( m_enum == ENUM_CONTRACTOR )
			{
				stream << ".CONTRACTOR.";
			}
			else if( m_enum == ENUM_SUBCONTRACTOR )
			{
				stream << ".SUBCONTRACTOR.";
			}
			else if( m_enum == ENUM_ARCHITECT )
			{
				stream << ".ARCHITECT.";
			}
			else if( m_enum == ENUM_STRUCTURALENGINEER )
			{
				stream << ".STRUCTURALENGINEER.";
			}
			else if( m_enum == ENUM_COSTENGINEER )
			{
				stream << ".COSTENGINEER.";
			}
			else if( m_enum == ENUM_CLIENT )
			{
				stream << ".CLIENT.";
			}
			else if( m_enum == ENUM_BUILDINGOWNER )
			{
				stream << ".BUILDINGOWNER.";
			}
			else if( m_enum == ENUM_BUILDINGOPERATOR )
			{
				stream << ".BUILDINGOPERATOR.";
			}
			else if( m_enum == ENUM_MECHANICALENGINEER )
			{
				stream << ".MECHANICALENGINEER.";
			}
			else if( m_enum == ENUM_ELECTRICALENGINEER )
			{
				stream << ".ELECTRICALENGINEER.";
			}
			else if( m_enum == ENUM_PROJECTMANAGER )
			{
				stream << ".PROJECTMANAGER.";
			}
			else if( m_enum == ENUM_FACILITIESMANAGER )
			{
				stream << ".FACILITIESMANAGER.";
			}
			else if( m_enum == ENUM_CIVILENGINEER )
			{
				stream << ".CIVILENGINEER.";
			}
			else if( m_enum == ENUM_COMMISSIONINGENGINEER )
			{
				stream << ".COMMISSIONINGENGINEER.";
			}
			else if( m_enum == ENUM_ENGINEER )
			{
				stream << ".ENGINEER.";
			}
			else if( m_enum == ENUM_OWNER )
			{
				stream << ".OWNER.";
			}
			else if( m_enum == ENUM_CONSULTANT )
			{
				stream << ".CONSULTANT.";
			}
			else if( m_enum == ENUM_CONSTRUCTIONMANAGER )
			{
				stream << ".CONSTRUCTIONMANAGER.";
			}
			else if( m_enum == ENUM_FIELDCONSTRUCTIONMANAGER )
			{
				stream << ".FIELDCONSTRUCTIONMANAGER.";
			}
			else if( m_enum == ENUM_RESELLER )
			{
				stream << ".RESELLER.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcRoleEnum> IfcRoleEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcRoleEnum>(); }
			shared_ptr<IfcRoleEnum> type_object( new IfcRoleEnum() );
			if( _stricmp( arg.c_str(), ".SUPPLIER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_SUPPLIER;
			}
			else if( _stricmp( arg.c_str(), ".MANUFACTURER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_MANUFACTURER;
			}
			else if( _stricmp( arg.c_str(), ".CONTRACTOR." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_CONTRACTOR;
			}
			else if( _stricmp( arg.c_str(), ".SUBCONTRACTOR." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_SUBCONTRACTOR;
			}
			else if( _stricmp( arg.c_str(), ".ARCHITECT." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_ARCHITECT;
			}
			else if( _stricmp( arg.c_str(), ".STRUCTURALENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_STRUCTURALENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".COSTENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_COSTENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".CLIENT." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_CLIENT;
			}
			else if( _stricmp( arg.c_str(), ".BUILDINGOWNER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_BUILDINGOWNER;
			}
			else if( _stricmp( arg.c_str(), ".BUILDINGOPERATOR." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_BUILDINGOPERATOR;
			}
			else if( _stricmp( arg.c_str(), ".MECHANICALENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_MECHANICALENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".ELECTRICALENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_ELECTRICALENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".PROJECTMANAGER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_PROJECTMANAGER;
			}
			else if( _stricmp( arg.c_str(), ".FACILITIESMANAGER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_FACILITIESMANAGER;
			}
			else if( _stricmp( arg.c_str(), ".CIVILENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_CIVILENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".COMMISSIONINGENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_COMMISSIONINGENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".ENGINEER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_ENGINEER;
			}
			else if( _stricmp( arg.c_str(), ".OWNER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_OWNER;
			}
			else if( _stricmp( arg.c_str(), ".CONSULTANT." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_CONSULTANT;
			}
			else if( _stricmp( arg.c_str(), ".CONSTRUCTIONMANAGER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_CONSTRUCTIONMANAGER;
			}
			else if( _stricmp( arg.c_str(), ".FIELDCONSTRUCTIONMANAGER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_FIELDCONSTRUCTIONMANAGER;
			}
			else if( _stricmp( arg.c_str(), ".RESELLER." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_RESELLER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcRoleEnum::ENUM_USERDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
