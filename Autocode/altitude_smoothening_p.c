/*
 * File: altitude_smoothening_p.c
 *
 * Code generated for Simulink model 'altitude_smoothening_p'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Oct 19 12:09:59 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "altitude_smoothening_p.h"
#include "rtwtypes.h"

/* Block signals (default storage) */
BlockIO_altitude_smoothening_p_T altitude_smoothening_p_B;

/* External inputs (root inport signals with default storage) */
ExternalInputs_altitude_smoothening_p_T altitude_smoothening_p_U;

/* External outputs (root outports fed by signals with default storage) */
ExternalOutputs_altitude_smoothening_p_T altitude_smoothening_p_Y;

/* Real-time model */
static RT_MODEL_altitude_smoothening_p_T altitude_smoothening_p_M_;
RT_MODEL_altitude_smoothening_p_T *const altitude_smoothening_p_M =
  &altitude_smoothening_p_M_;

/* Model step function */
void altitude_smoothening_p_step(void)
{
  uint8_T tmp;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/currenttime'
   *  Inport: '<Root>/totaltime'
   *  Product: '<Root>/Divide1'
   *  RelationalOperator: '<Root>/Equal'
   */
  if (altitude_smoothening_p_U.totaltime >= altitude_smoothening_p_U.currenttime)
  {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Outport: '<Root>/desiredaltitude' incorporates:
     *  SignalConversion generated from: '<S1>/In1'
     */
    altitude_smoothening_p_Y.desiredaltitude = altitude_smoothening_p_B.Add2;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  } else {
    if (altitude_smoothening_p_U.totaltime == 0) {
      /* Product: '<Root>/Divide1' */
      tmp = MAX_uint8_T;

      /* Divide by zero handler */
    } else {
      /* Product: '<Root>/Divide1' incorporates:
       *  Inport: '<Root>/startaltitude'
       *  Inport: '<Root>/targetaltitude'
       *  Sum: '<Root>/Add'
       */
      tmp = (uint8_T)((uint32_T)(uint8_T)
                      (altitude_smoothening_p_U.targetaltitude +
                       altitude_smoothening_p_U.startaltitude) /
                      altitude_smoothening_p_U.totaltime);
    }

    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Product: '<S2>/Divide' incorporates:
     *  Inport: '<Root>/startaltitude'
     *  Product: '<Root>/Divide1'
     *  Sum: '<S2>/Add1'
     */
    altitude_smoothening_p_B.Add2 = (uint16_T)((uint32_T)(uint8_T)
      (altitude_smoothening_p_U.startaltitude + tmp) *
      altitude_smoothening_p_U.currenttime);

    /* Outport: '<Root>/desiredaltitude' incorporates:
     *  SignalConversion generated from: '<S2>/desiredalt'
     */
    altitude_smoothening_p_Y.desiredaltitude = altitude_smoothening_p_B.Add2;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */
}

/* Model initialize function */
void altitude_smoothening_p_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void altitude_smoothening_p_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
