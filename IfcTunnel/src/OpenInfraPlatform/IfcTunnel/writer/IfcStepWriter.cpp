/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <locale.h>
#include "model/shared_ptr.h"
#include "model/IfcTunnelObject.h"
#include "model/IfcTunnelModel.h"
#include "entity/include/IfcProduct.h"
#include "entity/include/IfcProject.h"
#include "writer/IfcStepWriter.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        IfcStepWriter::IfcStepWriter()
        {
        }

        IfcStepWriter::~IfcStepWriter()
        {
        }

        void IfcStepWriter::writeStream( std::stringstream& stream, shared_ptr<IfcTunnelModel> model )
        {
            char* current_numeric_locale = setlocale(LC_NUMERIC, NULL);
            setlocale(LC_NUMERIC,"C");

            stream << model->getFileHeader().c_str();
            stream << "DATA;\n";

            const std::map<int,shared_ptr<IfcTunnelEntity> >& map = model->getMapIfcObjects();
            std::map<int,shared_ptr<IfcTunnelEntity> >::const_iterator it;
            for( it=map.begin(); it!=map.end(); ++it )
            {
                shared_ptr<IfcTunnelEntity> obj = it->second;

                if( obj.use_count() < 2 )
                {
                    // entity is referenced only in model map, not by other entities
                    if( !dynamic_pointer_cast<IfcProduct>(obj) && !dynamic_pointer_cast<IfcProject>(obj) )
                    {
                        continue;
                    }
                }
                obj->getStepLine( stream );
                stream << std::endl;
            }

            stream << "ENDSEC;\nEND-ISO-10303-21;\n";

            setlocale(LC_NUMERIC, current_numeric_locale);
        }
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
