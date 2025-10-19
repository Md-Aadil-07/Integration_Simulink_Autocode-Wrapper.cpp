#include <iostream>
#include <chrono>
#include <thread>
#include "Wrapper/FlightTrajectorySystem.hpp"

// --- Configuration ---
// This value is now dictated by the design of your Simulink model.
// Your Simulink Sample Time is 0.1 seconds, which is a frequency of 1 / 0.1 = 10 Hz.
// THIS CONSTANT MUST MATCH YOUR SIMULINK SAMPLE TIME!
const int LOOP_FREQUENCY_HZ = 10;

// This calculation remains the same.
const auto LOOP_PERIOD = std::chrono::milliseconds(1000 / LOOP_FREQUENCY_HZ);


int main() {
    std::cout << "--- Trajectory System Host Superloop (Discrete-Time Simulation) ---" << std::endl;
    std::cout << "Running at a fixed frequency of " << LOOP_FREQUENCY_HZ << " Hz (0.1s sample time). Press Ctrl+C to exit." << std::endl;

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

        // The core logic execution remains identical. The superloop's timing
        // is what ensures the model's sample time requirement is met.
        uint16_t desiredAltitude = trajectorySystem.runOriginalTrajectory(
            currentTime_sec,
            totalTime,
            startAltitude,
            targetAltitude
        );

        std::cout << "\r" << "Mission Time: " << (int)currentTime_sec << "s  |  Desired Altitude: " << desiredAltitude << "    " << std::flush;

        auto loopEndTime = std::chrono::steady_clock::now();
        auto executionDuration = loopEndTime - loopStartTime;
        auto sleepDuration = LOOP_PERIOD - executionDuration;
        
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }

    return 0;
}