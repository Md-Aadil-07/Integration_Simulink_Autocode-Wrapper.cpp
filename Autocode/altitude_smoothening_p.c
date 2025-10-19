/*
 * File: altitude_smoothening_p.c
 *
 * Code generated for Simulink model 'altitude_smoothening_p'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Oct 19 16:31:21 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "altitude_smoothening_p.h"
#include "rtwtypes.h"

/* Model output function */
void altitude_smoothening_p_output(RT_MODEL_altitude_smoothening_p_sT *const
  altitude_smoothening_p_M, uint8_T altitude_smoothening_p_U_startaltitude,
  uint8_T altitude_smoothening_p_U_totaltime, uint8_T
  altitude_smoothening_p_U_currenttime, uint8_T
  altitude_smoothening_p_U_targetaltitude, uint16_T
  *altitude_smoothening_p_Y_desiredaltitude)
{
  B_altitude_smoothening_p_sT *altitude_smoothening_p_B =
    altitude_smoothening_p_M->blockIO;
  uint16_T Add2;
  uint16_T desiredaltitude;
  uint8_T currenttime;
  uint8_T startaltitude;
  uint8_T tmp;
  uint8_T totaltime;

  /* Inport: '<Root>/startaltitude' */
  startaltitude = altitude_smoothening_p_U_startaltitude;

  /* Inport: '<Root>/totaltime' */
  totaltime = altitude_smoothening_p_U_totaltime;

  /* Product: '<S2>/Divide' */
  Add2 = altitude_smoothening_p_B->Add2;

  /* Inport: '<Root>/currenttime' */
  currenttime = altitude_smoothening_p_U_currenttime;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/currenttime'
   *  Inport: '<Root>/totaltime'
   *  Product: '<Root>/Divide1'
   *  RelationalOperator: '<Root>/Equal'
   */
  if (totaltime >= currenttime) {
    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Outport: '<Root>/desiredaltitude' incorporates:
     *  SignalConversion generated from: '<S1>/In1'
     */
    desiredaltitude = Add2;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
  } else {
    if (totaltime == (uint8_T)0) {
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
                      (altitude_smoothening_p_U_targetaltitude + startaltitude) /
                      (uint32_T)totaltime);
    }

    /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Product: '<S2>/Divide' incorporates:
     *  Inport: '<Root>/startaltitude'
     *  Product: '<Root>/Divide1'
     *  Sum: '<S2>/Add1'
     */
    Add2 = (uint16_T)((uint32_T)currenttime * (uint32_T)(uint8_T)(startaltitude
      + tmp));

    /* Outport: '<Root>/desiredaltitude' incorporates:
     *  SignalConversion generated from: '<S2>/desiredalt'
     */
    desiredaltitude = Add2;

    /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
  }

  /* End of If: '<Root>/If' */

  /* Product: '<S2>/Divide' */
  altitude_smoothening_p_B->Add2 = Add2;

  /* Outport: '<Root>/desiredaltitude' */
  *altitude_smoothening_p_Y_desiredaltitude = desiredaltitude;
}

/* Model update function */
void altitude_smoothening_p_update(RT_MODEL_altitude_smoothening_p_sT *const
  altitude_smoothening_p_M)
{
  UNUSED_PARAMETER(altitude_smoothening_p_M);

  /* (no update code required) */
}

/* Model initialize function */
void altitude_smoothening_p_initialize(RT_MODEL_altitude_smoothening_p_sT *const
  altitude_smoothening_p_M, uint8_T *altitude_smoothening_p_U_startaltitude,
  uint8_T *altitude_smoothening_p_U_totaltime, uint8_T
  *altitude_smoothening_p_U_currenttime, uint8_T
  *altitude_smoothening_p_U_targetaltitude, uint16_T
  *altitude_smoothening_p_Y_desiredaltitude)
{
  B_altitude_smoothening_p_sT *altitude_smoothening_p_B =
    altitude_smoothening_p_M->blockIO;

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) altitude_smoothening_p_B), 0,
                sizeof(B_altitude_smoothening_p_sT));

  /* external inputs */
  *altitude_smoothening_p_U_startaltitude = 0U;
  *altitude_smoothening_p_U_totaltime = 0U;
  *altitude_smoothening_p_U_currenttime = 0U;
  *altitude_smoothening_p_U_targetaltitude = 0U;

  /* external outputs */
  *altitude_smoothening_p_Y_desiredaltitude = 0U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
