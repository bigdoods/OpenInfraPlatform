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
#include "include/IfcArbitraryClosedProfileDef.h"
#include "include/IfcCurve.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcProfileProperties.h"
#include "include/IfcProfileTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcArbitraryClosedProfileDef 
		IfcArbitraryClosedProfileDef::IfcArbitraryClosedProfileDef() { m_entity_enum = IFCARBITRARYCLOSEDPROFILEDEF; }
		IfcArbitraryClosedProfileDef::IfcArbitraryClosedProfileDef( int id ) { m_id = id; m_entity_enum = IFCARBITRARYCLOSEDPROFILEDEF; }
		IfcArbitraryClosedProfileDef::~IfcArbitraryClosedProfileDef() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcArbitraryClosedProfileDef::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcArbitraryClosedProfileDef> other = dynamic_pointer_cast<IfcArbitraryClosedProfileDef>(other_entity);
			if( !other) { return; }
			m_ProfileType = other->m_ProfileType;
			m_ProfileName = other->m_ProfileName;
			m_OuterCurve = other->m_OuterCurve;
		}
		void IfcArbitraryClosedProfileDef::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCARBITRARYCLOSEDPROFILEDEF" << "(";
			if( m_ProfileType ) { m_ProfileType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileName ) { m_ProfileName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_OuterCurve ) { stream << "#" << m_OuterCurve->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcArbitraryClosedProfileDef::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcArbitraryClosedProfileDef::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcArbitraryClosedProfileDef, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcArbitraryClosedProfileDef, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ProfileType = IfcProfileTypeEnum::readStepData( args[0] );
			m_ProfileName = IfcLabel::readStepData( args[1] );
			readEntityReference( args[2], m_OuterCurve, map );
		}
		void IfcArbitraryClosedProfileDef::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcProfileDef::setInverseCounterparts( ptr_self_entity );
		}
		void IfcArbitraryClosedProfileDef::unlinkSelf()
		{
			IfcProfileDef::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
