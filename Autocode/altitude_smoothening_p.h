/*
 * File: altitude_smoothening_p.h
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

#ifndef altitude_smoothening_p_h_
#define altitude_smoothening_p_h_
#ifndef altitude_smoothening_p_COMMON_INCLUDES_
#define altitude_smoothening_p_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                             /* altitude_smoothening_p_COMMON_INCLUDES_ */

#include "altitude_smoothening_p_types.h"
#include "rt_defines.h"
#include <string.h>

/* Block signals (default storage) */
typedef struct {
  uint16_T Add2;                       /* '<S2>/Add2' */
} B_altitude_smoothening_p_sT;

/* Real-time Model Data Structure */
struct tag_RTM_altitude_smoothening_p_sT {
  B_altitude_smoothening_p_sT *blockIO;
};

/* Model entry point functions */
extern void altitude_smoothening_p_initialize(RT_MODEL_altitude_smoothening_p_sT
  *const altitude_smoothening_p_M, uint8_T
  *altitude_smoothening_p_U_startaltitude, uint8_T
  *altitude_smoothening_p_U_totaltime, uint8_T
  *altitude_smoothening_p_U_currenttime, uint8_T
  *altitude_smoothening_p_U_targetaltitude, uint16_T
  *altitude_smoothening_p_Y_desiredaltitude);
extern void altitude_smoothening_p_output(RT_MODEL_altitude_smoothening_p_sT *
  const altitude_smoothening_p_M, uint8_T altitude_smoothening_p_U_startaltitude,
  uint8_T altitude_smoothening_p_U_totaltime, uint8_T
  altitude_smoothening_p_U_currenttime, uint8_T
  altitude_smoothening_p_U_targetaltitude, uint16_T
  *altitude_smoothening_p_Y_desiredaltitude);
extern void altitude_smoothening_p_update(RT_MODEL_altitude_smoothening_p_sT *
  const altitude_smoothening_p_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Signal Copy' : Eliminate redundant signal conversion block
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'altitude_smoothening_p'
 * '<S1>'   : 'altitude_smoothening_p/If Action Subsystem'
 * '<S2>'   : 'altitude_smoothening_p/If Action Subsystem1'
 */

/*-
 * Requirements for '<Root>': altitude_smoothening_p

 */
#endif                                 /* altitude_smoothening_p_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
