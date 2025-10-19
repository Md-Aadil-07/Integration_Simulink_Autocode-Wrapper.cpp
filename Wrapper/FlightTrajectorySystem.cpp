#include "FlightTrajectorySystem.hpp"

FlightTrajectorySystem::FlightTrajectorySystem() {}

void FlightTrajectorySystem::initialize() {
    // The base model is always initialized.
    altitude_smoothening_initialize();

    // This initialization call is conditional.
    #ifdef INCLUDE_MODIFIED_TRAJECTORY_MODEL
    altitude_smoothening_p_initialize();
    #endif
}

uint16_t FlightTrajectorySystem::runOriginalTrajectory(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude) {
    altitude_smoothening_U.currenttime = currentTime;
    altitude_smoothening_U.totaltime = totalTime;
    altitude_smoothening_U.startaltitude = startAltitude;
    altitude_smoothening_U.targetaltitude = targetAltitude;

    altitude_smoothening_step();

    return altitude_smoothening_Y.desiredaltitude;
}

// This entire function implementation is conditional. It will not be compiled
// into the final program unless the flag is defined.
#ifdef INCLUDE_MODIFIED_TRAJECTORY_MODEL
uint16_t FlightTrajectorySystem::runModifiedTrajectory(uint8_t currentTime, uint8_t totalTime, uint8_t startAltitude, uint8_t targetAltitude) {
    altitude_smoothening_p_U.currenttime = currentTime;
    altitude_smoothening_p_U.totaltime = totalTime;
    altitude_smoothening_p_U.startaltitude = startAltitude;
    altitude_smoothening_p_U.targetaltitude = targetAltitude;

    altitude_smoothening_p_step();

    return altitude_smoothening_p_Y.desiredaltitude;
}
#endif