/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcComplexProperty.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcIdentifier.h"
#include "include/IfcProperty.h"
#include "include/IfcPropertyDependencyRelationship.h"
#include "include/IfcPropertySet.h"
#include "include/IfcText.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcComplexProperty 
		IfcComplexProperty::IfcComplexProperty() { m_entity_enum = IFCCOMPLEXPROPERTY; }
		IfcComplexProperty::IfcComplexProperty( int id ) { m_id = id; m_entity_enum = IFCCOMPLEXPROPERTY; }
		IfcComplexProperty::~IfcComplexProperty() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcComplexProperty::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcComplexProperty> other = dynamic_pointer_cast<IfcComplexProperty>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_Description = other->m_Description;
			m_UsageName = other->m_UsageName;
			m_HasProperties = other->m_HasProperties;
		}
		void IfcComplexProperty::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOMPLEXPROPERTY" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UsageName ) { m_UsageName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_HasProperties );
			stream << ");";
		}
		void IfcComplexProperty::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcComplexProperty::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcComplexProperty, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcComplexProperty, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcIdentifier::readStepData( args[0] );
			m_Description = IfcText::readStepData( args[1] );
			m_UsageName = IfcIdentifier::readStepData( args[2] );
			readEntityReferenceList( args[3], m_HasProperties, map );
		}
		void IfcComplexProperty::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcProperty::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcComplexProperty> ptr_self = dynamic_pointer_cast<IfcComplexProperty>( ptr_self_entity );
			if( !ptr_self ) { throw IfcBridgeException( "IfcComplexProperty::setInverseCounterparts: type mismatch" ); }
			for( int i=0; i<m_HasProperties.size(); ++i )
			{
				if( m_HasProperties[i] )
				{
					m_HasProperties[i]->m_PartOfComplex_inverse.push_back( ptr_self );
				}
			}
		}
		void IfcComplexProperty::unlinkSelf()
		{
			IfcProperty::unlinkSelf();
			for( int i=0; i<m_HasProperties.size(); ++i )
			{
				if( m_HasProperties[i] )
				{
					std::vector<weak_ptr<IfcComplexProperty> >& PartOfComplex_inverse = m_HasProperties[i]->m_PartOfComplex_inverse;
					std::vector<weak_ptr<IfcComplexProperty> >::iterator it_PartOfComplex_inverse;
					for( it_PartOfComplex_inverse = PartOfComplex_inverse.begin(); it_PartOfComplex_inverse != PartOfComplex_inverse.end(); ++it_PartOfComplex_inverse)
					{
						shared_ptr<IfcComplexProperty> self_candidate( *it_PartOfComplex_inverse );
						if( self_candidate->getId() == this->getId() )
						{
							PartOfComplex_inverse.erase( it_PartOfComplex_inverse );
							break;
						}
					}
				}
			}
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
