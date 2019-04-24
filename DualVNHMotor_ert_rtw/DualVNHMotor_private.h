/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DualVNHMotor_private.h
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

#ifndef RTW_HEADER_DualVNHMotor_private_h_
#define RTW_HEADER_DualVNHMotor_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void sfunc_dcmotor_Start_wrapper(real_T *xD);
  extern void sfunc_dcmotor_Outputs_wrapper(const real_T *spd1,
    const real_T *spd2,
    const real_T *xD);
  extern void sfunc_dcmotor_Update_wrapper(const real_T *spd1,
    const real_T *spd2,
    real_T *xD);
  extern void sfunc_dcmotor_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif
#endif                                 /* RTW_HEADER_DualVNHMotor_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
