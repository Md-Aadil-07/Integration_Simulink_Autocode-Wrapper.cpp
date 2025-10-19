#pragma once

#include <stdint.h> // For standard integer types

// The extern "C" block is crucial for linking C++ with C code.
extern "C" {
    // The base model is always included.
    #include "altitude_smoothening.h"

    // This block is conditional. The preprocessor will only include this header
    // if we provide the INCLUDE_MODIFIED_TRAJECTORY_MODEL flag during compilation.
    #ifdef INCLUDE_MODIFIED_TRAJECTORY_MODEL
    #include "altitude_smoothening_p.h"
    #endif
}

/**
 * @class FlightTrajectorySystem
 * @brief A modular C++ wrapper for Simulink models, configurable at compile time.
 */
class FlightTrajectorySystem {
public:
    FlightTrajectorySystem();
    void initialize();
    uint16_t runOriginalTrajectory(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude);

    // This method declaration is conditional. It will only exist in the class
    // if the compile-time flag is set.
    #ifdef INCLUDE_MODIFIED_TRAJECTORY_MODEL
    uint16_t runModifiedTrajectory(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude);
    #endif
};