#include <iostream>   // For std::cout
#include <chrono>     // For managing time (milliseconds, steady_clock)
#include <thread>     // For pausing the execution (std::this_thread::sleep_for)

#include "Wrapper/FlightTrajectorySystem.hpp" // Your wrapper's header

// --- Configuration ---
// Define the frequency we want our loop to run at.
const int LOOP_FREQUENCY_HZ = 10; // Run at 10 times per second
// Calculate the required duration for one loop cycle.
const auto LOOP_PERIOD = std::chrono::milliseconds(1000 / LOOP_FREQUENCY_HZ);


int main() {
    std::cout << "--- Trajectory System Host Superloop ---" << std::endl;
    std::cout << "Running indefinitely at " << LOOP_FREQUENCY_HZ << " Hz. Press Ctrl+C to exit." << std::endl;

    // 1. Create and initialize the system.
    FlightTrajectorySystem trajectorySystem;
    trajectorySystem.initialize();

    // 2. Define the overall mission scenario.
    const uint8_t totalTime = 20;      // 20 seconds total maneuver time
    const uint8_t startAltitude = 10;
    const uint8_t targetAltitude = 50;

    // 3. Get the starting time of the "mission".
    auto missionStartTime = std::chrono::steady_clock::now();

    // 4. This is the "superloop", equivalent to `for(;;)` in a FreeRTOS task.
    while (true) {
        // Record the time at the beginning of this loop iteration.
        auto loopStartTime = std::chrono::steady_clock::now();

        // Calculate the current mission time.
        auto elapsedTime = loopStartTime - missionStartTime;
        uint8_t currentTime_sec = std::chrono::duration_cast<std::chrono::seconds>(elapsedTime).count();

        // Execute the core logic using the current mission time.
        uint16_t desiredAltitude = trajectorySystem.runOriginalTrajectory(
            currentTime_sec,
            totalTime,
            startAltitude,
            targetAltitude
        );

        // Print the output to the console. The '\r' moves the cursor to the
        // start of the line so each new printout overwrites the last one.
        std::cout << "\r" << "Mission Time: " << (int)currentTime_sec << "s  |  Desired Altitude: " << desiredAltitude << "    " << std::flush;

        // Calculate how long the logic and printing took.
        auto loopEndTime = std::chrono::steady_clock::now();
        auto executionDuration = loopEndTime - loopStartTime;

        // Calculate how long we need to sleep to maintain the desired frequency.
        auto sleepDuration = LOOP_PERIOD - executionDuration;
        
        // If the execution didn't take longer than our period, sleep for the remaining time.
        if (sleepDuration > std::chrono::milliseconds(0)) {
            std::this_thread::sleep_for(sleepDuration);
        }
    }

    // This part of the code is now unreachable, but it's good practice to keep it.
    return 0;
}