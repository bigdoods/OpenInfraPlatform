/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcPreDefinedTextFont.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcPreDefinedTextFont 
		IfcPreDefinedTextFont::IfcPreDefinedTextFont() { m_entity_enum = IFCPREDEFINEDTEXTFONT; }
		IfcPreDefinedTextFont::IfcPreDefinedTextFont( int id ) { m_id = id; m_entity_enum = IFCPREDEFINEDTEXTFONT; }
		IfcPreDefinedTextFont::~IfcPreDefinedTextFont() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPreDefinedTextFont::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcPreDefinedTextFont> other = dynamic_pointer_cast<IfcPreDefinedTextFont>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
		}
		void IfcPreDefinedTextFont::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPREDEFINEDTEXTFONT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcPreDefinedTextFont::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPreDefinedTextFont::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcPreDefinedTextFont, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcPreDefinedTextFont, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
		}
		void IfcPreDefinedTextFont::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcPreDefinedItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcPreDefinedTextFont::unlinkSelf()
		{
			IfcPreDefinedItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
