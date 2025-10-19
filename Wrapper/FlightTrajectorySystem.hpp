#pragma once

#include <stdint.h> // Include standard integer types for clarity (uint8_t, uint16_t)

// This is the most critical part for C/C++ interoperability.
// It tells the C++ compiler that the functions declared inside these
// header files are C functions, preventing C++ name mangling issues.
extern "C" {
#include "altitude_smoothening.h"
#include "altitude_smoothening_p.h"
}

/**
 * @class FlightTrajectorySystem
 * @brief A C++ wrapper to manage and consolidate the auto-generated Simulink models.
 *
 * This class provides a clean, object-oriented interface to the underlying C code
 * generated for the 'altitude_smoothening' and 'altitude_smoothening_p' models.
 * It encapsulates the global variables and C-style function calls, presenting
 * a stable API to the rest of the application.
 */
class FlightTrajectorySystem {
public:
    /**
     * @brief Constructor for the FlightTrajectorySystem.
     */
    FlightTrajectorySystem();

    /**
     * @brief Initializes both underlying C models. Must be called once before use.
     */
    void initialize();

    /**
     * @brief Executes one step of the original trajectory generation logic.
     * @param currentTime The current elapsed time of the maneuver.
     * @param totalTime The total planned duration of the maneuver.
     * @param startAltitude The altitude at the beginning of the maneuver.
     * @param targetAltitude The desired final altitude.
     * @return The calculated desired altitude for the current time step.
     */
    uint16_t runOriginalTrajectory(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude);

    /**
     * @brief Executes one step of the modified trajectory generation logic.
     * @param currentTime The current elapsed time of the maneuver.
     * @param totalTime The total planned duration of the maneuver.
     * @param startAltitude The altitude at the beginning of the maneuver.
     * @param targetAltitude The desired final altitude.
     * @return The calculated desired altitude for the current time step from the modified model.
     */
    uint16_t runModifiedTrajectory(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude);
};