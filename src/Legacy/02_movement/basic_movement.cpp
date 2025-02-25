#include "Legacy/02_movement/basic_movement.h"
#include "Legacy/01_basics/motors.h"

namespace Movement {
  // Helper function to convert inches to degrees of motor rotation
  float inchesToDegrees(float inches) {
    return (inches / WHEEL_CIRCUMFERENCE) * 360.0;
  }
  
  void driveDistance(float inches, int power) {
    // Step 1: Reset motor encoders
    leftDrive.resetPosition();
    rightDrive.resetPosition();
    
    // Step 2: Calculate target position in degrees
    float targetDegrees = inchesToDegrees(inches);
    
    // Step 3: Set the direction based on whether inches is positive or negative
    if (inches < 0) {
      power = -power;
    }
    
    // Step 4: Start moving
    Basics::tankDrive(power, power);
    
    // Step 5: Keep moving until we reach our target
    // We'll learn a better way to do this with PID later!
    while (fabs(leftDrive.position(vex::rotationUnits::deg)) < fabs(targetDegrees) &&
           fabs(rightDrive.position(vex::rotationUnits::deg)) < fabs(targetDegrees)) {
      vex::task::sleep(10); // Don't hog the CPU
    }
    
    // Step 6: Stop
    Basics::stopDrive();
  }
  
  void turn(float degrees, int power) {
    // Step 1: Reset motor encoders
    leftDrive.resetPosition();
    rightDrive.resetPosition();
    
    // Step 2: Calculate how far each wheel needs to turn
    // For a turn, one wheel moves forward while the other moves backward
    float turnCircumference = TRACK_WIDTH * 3.14159;
    float turnDistance = (degrees / 360.0) * turnCircumference;
    float targetDegrees = inchesToDegrees(turnDistance);
    
    // Step 3: Set direction based on turn direction
    int leftPower = power;
    int rightPower = -power;
    if (degrees < 0) {
      leftPower = -power;
      rightPower = power;
    }
    
    // Step 4: Start turning
    Basics::tankDrive(leftPower, rightPower);
    
    // Step 5: Keep turning until we reach our target
    while (fabs(leftDrive.position(vex::rotationUnits::deg)) < fabs(targetDegrees) &&
           fabs(rightDrive.position(vex::rotationUnits::deg)) < fabs(targetDegrees)) {
      vex::task::sleep(10);
    }
    
    // Step 6: Stop
    Basics::stopDrive();
  }
  
  void waitUntilSettled(int timeout) {
    // Get the current positions
    float startLeftPos = fabs(leftDrive.position(vex::rotationUnits::deg));
    float startRightPos = fabs(rightDrive.position(vex::rotationUnits::deg));
    
    // Keep track of time
    int timeWaited = 0;
    
    // Wait until the motors stop moving or we timeout
    while (timeWaited < timeout) {
      vex::task::sleep(10);
      timeWaited += 10;
      
      // Get new positions
      float currentLeftPos = fabs(leftDrive.position(vex::rotationUnits::deg));
      float currentRightPos = fabs(rightDrive.position(vex::rotationUnits::deg));
      
      // If we haven't moved in the last 100ms, we're settled
      if (fabs(currentLeftPos - startLeftPos) < 1 &&
          fabs(currentRightPos - startRightPos) < 1) {
        break;
      }
      
      // Update start positions
      startLeftPos = currentLeftPos;
      startRightPos = currentRightPos;
    }
  }
}
