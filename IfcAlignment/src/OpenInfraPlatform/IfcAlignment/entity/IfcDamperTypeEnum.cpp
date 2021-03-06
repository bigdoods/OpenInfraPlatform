/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcDamperTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcDamperTypeEnum 
		IfcDamperTypeEnum::IfcDamperTypeEnum() {}
		IfcDamperTypeEnum::~IfcDamperTypeEnum() {}
		void IfcDamperTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDAMPERTYPEENUM("; }
			if( m_enum == ENUM_BACKDRAFTDAMPER )
			{
				stream << ".BACKDRAFTDAMPER.";
			}
			else if( m_enum == ENUM_BALANCINGDAMPER )
			{
				stream << ".BALANCINGDAMPER.";
			}
			else if( m_enum == ENUM_BLASTDAMPER )
			{
				stream << ".BLASTDAMPER.";
			}
			else if( m_enum == ENUM_CONTROLDAMPER )
			{
				stream << ".CONTROLDAMPER.";
			}
			else if( m_enum == ENUM_FIREDAMPER )
			{
				stream << ".FIREDAMPER.";
			}
			else if( m_enum == ENUM_FIRESMOKEDAMPER )
			{
				stream << ".FIRESMOKEDAMPER.";
			}
			else if( m_enum == ENUM_FUMEHOODEXHAUST )
			{
				stream << ".FUMEHOODEXHAUST.";
			}
			else if( m_enum == ENUM_GRAVITYDAMPER )
			{
				stream << ".GRAVITYDAMPER.";
			}
			else if( m_enum == ENUM_GRAVITYRELIEFDAMPER )
			{
				stream << ".GRAVITYRELIEFDAMPER.";
			}
			else if( m_enum == ENUM_RELIEFDAMPER )
			{
				stream << ".RELIEFDAMPER.";
			}
			else if( m_enum == ENUM_SMOKEDAMPER )
			{
				stream << ".SMOKEDAMPER.";
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
		shared_ptr<IfcDamperTypeEnum> IfcDamperTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDamperTypeEnum>(); }
			shared_ptr<IfcDamperTypeEnum> type_object( new IfcDamperTypeEnum() );
			if( _stricmp( arg.c_str(), ".BACKDRAFTDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_BACKDRAFTDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".BALANCINGDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_BALANCINGDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".BLASTDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_BLASTDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".CONTROLDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_CONTROLDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".FIREDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_FIREDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".FIRESMOKEDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_FIRESMOKEDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".FUMEHOODEXHAUST." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_FUMEHOODEXHAUST;
			}
			else if( _stricmp( arg.c_str(), ".GRAVITYDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_GRAVITYDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".GRAVITYRELIEFDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_GRAVITYRELIEFDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".RELIEFDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_RELIEFDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".SMOKEDAMPER." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_SMOKEDAMPER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDamperTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
