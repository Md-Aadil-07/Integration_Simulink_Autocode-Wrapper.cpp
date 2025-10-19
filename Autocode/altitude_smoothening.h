/*
 * File: altitude_smoothening.h
 *
 * Code generated for Simulink model 'altitude_smoothening'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sun Oct 19 13:44:12 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef altitude_smoothening_h_
#define altitude_smoothening_h_
#ifndef altitude_smoothening_COMMON_INCLUDES_
#define altitude_smoothening_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                               /* altitude_smoothening_COMMON_INCLUDES_ */

#include "altitude_smoothening_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T Add2;                       /* '<S2>/Add2' */
} BlockIO_altitude_smoothening_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T startaltitude;               /* '<Root>/startaltitude' */
  uint8_T totaltime;                   /* '<Root>/totaltime' */
  uint8_T currenttime;                 /* '<Root>/currenttime' */
  uint8_T targetaltitude;              /* '<Root>/targetaltitude' */
} ExternalInputs_altitude_smoothening_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T desiredaltitude;            /* '<Root>/desiredaltitude' */
} ExternalOutputs_altitude_smoothening_T;

/* Real-time Model Data Structure */
struct tag_RTM_altitude_smoothening_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern BlockIO_altitude_smoothening_T altitude_smoothening_B;

/* External inputs (root inport signals with default storage) */
extern ExternalInputs_altitude_smoothening_T altitude_smoothening_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExternalOutputs_altitude_smoothening_T altitude_smoothening_Y;

/* Model entry point functions */
extern void altitude_smoothening_initialize(void);
extern void altitude_smoothening_step(void);
extern void altitude_smoothening_terminate(void);

/* Real-time Model object */
extern RT_MODEL_altitude_smoothening_T *const altitude_smoothening_M;

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
 * '<Root>' : 'altitude_smoothening'
 * '<S1>'   : 'altitude_smoothening/If Action Subsystem'
 * '<S2>'   : 'altitude_smoothening/If Action Subsystem1'
 */
#endif                                 /* altitude_smoothening_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
