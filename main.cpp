#include <iostream>
#include <chrono>
#include <thread>
#include "Wrapper/FlightTrajectorySystem.hpp"

const int LOOP_FREQUENCY_HZ = 10; // This MUST match your model's 0.1s sample time
const auto LOOP_PERIOD = std::chrono::milliseconds(1000 / LOOP_FREQUENCY_HZ);

int main() {
    std::cout << "--- Trajectory System (Output/Update) Host Superloop ---" << std::endl;

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

        // The main loop now makes one simple, safe call per model.
        uint16_t desiredAltitude = trajectorySystem.executeStep(
            currentTime_sec, totalTime, startAltitude, targetAltitude
        );
        uint16_t desiredAltitude_p = trajectorySystem.executeStep_p(
            currentTime_sec, totalTime, startAltitude, targetAltitude
        );

        std::cout << "\r" << "Time: " << (int)currentTime_sec << "s | Alt: " << desiredAltitude << " | Alt_p: " << desiredAltitude_p << "    " << std::flush;

        auto loopEndTime = std::chrono::steady_clock::now();
        auto executionDuration = loopEndTime - loopStartTime;
        auto sleepDuration = LOOP_PERIOD - executionDuration;
        
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }
    return 0;
}