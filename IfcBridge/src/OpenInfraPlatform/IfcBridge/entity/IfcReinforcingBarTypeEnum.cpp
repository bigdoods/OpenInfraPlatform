/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/IfcBridgeException.h"
#include "include/IfcReinforcingBarTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcReinforcingBarTypeEnum 
		IfcReinforcingBarTypeEnum::IfcReinforcingBarTypeEnum() {}
		IfcReinforcingBarTypeEnum::~IfcReinforcingBarTypeEnum() {}
		void IfcReinforcingBarTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCREINFORCINGBARTYPEENUM("; }
			if( m_enum == ENUM_ANCHORING )
			{
				stream << ".ANCHORING.";
			}
			else if( m_enum == ENUM_EDGE )
			{
				stream << ".EDGE.";
			}
			else if( m_enum == ENUM_LIGATURE )
			{
				stream << ".LIGATURE.";
			}
			else if( m_enum == ENUM_MAIN )
			{
				stream << ".MAIN.";
			}
			else if( m_enum == ENUM_PUNCHING )
			{
				stream << ".PUNCHING.";
			}
			else if( m_enum == ENUM_RING )
			{
				stream << ".RING.";
			}
			else if( m_enum == ENUM_SHEAR )
			{
				stream << ".SHEAR.";
			}
			else if( m_enum == ENUM_STUD )
			{
				stream << ".STUD.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcReinforcingBarTypeEnum> IfcReinforcingBarTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcReinforcingBarTypeEnum>(); }
			shared_ptr<IfcReinforcingBarTypeEnum> type_object( new IfcReinforcingBarTypeEnum() );
			if( _stricmp( arg.c_str(), ".ANCHORING." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_ANCHORING;
			}
			else if( _stricmp( arg.c_str(), ".EDGE." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_EDGE;
			}
			else if( _stricmp( arg.c_str(), ".LIGATURE." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_LIGATURE;
			}
			else if( _stricmp( arg.c_str(), ".MAIN." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_MAIN;
			}
			else if( _stricmp( arg.c_str(), ".PUNCHING." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_PUNCHING;
			}
			else if( _stricmp( arg.c_str(), ".RING." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_RING;
			}
			else if( _stricmp( arg.c_str(), ".SHEAR." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_SHEAR;
			}
			else if( _stricmp( arg.c_str(), ".STUD." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_STUD;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcReinforcingBarTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
