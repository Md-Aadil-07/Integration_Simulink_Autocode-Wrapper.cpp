#pragma once

#include <stdint.h>

// Include both generated headers. Your previous settings for unique
// identifiers have prevented any conflicts.
extern "C" {
#include "altitude_smoothening.h"
#include "altitude_smoothening_p.h"
}

/**
 * @class FlightTrajectorySystem
 * @brief Manages Simulink models with separate output/update phases.
 *
 * This wrapper owns the internal state of the generated models and orchestrates
 * the correct calling sequence of their output and update functions.
 */
class FlightTrajectorySystem {
public:
    FlightTrajectorySystem();
    void initialize();

    // A single, clean method to execute a full, correctly sequenced cycle.
    uint16_t executeStep(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude);
    uint16_t executeStep_p(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude);

private:
    // The wrapper owns the state data for EACH model as a private member.
    RT_MODEL_altitude_smoothening_sT m_modelData;
    RT_MODEL_altitude_smoothening_p_sT m_modelData_p;

    // It also needs to own the storage for the model's internal signals (Block I/O).
    B_altitude_smoothening_sT m_blockIO;
    B_altitude_smoothening_p_sT m_blockIO_p;
    
    // Member variables for the I/O, as the initialize function expects pointers to them.
    uint8_t m_U_startaltitude;
    uint8_t m_U_totaltime;
    uint8_t m_U_currenttime;
    uint8_t m_U_targetaltitude;
    uint16_t m_Y_desiredaltitude;

    uint8_t m_p_U_startaltitude;
    uint8_t m_p_U_totaltime;
    uint8_t m_p_U_currenttime;
    uint8_t m_p_U_targetaltitude;
    uint16_t m_p_Y_desiredaltitude;
};