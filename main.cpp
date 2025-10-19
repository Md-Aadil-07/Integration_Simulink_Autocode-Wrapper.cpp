#include <iostream>
#include <chrono>
#include <thread>
#include "Wrapper/FlightTrajectorySystem.hpp"

// This loop frequency must match the sample time of your Simulink models (1 / 0.1s = 10 Hz)
const int LOOP_FREQUENCY_HZ = 10;
const auto LOOP_PERIOD = std::chrono::milliseconds(1000 / LOOP_FREQUENCY_HZ);

int main() {
    std::cout << "--- Trajectory System Host Superloop ---" << std::endl;
    std::cout << "Running at " << LOOP_FREQUENCY_HZ << " Hz. Press Ctrl+C to exit." << std::endl;

    FlightTrajectorySystem trajectorySystem;
    trajectorySystem.initialize();

    const uint8_t totalTime = 20;
    const uint8_t startAltitude = 10;
    const uint8_t targetAltitude = 50;

    auto missionStartTime = std::chrono::steady_clock::now();

    while (true) {
        auto loopStartTime = std::chrono::steady_clock::now();
        auto elapsedTime = loopStartTime - missionStartTime;
        uint8_t currentTime_sec = std::chrono::duration_cast<std::chrono::seconds>(elapsedTime).count();

        // The original model is always executed.
        uint16_t desiredAltitudeOriginal = trajectorySystem.runOriginalTrajectory(
            currentTime_sec, totalTime, startAltitude, targetAltitude
        );

        // Print the output, using '\r' to keep it on a single updating line.
        std::cout << "\r" << "Time: " << (int)currentTime_sec << "s | Original Alt: " << desiredAltitudeOriginal;

        // This block is conditional. It will only be compiled if the flag is set.
        // This allows this same main.cpp to work for both build configurations.
        #ifdef INCLUDE_MODIFIED_TRAJECTORY_MODEL
        uint16_t desiredAltitudeModified = trajectorySystem.runModifiedTrajectory(
            currentTime_sec, totalTime, startAltitude, targetAltitude
        );
        std::cout << " | Modified Alt: " << desiredAltitudeModified;
        #endif

        std::cout << "    " << std::flush; // Add padding and flush the output buffer

        auto loopEndTime = std::chrono::steady_clock::now();
        auto executionDuration = loopEndTime - loopStartTime;
        auto sleepDuration = LOOP_PERIOD - executionDuration;
        
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }

    return 0;
}