/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include "entity/include/IfcAbsorbedDoseMeasure.h"
#include "entity/include/IfcAccelerationMeasure.h"
#include "entity/include/IfcActionSourceTypeEnum.h"
#include "entity/include/IfcActionTypeEnum.h"
#include "entity/include/IfcActorSelect.h"
#include "entity/include/IfcActuatorTypeEnum.h"
#include "entity/include/IfcAddressTypeEnum.h"
#include "entity/include/IfcAheadOrBehind.h"
#include "entity/include/IfcAirTerminalBoxTypeEnum.h"
#include "entity/include/IfcAirTerminalTypeEnum.h"
#include "entity/include/IfcAirToAirHeatRecoveryTypeEnum.h"
#include "entity/include/IfcAlarmTypeEnum.h"
#include "entity/include/IfcAmountOfSubstanceMeasure.h"
#include "entity/include/IfcAnalysisModelTypeEnum.h"
#include "entity/include/IfcAnalysisTheoryTypeEnum.h"
#include "entity/include/IfcAngularVelocityMeasure.h"
#include "entity/include/IfcAppliedValueSelect.h"
#include "entity/include/IfcAreaMeasure.h"
#include "entity/include/IfcArithmeticOperatorEnum.h"
#include "entity/include/IfcAssemblyPlaceEnum.h"
#include "entity/include/IfcAxis2Placement.h"
#include "entity/include/IfcBSplineCurveForm.h"
#include "entity/include/IfcBeamTypeEnum.h"
#include "entity/include/IfcBenchmarkEnum.h"
#include "entity/include/IfcBoilerTypeEnum.h"
#include "entity/include/IfcBoolean.h"
#include "entity/include/IfcBooleanOperand.h"
#include "entity/include/IfcBooleanOperator.h"
#include "entity/include/IfcBoxAlignment.h"
#include "entity/include/IfcBuildingElementProxyTypeEnum.h"
#include "entity/include/IfcCableCarrierFittingTypeEnum.h"
#include "entity/include/IfcCableCarrierSegmentTypeEnum.h"
#include "entity/include/IfcCableSegmentTypeEnum.h"
#include "entity/include/IfcChangeActionEnum.h"
#include "entity/include/IfcCharacterStyleSelect.h"
#include "entity/include/IfcChillerTypeEnum.h"
#include "entity/include/IfcClassificationNotationSelect.h"
#include "entity/include/IfcCoilTypeEnum.h"
#include "entity/include/IfcColour.h"
#include "entity/include/IfcColourOrFactor.h"
#include "entity/include/IfcColumnTypeEnum.h"
#include "entity/include/IfcComplexNumber.h"
#include "entity/include/IfcCompoundPlaneAngleMeasure.h"
#include "entity/include/IfcCompressorTypeEnum.h"
#include "entity/include/IfcCondenserTypeEnum.h"
#include "entity/include/IfcConditionCriterionSelect.h"
#include "entity/include/IfcConnectionTypeEnum.h"
#include "entity/include/IfcConstraintEnum.h"
#include "entity/include/IfcContextDependentMeasure.h"
#include "entity/include/IfcControllerTypeEnum.h"
#include "entity/include/IfcCooledBeamTypeEnum.h"
#include "entity/include/IfcCoolingTowerTypeEnum.h"
#include "entity/include/IfcCostScheduleTypeEnum.h"
#include "entity/include/IfcCountMeasure.h"
#include "entity/include/IfcCoveringTypeEnum.h"
#include "entity/include/IfcCsgSelect.h"
#include "entity/include/IfcCurrencyEnum.h"
#include "entity/include/IfcCurtainWallTypeEnum.h"
#include "entity/include/IfcCurvatureMeasure.h"
#include "entity/include/IfcCurveFontOrScaledCurveFontSelect.h"
#include "entity/include/IfcCurveOrEdgeCurve.h"
#include "entity/include/IfcCurveStyleFontSelect.h"
#include "entity/include/IfcDamperTypeEnum.h"
#include "entity/include/IfcDataOriginEnum.h"
#include "entity/include/IfcDateTimeSelect.h"
#include "entity/include/IfcDayInMonthNumber.h"
#include "entity/include/IfcDaylightSavingHour.h"
#include "entity/include/IfcDefinedSymbolSelect.h"
#include "entity/include/IfcDerivedMeasureValue.h"
#include "entity/include/IfcDerivedUnitEnum.h"
#include "entity/include/IfcDescriptiveMeasure.h"
#include "entity/include/IfcDimensionCount.h"
#include "entity/include/IfcDimensionExtentUsage.h"
#include "entity/include/IfcDirectionSenseEnum.h"
#include "entity/include/IfcDistributionChamberElementTypeEnum.h"
#include "entity/include/IfcDocumentConfidentialityEnum.h"
#include "entity/include/IfcDocumentSelect.h"
#include "entity/include/IfcDocumentStatusEnum.h"
#include "entity/include/IfcDoorPanelOperationEnum.h"
#include "entity/include/IfcDoorPanelPositionEnum.h"
#include "entity/include/IfcDoorStyleConstructionEnum.h"
#include "entity/include/IfcDoorStyleOperationEnum.h"
#include "entity/include/IfcDoseEquivalentMeasure.h"
#include "entity/include/IfcDraughtingCalloutElement.h"
#include "entity/include/IfcDuctFittingTypeEnum.h"
#include "entity/include/IfcDuctSegmentTypeEnum.h"
#include "entity/include/IfcDuctSilencerTypeEnum.h"
#include "entity/include/IfcDynamicViscosityMeasure.h"
#include "entity/include/IfcElectricApplianceTypeEnum.h"
#include "entity/include/IfcElectricCapacitanceMeasure.h"
#include "entity/include/IfcElectricChargeMeasure.h"
#include "entity/include/IfcElectricConductanceMeasure.h"
#include "entity/include/IfcElectricCurrentEnum.h"
#include "entity/include/IfcElectricCurrentMeasure.h"
#include "entity/include/IfcElectricDistributionPointFunctionEnum.h"
#include "entity/include/IfcElectricFlowStorageDeviceTypeEnum.h"
#include "entity/include/IfcElectricGeneratorTypeEnum.h"
#include "entity/include/IfcElectricHeaterTypeEnum.h"
#include "entity/include/IfcElectricMotorTypeEnum.h"
#include "entity/include/IfcElectricResistanceMeasure.h"
#include "entity/include/IfcElectricTimeControlTypeEnum.h"
#include "entity/include/IfcElectricVoltageMeasure.h"
#include "entity/include/IfcElementAssemblyTypeEnum.h"
#include "entity/include/IfcElementCompositionEnum.h"
#include "entity/include/IfcEnergyMeasure.h"
#include "entity/include/IfcEnergySequenceEnum.h"
#include "entity/include/IfcEnvironmentalImpactCategoryEnum.h"
#include "entity/include/IfcEvaporativeCoolerTypeEnum.h"
#include "entity/include/IfcEvaporatorTypeEnum.h"
#include "entity/include/IfcFanTypeEnum.h"
#include "entity/include/IfcFillAreaStyleTileShapeSelect.h"
#include "entity/include/IfcFillStyleSelect.h"
#include "entity/include/IfcFilterTypeEnum.h"
#include "entity/include/IfcFireSuppressionTerminalTypeEnum.h"
#include "entity/include/IfcFlowDirectionEnum.h"
#include "entity/include/IfcFlowInstrumentTypeEnum.h"
#include "entity/include/IfcFlowMeterTypeEnum.h"
#include "entity/include/IfcFontStyle.h"
#include "entity/include/IfcFontVariant.h"
#include "entity/include/IfcFontWeight.h"
#include "entity/include/IfcFootingTypeEnum.h"
#include "entity/include/IfcForceMeasure.h"
#include "entity/include/IfcFrequencyMeasure.h"
#include "entity/include/IfcGasTerminalTypeEnum.h"
#include "entity/include/IfcGeometricProjectionEnum.h"
#include "entity/include/IfcGeometricSetSelect.h"
#include "entity/include/IfcGlobalOrLocalEnum.h"
#include "entity/include/IfcGloballyUniqueId.h"
#include "entity/include/IfcHatchLineDistanceSelect.h"
#include "entity/include/IfcHeatExchangerTypeEnum.h"
#include "entity/include/IfcHeatFluxDensityMeasure.h"
#include "entity/include/IfcHeatingValueMeasure.h"
#include "entity/include/IfcHourInDay.h"
#include "entity/include/IfcHumidifierTypeEnum.h"
#include "entity/include/IfcIdentifier.h"
#include "entity/include/IfcIlluminanceMeasure.h"
#include "entity/include/IfcInductanceMeasure.h"
#include "entity/include/IfcInteger.h"
#include "entity/include/IfcIntegerCountRateMeasure.h"
#include "entity/include/IfcInternalOrExternalEnum.h"
#include "entity/include/IfcInventoryTypeEnum.h"
#include "entity/include/IfcIonConcentrationMeasure.h"
#include "entity/include/IfcIsothermalMoistureCapacityMeasure.h"
#include "entity/include/IfcJunctionBoxTypeEnum.h"
#include "entity/include/IfcKinematicViscosityMeasure.h"
#include "entity/include/IfcLabel.h"
#include "entity/include/IfcLampTypeEnum.h"
#include "entity/include/IfcLayerSetDirectionEnum.h"
#include "entity/include/IfcLayeredItem.h"
#include "entity/include/IfcLengthMeasure.h"
#include "entity/include/IfcLibrarySelect.h"
#include "entity/include/IfcLightDistributionCurveEnum.h"
#include "entity/include/IfcLightDistributionDataSourceSelect.h"
#include "entity/include/IfcLightEmissionSourceEnum.h"
#include "entity/include/IfcLightFixtureTypeEnum.h"
#include "entity/include/IfcLinearForceMeasure.h"
#include "entity/include/IfcLinearMomentMeasure.h"
#include "entity/include/IfcLinearStiffnessMeasure.h"
#include "entity/include/IfcLinearVelocityMeasure.h"
#include "entity/include/IfcLoadGroupTypeEnum.h"
#include "entity/include/IfcLogical.h"
#include "entity/include/IfcLogicalOperatorEnum.h"
#include "entity/include/IfcLuminousFluxMeasure.h"
#include "entity/include/IfcLuminousIntensityDistributionMeasure.h"
#include "entity/include/IfcLuminousIntensityMeasure.h"
#include "entity/include/IfcMagneticFluxDensityMeasure.h"
#include "entity/include/IfcMagneticFluxMeasure.h"
#include "entity/include/IfcMassDensityMeasure.h"
#include "entity/include/IfcMassFlowRateMeasure.h"
#include "entity/include/IfcMassMeasure.h"
#include "entity/include/IfcMassPerLengthMeasure.h"
#include "entity/include/IfcMaterialSelect.h"
#include "entity/include/IfcMeasureValue.h"
#include "entity/include/IfcMemberTypeEnum.h"
#include "entity/include/IfcMetricValueSelect.h"
#include "entity/include/IfcMinuteInHour.h"
#include "entity/include/IfcModulusOfElasticityMeasure.h"
#include "entity/include/IfcModulusOfLinearSubgradeReactionMeasure.h"
#include "entity/include/IfcModulusOfRotationalSubgradeReactionMeasure.h"
#include "entity/include/IfcModulusOfSubgradeReactionMeasure.h"
#include "entity/include/IfcMoistureDiffusivityMeasure.h"
#include "entity/include/IfcMolecularWeightMeasure.h"
#include "entity/include/IfcMomentOfInertiaMeasure.h"
#include "entity/include/IfcMonetaryMeasure.h"
#include "entity/include/IfcMonthInYearNumber.h"
#include "entity/include/IfcMotorConnectionTypeEnum.h"
#include "entity/include/IfcNormalisedRatioMeasure.h"
#include "entity/include/IfcNullStyle.h"
#include "entity/include/IfcNumericMeasure.h"
#include "entity/include/IfcObjectReferenceSelect.h"
#include "entity/include/IfcObjectTypeEnum.h"
#include "entity/include/IfcObjectiveEnum.h"
#include "entity/include/IfcOccupantTypeEnum.h"
#include "entity/include/IfcOrientationSelect.h"
#include "entity/include/IfcOutletTypeEnum.h"
#include "entity/include/IfcPHMeasure.h"
#include "entity/include/IfcParameterValue.h"
#include "entity/include/IfcPermeableCoveringOperationEnum.h"
#include "entity/include/IfcPhysicalOrVirtualEnum.h"
#include "entity/include/IfcPileConstructionEnum.h"
#include "entity/include/IfcPileTypeEnum.h"
#include "entity/include/IfcPipeFittingTypeEnum.h"
#include "entity/include/IfcPipeSegmentTypeEnum.h"
#include "entity/include/IfcPlanarForceMeasure.h"
#include "entity/include/IfcPlaneAngleMeasure.h"
#include "entity/include/IfcPlateTypeEnum.h"
#include "entity/include/IfcPointOrVertexPoint.h"
#include "entity/include/IfcPositiveLengthMeasure.h"
#include "entity/include/IfcPositivePlaneAngleMeasure.h"
#include "entity/include/IfcPositiveRatioMeasure.h"
#include "entity/include/IfcPowerMeasure.h"
#include "entity/include/IfcPresentableText.h"
#include "entity/include/IfcPresentationStyleSelect.h"
#include "entity/include/IfcPressureMeasure.h"
#include "entity/include/IfcProcedureTypeEnum.h"
#include "entity/include/IfcProfileTypeEnum.h"
#include "entity/include/IfcProjectOrderRecordTypeEnum.h"
#include "entity/include/IfcProjectOrderTypeEnum.h"
#include "entity/include/IfcProjectedOrTrueLengthEnum.h"
#include "entity/include/IfcPropertySourceEnum.h"
#include "entity/include/IfcProtectiveDeviceTypeEnum.h"
#include "entity/include/IfcPumpTypeEnum.h"
#include "entity/include/IfcRadioActivityMeasure.h"
#include "entity/include/IfcRailingTypeEnum.h"
#include "entity/include/IfcRampFlightTypeEnum.h"
#include "entity/include/IfcRampTypeEnum.h"
#include "entity/include/IfcRatioMeasure.h"
#include "entity/include/IfcReal.h"
#include "entity/include/IfcReflectanceMethodEnum.h"
#include "entity/include/IfcReinforcingBarRoleEnum.h"
#include "entity/include/IfcReinforcingBarSurfaceEnum.h"
#include "entity/include/IfcResourceConsumptionEnum.h"
#include "entity/include/IfcRibPlateDirectionEnum.h"
#include "entity/include/IfcRoleEnum.h"
#include "entity/include/IfcRoofTypeEnum.h"
#include "entity/include/IfcRotationalFrequencyMeasure.h"
#include "entity/include/IfcRotationalMassMeasure.h"
#include "entity/include/IfcRotationalStiffnessMeasure.h"
#include "entity/include/IfcSIPrefix.h"
#include "entity/include/IfcSIUnitName.h"
#include "entity/include/IfcSanitaryTerminalTypeEnum.h"
#include "entity/include/IfcSecondInMinute.h"
#include "entity/include/IfcSectionModulusMeasure.h"
#include "entity/include/IfcSectionTypeEnum.h"
#include "entity/include/IfcSectionalAreaIntegralMeasure.h"
#include "entity/include/IfcSensorTypeEnum.h"
#include "entity/include/IfcSequenceEnum.h"
#include "entity/include/IfcServiceLifeFactorTypeEnum.h"
#include "entity/include/IfcServiceLifeTypeEnum.h"
#include "entity/include/IfcShearModulusMeasure.h"
#include "entity/include/IfcShell.h"
#include "entity/include/IfcSimpleValue.h"
#include "entity/include/IfcSizeSelect.h"
#include "entity/include/IfcSlabTypeEnum.h"
#include "entity/include/IfcSolidAngleMeasure.h"
#include "entity/include/IfcSoundPowerMeasure.h"
#include "entity/include/IfcSoundPressureMeasure.h"
#include "entity/include/IfcSoundScaleEnum.h"
#include "entity/include/IfcSpaceHeaterTypeEnum.h"
#include "entity/include/IfcSpaceTypeEnum.h"
#include "entity/include/IfcSpecificHeatCapacityMeasure.h"
#include "entity/include/IfcSpecularExponent.h"
#include "entity/include/IfcSpecularHighlightSelect.h"
#include "entity/include/IfcSpecularRoughness.h"
#include "entity/include/IfcStackTerminalTypeEnum.h"
#include "entity/include/IfcStairFlightTypeEnum.h"
#include "entity/include/IfcStairTypeEnum.h"
#include "entity/include/IfcStateEnum.h"
#include "entity/include/IfcStructuralActivityAssignmentSelect.h"
#include "entity/include/IfcStructuralCurveTypeEnum.h"
#include "entity/include/IfcStructuralSurfaceTypeEnum.h"
#include "entity/include/IfcSurfaceOrFaceSurface.h"
#include "entity/include/IfcSurfaceSide.h"
#include "entity/include/IfcSurfaceStyleElementSelect.h"
#include "entity/include/IfcSurfaceTextureEnum.h"
#include "entity/include/IfcSwitchingDeviceTypeEnum.h"
#include "entity/include/IfcSymbolStyleSelect.h"
#include "entity/include/IfcTankTypeEnum.h"
#include "entity/include/IfcTemperatureGradientMeasure.h"
#include "entity/include/IfcTendonTypeEnum.h"
#include "entity/include/IfcText.h"
#include "entity/include/IfcTextAlignment.h"
#include "entity/include/IfcTextDecoration.h"
#include "entity/include/IfcTextFontName.h"
#include "entity/include/IfcTextFontSelect.h"
#include "entity/include/IfcTextPath.h"
#include "entity/include/IfcTextStyleSelect.h"
#include "entity/include/IfcTextTransformation.h"
#include "entity/include/IfcThermalAdmittanceMeasure.h"
#include "entity/include/IfcThermalConductivityMeasure.h"
#include "entity/include/IfcThermalExpansionCoefficientMeasure.h"
#include "entity/include/IfcThermalLoadSourceEnum.h"
#include "entity/include/IfcThermalLoadTypeEnum.h"
#include "entity/include/IfcThermalResistanceMeasure.h"
#include "entity/include/IfcThermalTransmittanceMeasure.h"
#include "entity/include/IfcThermodynamicTemperatureMeasure.h"
#include "entity/include/IfcTimeMeasure.h"
#include "entity/include/IfcTimeSeriesDataTypeEnum.h"
#include "entity/include/IfcTimeSeriesScheduleTypeEnum.h"
#include "entity/include/IfcTimeStamp.h"
#include "entity/include/IfcTorqueMeasure.h"
#include "entity/include/IfcTransformerTypeEnum.h"
#include "entity/include/IfcTransitionCode.h"
#include "entity/include/IfcTransportElementTypeEnum.h"
#include "entity/include/IfcTrimmingPreference.h"
#include "entity/include/IfcTrimmingSelect.h"
#include "entity/include/IfcTubeBundleTypeEnum.h"
#include "entity/include/IfcUnit.h"
#include "entity/include/IfcUnitEnum.h"
#include "entity/include/IfcUnitaryEquipmentTypeEnum.h"
#include "entity/include/IfcValue.h"
#include "entity/include/IfcValveTypeEnum.h"
#include "entity/include/IfcVaporPermeabilityMeasure.h"
#include "entity/include/IfcVectorOrDirection.h"
#include "entity/include/IfcVibrationIsolatorTypeEnum.h"
#include "entity/include/IfcVolumeMeasure.h"
#include "entity/include/IfcVolumetricFlowRateMeasure.h"
#include "entity/include/IfcWallTypeEnum.h"
#include "entity/include/IfcWarpingConstantMeasure.h"
#include "entity/include/IfcWarpingMomentMeasure.h"
#include "entity/include/IfcWasteTerminalTypeEnum.h"
#include "entity/include/IfcWindowPanelOperationEnum.h"
#include "entity/include/IfcWindowPanelPositionEnum.h"
#include "entity/include/IfcWindowStyleConstructionEnum.h"
#include "entity/include/IfcWindowStyleOperationEnum.h"
#include "entity/include/IfcWorkControlTypeEnum.h"
#include "entity/include/IfcYearNumber.h"