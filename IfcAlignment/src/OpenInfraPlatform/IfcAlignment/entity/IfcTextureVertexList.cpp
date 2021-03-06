/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcParameterValue.h"
#include "include/IfcTextureVertexList.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcTextureVertexList 
		IfcTextureVertexList::IfcTextureVertexList() { m_entity_enum = IFCTEXTUREVERTEXLIST; }
		IfcTextureVertexList::IfcTextureVertexList( int id ) { m_id = id; m_entity_enum = IFCTEXTUREVERTEXLIST; }
		IfcTextureVertexList::~IfcTextureVertexList() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTextureVertexList::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcTextureVertexList> other = dynamic_pointer_cast<IfcTextureVertexList>(other_entity);
			if( !other) { return; }
			m_TexCoordsList = other->m_TexCoordsList;
		}
		void IfcTextureVertexList::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTEXTUREVERTEXLIST" << "(";
			writeTypeOfRealList2D( stream, m_TexCoordsList );
			stream << ");";
		}
		void IfcTextureVertexList::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTextureVertexList::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTextureVertexList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcTextureVertexList, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList2D( args[0], m_TexCoordsList );
		}
		void IfcTextureVertexList::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTextureVertexList::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
