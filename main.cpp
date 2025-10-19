#include <iostream>
#include <chrono>
#include <thread>
#include "Wrapper/FlightTrajectorySystem.hpp"

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

        // <<< BENCHMARKING START >>>
        auto timing_start = std::chrono::high_resolution_clock::now();

        uint16_t desiredAltitudeOriginal = trajectorySystem.runOriginalTrajectory(
            currentTime_sec, totalTime, startAltitude, targetAltitude
        );

        auto timing_end = std::chrono::high_resolution_clock::now();
        auto execution_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(timing_end - timing_start).count();
        // <<< BENCHMARKING END >>>

        std::cout << "\r" << "Time: " << (int)currentTime_sec << "s | Desired Alt: " << desiredAltitudeOriginal
                  << " | Execution Time: " << execution_ns << " ns    " << std::flush;

        auto loopEndTime = std::chrono::steady_clock::now();
        auto executionDuration = loopEndTime - loopStartTime;
        auto sleepDuration = LOOP_PERIOD - executionDuration;
        
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }

    return 0;
}