// no super loop just for testing purpose if the .exe is  building
#include <iostream> // For printing to the console (std::cout)
#include <stdio.h>    // Alternative for printing (printf)
#include "Wrapper/FlightTrajectorySystem.hpp" // Include your wrapper's header

// The main() function is the entry point for any C/C++ executable.
int main() {
    printf("--- Trajectory System Host Test ---\n");

    // 1. Create an instance of your wrapper class.
    FlightTrajectorySystem trajectorySystem;

    // 2. Initialize the system.
    printf("Initializing models...\n");
    trajectorySystem.initialize();

    // 3. Define a test scenario.
    uint8_t totalTime = 20;      // 20 seconds
    uint8_t startAltitude = 10;  // 1000 feet (scaled)
    uint8_t targetAltitude = 50; // 5000 feet (scaled)

    printf("Running simulation for the 'Original' model...\n");
    printf("Time (s) | Desired Altitude\n");
    printf("----------------------------\n");

    // 4. Simulate the passage of time by running the logic in a loop.
    for (uint8_t currentTime = 0; currentTime <= totalTime + 5; ++currentTime) {
        uint16_t desiredAltitude = trajectorySystem.runOriginalTrajectory(
            currentTime,
            totalTime,
            startAltitude,
            targetAltitude
        );

        // 5. Print the output for each step.
        printf("%8d | %16d\n", currentTime, desiredAltitude);
    }
    
    printf("\n--- Test Complete ---\n");

    return 0; // A return value of 0 indicates the program finished successfully.
}