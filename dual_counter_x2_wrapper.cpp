
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
// start arduino code to increment counters
# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
int encoderA1=0;
int encoderB1=0;
int pulses1;
int pulsesChanged1 = 0;

// read encoder x2 count on motor 1
extern "C" void A1_CHANGE() {
if ( digitalRead(encoderB1) == 0 ) {
if ( digitalRead(encoderA1) == 0 ) {
pulses1--; 
} else {
pulses1++;
}
} else {
if (digitalRead(encoderA1) == 0 ) {
pulses1++;
} else {
pulses1--; 
}
}
pulsesChanged1 = 1;
}

// same code but for motor 2
int encoderA2=0;
int encoderB2=0;
int pulses2;
int pulsesChanged2 = 0;
//Output pulses.
extern "C" void A2_CHANGE() { 
if ( digitalRead(encoderB2) == 0 ) {
if ( digitalRead(encoderA2) == 0 ) {
pulses2--;
} else {
pulses2++;
}
} else {
if (digitalRead(encoderA2) == 0 ) {
pulses2++; 
} else {
pulses2--; 
}
}
pulsesChanged2 = 1;
}
# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
extern "C" void dual_counter_x2_Outputs_wrapper(const int32_T *encoder1a,
			const int32_T *encoder1b,
			const int32_T *encoder2a,
			const int32_T *encoder2b,
			int32_T *count1,
			int32_T *count2,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (xD[0]==1) {
/* don't do anything for mex file generation */
# ifndef MATLAB_MEX_FILE
// set output 1 to motor 1 position
if (pulsesChanged1 != 0) {
pulsesChanged1 = 0;
count1[0]=pulses1;
}

// set output 2 to motor 2 position
if (pulsesChanged2 != 0) {
pulsesChanged2 = 0;
count2[0]=pulses2;
}
# endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
extern "C" void dual_counter_x2_Update_wrapper(const int32_T *encoder1a,
			const int32_T *encoder1b,
			const int32_T *encoder2a,
			const int32_T *encoder2b,
			int32_T *count1,
			int32_T *count2,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */

// initialize block
if (xD[0]!=1) {
# ifndef MATLAB_MEX_FILE
encoderA1=encoder1a[0];
encoderB1=encoder1b[0];
encoderA2=encoder2a[0];
encoderB2=encoder2b[0];
attachInterrupt(digitalPinToInterrupt(encoderA1), A1_CHANGE, CHANGE);
attachInterrupt(digitalPinToInterrupt(encoderA2), A2_CHANGE, CHANGE);
# endif
/* initialization done */
xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

