/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DualVNHMotor.c
 *
 * Code generated for Simulink model 'DualVNHMotor'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Wed Apr 24 12:10:27 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DualVNHMotor.h"
#include "DualVNHMotor_private.h"
#include "DualVNHMotor_dt.h"

/* Block states (default storage) */
DW_DualVNHMotor_T DualVNHMotor_DW;

/* Real-time model */
RT_MODEL_DualVNHMotor_T DualVNHMotor_M_;
RT_MODEL_DualVNHMotor_T *const DualVNHMotor_M = &DualVNHMotor_M_;

/* Model step function */
void DualVNHMotor_step(void)
{
  /* S-Function (sfunc_dcmotor): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  sfunc_dcmotor_Outputs_wrapper(&DualVNHMotor_P.Constant_Value,
    &DualVNHMotor_P.Constant1_Value, &DualVNHMotor_DW.SFunctionBuilder_DSTATE);

  /* Update for S-Function (sfunc_dcmotor): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */

  /* S-Function "sfunc_dcmotor_wrapper" Block: <S1>/S-Function Builder */
  sfunc_dcmotor_Update_wrapper(&DualVNHMotor_P.Constant_Value,
    &DualVNHMotor_P.Constant1_Value, &DualVNHMotor_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, (real_T)DualVNHMotor_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(DualVNHMotor_M)!=-1) &&
        !((rtmGetTFinal(DualVNHMotor_M)-DualVNHMotor_M->Timing.taskTime0) >
          DualVNHMotor_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(DualVNHMotor_M, "Simulation finished");
    }

    if (rtmGetStopRequested(DualVNHMotor_M)) {
      rtmSetErrorStatus(DualVNHMotor_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  DualVNHMotor_M->Timing.taskTime0 =
    (++DualVNHMotor_M->Timing.clockTick0) * DualVNHMotor_M->Timing.stepSize0;
}

/* Model initialize function */
void DualVNHMotor_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)DualVNHMotor_M, 0,
                sizeof(RT_MODEL_DualVNHMotor_T));
  rtmSetTFinal(DualVNHMotor_M, -1);
  DualVNHMotor_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  DualVNHMotor_M->Sizes.checksums[0] = (1885448119U);
  DualVNHMotor_M->Sizes.checksums[1] = (2863728543U);
  DualVNHMotor_M->Sizes.checksums[2] = (686235174U);
  DualVNHMotor_M->Sizes.checksums[3] = (1600965126U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DualVNHMotor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DualVNHMotor_M->extModeInfo,
      &DualVNHMotor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DualVNHMotor_M->extModeInfo,
                        DualVNHMotor_M->Sizes.checksums);
    rteiSetTPtr(DualVNHMotor_M->extModeInfo, rtmGetTPtr(DualVNHMotor_M));
  }

  /* states (dwork) */
  (void) memset((void *)&DualVNHMotor_DW, 0,
                sizeof(DW_DualVNHMotor_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DualVNHMotor_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* InitializeConditions for S-Function (sfunc_dcmotor): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */

  /* S-Function Block: <S1>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        DualVNHMotor_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void DualVNHMotor_terminate(void)
{
  /* Terminate for S-Function (sfunc_dcmotor): '<S1>/S-Function Builder' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */

  /* S-Function Block: <S1>/S-Function Builder */
  sfunc_dcmotor_Terminate_wrapper(&DualVNHMotor_DW.SFunctionBuilder_DSTATE);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
