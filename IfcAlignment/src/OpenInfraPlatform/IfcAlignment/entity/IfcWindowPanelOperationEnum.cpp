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
#include "include/IfcWindowPanelOperationEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcWindowPanelOperationEnum 
		IfcWindowPanelOperationEnum::IfcWindowPanelOperationEnum() {}
		IfcWindowPanelOperationEnum::~IfcWindowPanelOperationEnum() {}
		void IfcWindowPanelOperationEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCWINDOWPANELOPERATIONENUM("; }
			if( m_enum == ENUM_SIDEHUNGRIGHTHAND )
			{
				stream << ".SIDEHUNGRIGHTHAND.";
			}
			else if( m_enum == ENUM_SIDEHUNGLEFTHAND )
			{
				stream << ".SIDEHUNGLEFTHAND.";
			}
			else if( m_enum == ENUM_TILTANDTURNRIGHTHAND )
			{
				stream << ".TILTANDTURNRIGHTHAND.";
			}
			else if( m_enum == ENUM_TILTANDTURNLEFTHAND )
			{
				stream << ".TILTANDTURNLEFTHAND.";
			}
			else if( m_enum == ENUM_TOPHUNG )
			{
				stream << ".TOPHUNG.";
			}
			else if( m_enum == ENUM_BOTTOMHUNG )
			{
				stream << ".BOTTOMHUNG.";
			}
			else if( m_enum == ENUM_PIVOTHORIZONTAL )
			{
				stream << ".PIVOTHORIZONTAL.";
			}
			else if( m_enum == ENUM_PIVOTVERTICAL )
			{
				stream << ".PIVOTVERTICAL.";
			}
			else if( m_enum == ENUM_SLIDINGHORIZONTAL )
			{
				stream << ".SLIDINGHORIZONTAL.";
			}
			else if( m_enum == ENUM_SLIDINGVERTICAL )
			{
				stream << ".SLIDINGVERTICAL.";
			}
			else if( m_enum == ENUM_REMOVABLECASEMENT )
			{
				stream << ".REMOVABLECASEMENT.";
			}
			else if( m_enum == ENUM_FIXEDCASEMENT )
			{
				stream << ".FIXEDCASEMENT.";
			}
			else if( m_enum == ENUM_OTHEROPERATION )
			{
				stream << ".OTHEROPERATION.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcWindowPanelOperationEnum> IfcWindowPanelOperationEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcWindowPanelOperationEnum>(); }
			shared_ptr<IfcWindowPanelOperationEnum> type_object( new IfcWindowPanelOperationEnum() );
			if( _stricmp( arg.c_str(), ".SIDEHUNGRIGHTHAND." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_SIDEHUNGRIGHTHAND;
			}
			else if( _stricmp( arg.c_str(), ".SIDEHUNGLEFTHAND." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_SIDEHUNGLEFTHAND;
			}
			else if( _stricmp( arg.c_str(), ".TILTANDTURNRIGHTHAND." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_TILTANDTURNRIGHTHAND;
			}
			else if( _stricmp( arg.c_str(), ".TILTANDTURNLEFTHAND." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_TILTANDTURNLEFTHAND;
			}
			else if( _stricmp( arg.c_str(), ".TOPHUNG." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_TOPHUNG;
			}
			else if( _stricmp( arg.c_str(), ".BOTTOMHUNG." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_BOTTOMHUNG;
			}
			else if( _stricmp( arg.c_str(), ".PIVOTHORIZONTAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_PIVOTHORIZONTAL;
			}
			else if( _stricmp( arg.c_str(), ".PIVOTVERTICAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_PIVOTVERTICAL;
			}
			else if( _stricmp( arg.c_str(), ".SLIDINGHORIZONTAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_SLIDINGHORIZONTAL;
			}
			else if( _stricmp( arg.c_str(), ".SLIDINGVERTICAL." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_SLIDINGVERTICAL;
			}
			else if( _stricmp( arg.c_str(), ".REMOVABLECASEMENT." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_REMOVABLECASEMENT;
			}
			else if( _stricmp( arg.c_str(), ".FIXEDCASEMENT." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_FIXEDCASEMENT;
			}
			else if( _stricmp( arg.c_str(), ".OTHEROPERATION." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_OTHEROPERATION;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcWindowPanelOperationEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
