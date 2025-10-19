#include "FlightTrajectorySystem.hpp"

FlightTrajectorySystem::FlightTrajectorySystem() {
    // The constructor's job is to link the state structures together,
    // as the generated code expects.
    m_modelData.blockIO = &m_blockIO;
    m_modelData_p.blockIO = &m_blockIO_p;
}

void FlightTrajectorySystem::initialize() {
    // Call the initialize functions, passing pointers to our internal state
    // and I/O member variables. This correctly sets everything to zero.
    altitude_smoothening_initialize(&m_modelData, &m_U_startaltitude, &m_U_totaltime, &m_U_currenttime, &m_U_targetaltitude, &m_Y_desiredaltitude);
    altitude_smoothening_p_initialize(&m_modelData_p, &m_p_U_startaltitude, &m_p_U_totaltime, &m_p_U_currenttime, &m_p_U_targetaltitude, &m_p_Y_desiredaltitude);
}

// This method guarantees the correct "output -> update" sequence for the original model.
uint16_t FlightTrajectorySystem::executeStep(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude) {
    uint16_t desiredAltitude; // A local variable to hold the output

    // --- 1. Call the Output Function ---
    // Pass the model's state, all inputs by value, and a pointer to our output variable.
    altitude_smoothening_output(&m_modelData, startAltitude, totalTime, currentTime, targetAltitude, &desiredAltitude);

    // --- 2. Call the Update Function ---
    // This function advances the model's internal state for the next time step.
    altitude_smoothening_update(&m_modelData);

    return desiredAltitude;
}

// This method does the same for the modified "_p" model.
uint16_t FlightTrajectorySystem::executeStep_p(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude) {
    uint16_t desiredAltitude; // A local variable for the output

    altitude_smoothening_p_output(&m_modelData_p, startAltitude, totalTime, currentTime, targetAltitude, &desiredAltitude);
    altitude_smoothening_p_update(&m_modelData_p);

    return desiredAltitude;
}