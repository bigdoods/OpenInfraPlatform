/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcCartesianPointList3D.h"
#include "include/IfcIndexedColourMap.h"
#include "include/IfcIndexedTextureMap.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcTriangulatedFaceSet.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcTriangulatedFaceSet 
		IfcTriangulatedFaceSet::IfcTriangulatedFaceSet() { m_entity_enum = IFCTRIANGULATEDFACESET; }
		IfcTriangulatedFaceSet::IfcTriangulatedFaceSet( int id ) { m_id = id; m_entity_enum = IFCTRIANGULATEDFACESET; }
		IfcTriangulatedFaceSet::~IfcTriangulatedFaceSet() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTriangulatedFaceSet::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcTriangulatedFaceSet> other = dynamic_pointer_cast<IfcTriangulatedFaceSet>(other_entity);
			if( !other) { return; }
			m_Coordinates = other->m_Coordinates;
			m_Normals = other->m_Normals;
			m_Closed = other->m_Closed;
			m_CoordIndex = other->m_CoordIndex;
			m_NormalIndex = other->m_NormalIndex;
		}
		void IfcTriangulatedFaceSet::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTRIANGULATEDFACESET" << "(";
			if( m_Coordinates ) { stream << "#" << m_Coordinates->getId(); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList2D( stream, m_Normals );
			stream << ",";
			if( m_Closed == false ) { stream << ".F."; }
			else if( m_Closed == true ) { stream << ".T."; }
			stream << ",";
			writeIntList2D( stream, m_CoordIndex );
			stream << ",";
			writeIntList2D( stream, m_NormalIndex );
			stream << ");";
		}
		void IfcTriangulatedFaceSet::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTriangulatedFaceSet::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTriangulatedFaceSet, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcTriangulatedFaceSet, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Coordinates, map );
			readTypeOfRealList2D( args[1], m_Normals );
			if( _stricmp( args[2].c_str(), ".F." ) == 0 ) { m_Closed = false; }
			else if( _stricmp( args[2].c_str(), ".T." ) == 0 ) { m_Closed = true; }
			readIntList2D(  args[3], m_CoordIndex );
			readIntList2D(  args[4], m_NormalIndex );
		}
		void IfcTriangulatedFaceSet::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcTessellatedFaceSet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcTriangulatedFaceSet::unlinkSelf()
		{
			IfcTessellatedFaceSet::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
