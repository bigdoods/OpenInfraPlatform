/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcValue.h"

// TYPE IfcDerivedMeasureValue = SELECT	(IfcAbsorbedDoseMeasure	,IfcAccelerationMeasure	,IfcAngularVelocityMeasure	,IfcAreaDensityMeasure	,IfcCompoundPlaneAngleMeasure	,IfcCurvatureMeasure	,IfcDoseEquivalentMeasure	,IfcDynamicViscosityMeasure	,IfcElectricCapacitanceMeasure	,IfcElectricChargeMeasure	,IfcElectricConductanceMeasure	,IfcElectricResistanceMeasure	,IfcElectricVoltageMeasure	,IfcEnergyMeasure	,IfcForceMeasure	,IfcFrequencyMeasure	,IfcHeatFluxDensityMeasure	,IfcHeatingValueMeasure	,IfcIlluminanceMeasure	,IfcInductanceMeasure	,IfcIntegerCountRateMeasure	,IfcIonConcentrationMeasure	,IfcIsothermalMoistureCapacityMeasure	,IfcKinematicViscosityMeasure	,IfcLinearForceMeasure	,IfcLinearMomentMeasure	,IfcLinearStiffnessMeasure	,IfcLinearVelocityMeasure	,IfcLuminousFluxMeasure	,IfcLuminousIntensityDistributionMeasure	,IfcMagneticFluxDensityMeasure	,IfcMagneticFluxMeasure	,IfcMassDensityMeasure	,IfcMassFlowRateMeasure	,IfcMassPerLengthMeasure	,IfcModulusOfElasticityMeasure	,IfcModulusOfLinearSubgradeReactionMeasure	,IfcModulusOfRotationalSubgradeReactionMeasure	,IfcModulusOfSubgradeReactionMeasure	,IfcMoistureDiffusivityMeasure	,IfcMolecularWeightMeasure	,IfcMomentOfInertiaMeasure	,IfcMonetaryMeasure	,IfcPHMeasure	,IfcPlanarForceMeasure	,IfcPowerMeasure	,IfcPressureMeasure	,IfcRadioActivityMeasure	,IfcRotationalFrequencyMeasure	,IfcRotationalMassMeasure	,IfcRotationalStiffnessMeasure	,IfcSectionModulusMeasure	,IfcSectionalAreaIntegralMeasure	,IfcShearModulusMeasure	,IfcSoundPowerLevelMeasure	,IfcSoundPowerMeasure	,IfcSoundPressureLevelMeasure	,IfcSoundPressureMeasure	,IfcSpecificHeatCapacityMeasure	,IfcTemperatureGradientMeasure	,IfcTemperatureRateOfChangeMeasure	,IfcThermalAdmittanceMeasure	,IfcThermalConductivityMeasure	,IfcThermalExpansionCoefficientMeasure	,IfcThermalResistanceMeasure	,IfcThermalTransmittanceMeasure	,IfcTorqueMeasure	,IfcVaporPermeabilityMeasure	,IfcVolumetricFlowRateMeasure	,IfcWarpingConstantMeasure	,IfcWarpingMomentMeasure);
namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcDerivedMeasureValue : public IfcValue
		{
		public:
			IfcDerivedMeasureValue();
			~IfcDerivedMeasureValue();
			virtual const char* classname() const { return "IfcDerivedMeasureValue"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcDerivedMeasureValue> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

