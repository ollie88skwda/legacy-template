#include "Legacy/05_autonomous/auto_routines.h"
#include "Legacy/04_advanced/pid_movement.h"

using namespace vex;
using namespace AdvancedMovement;

namespace Autonomous {
  void simpleAuto() {
    // Example of a simple autonomous routine
    
    // Step 1: Drive forward 24 inches
    driveDistance(24);
    
    // Step 2: Turn 90 degrees right
    turnAngle(90);
    
    // Step 3: Drive forward 12 inches
    driveDistance(12);
    
    // Step 4: Turn back to starting angle
    turnAngle(-90);
  }
  
  void squareAuto() {
    // Example of making a 24-inch square
    
    // Repeat 4 times to make a square
    for (int i = 0; i < 4; i++) {
      // Drive forward 24 inches
      AdvancedMovement::driveDistance(24);
      Movement::waitUntilSettled();
      
      // Turn 90 degrees
      AdvancedMovement::turnAngle(90);
      Movement::waitUntilSettled();
    }
  }
  
  void competitionAuto() {
    // This is where you'll write your competition autonomous
    // Here's an example structure:
    
    // Step 1: Get first goal
    AdvancedMovement::driveToPoint(36, 0);  // Drive to first goal
    Movement::waitUntilSettled();
    // Your code to grab the goal would go here
    
    // Step 2: Move to scoring position
    AdvancedMovement::driveToPoint(0, 36);  // Drive to scoring position
    Movement::waitUntilSettled();
    // Your code to score would go here
    
    // Continue with more steps...
  }
  
  void skillsAuto() {
    // This is where you'll write your skills autonomous
    // You have 60 seconds to score as many points as possible
    // Here's an example structure:
    
    // Step 1: Score preload
    AdvancedMovement::driveDistance(24);
    Movement::waitUntilSettled();
    // Your scoring code here
    
    // Step 2: Get and score more goals
    AdvancedMovement::driveToPoint(-24, 24);
    Movement::waitUntilSettled();
    // Your code to get next goal
    
    // Continue with more steps...
  }
}
