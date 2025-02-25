#include "Legacy/04_advanced/pid_movement.h"
#include "Legacy/01_basics/motors.h"
#include "Legacy/03_pid/tuning.h"

using namespace vex;
using namespace Basics;

namespace AdvancedMovement {
  // Create our PID controllers using the tuned constants
  PID drivePID(
    PIDTuning::DrivePIDConstants::kP,
    PIDTuning::DrivePIDConstants::kI,
    PIDTuning::DrivePIDConstants::kD,
    PIDTuning::DrivePIDConstants::minError,
    PIDTuning::DrivePIDConstants::settleTime
  );
  
  PID turnPID(
    PIDTuning::TurnPIDConstants::kP,
    PIDTuning::TurnPIDConstants::kI,
    PIDTuning::TurnPIDConstants::kD,
    PIDTuning::TurnPIDConstants::minError,
    PIDTuning::TurnPIDConstants::settleTime
  );
  
  void driveDistance(float inches) {
    // Reset everything
    leftDrive.resetPosition();
    rightDrive.resetPosition();
    drivePID.reset();
    
    // Calculate target in motor degrees
    float targetDegrees = (inches / (Movement::WHEEL_CIRCUMFERENCE)) * 360.0;
    
    while (!drivePID.isSettled()) {
      // Get current position
      float currentDegrees = (leftDrive.position(rotationUnits::deg) + 
                            rightDrive.position(rotationUnits::deg)) / 2.0;
      
      // Calculate error
      float error = targetDegrees - currentDegrees;
      
      // Get motor power from PID
      float power = drivePID.calculate(error);
      
      // Apply power to motors
      tankDrive(power, power);
      
      task::sleep(10);
    }
    
    stopDrive();
  }
  
  void turnAngle(float degrees) {
    // Reset everything
    leftDrive.resetPosition();
    rightDrive.resetPosition();
    turnPID.reset();
    
    // Calculate how far each wheel needs to move
    float turnCircumference = Movement::TRACK_WIDTH * 3.14159;
    float turnDistance = (degrees / 360.0) * turnCircumference;
    float targetDegrees = (turnDistance / Movement::WHEEL_CIRCUMFERENCE) * 360.0;
    
    while (!turnPID.isSettled()) {
      // Get current rotation
      float currentDegrees = (rightDrive.position(rotationUnits::deg) - 
                            leftDrive.position(rotationUnits::deg)) / 2.0;
      
      // Calculate error
      float error = targetDegrees - currentDegrees;
      
      // Get motor power from PID
      float power = turnPID.calculate(error);
      
      // Apply opposite powers to turn
      tankDrive(-power, power);
      
      task::sleep(10);
    }
    
    stopDrive();
  }
  
  void driveToPoint(float x, float y) {
    // First turn to face the point
    float angle = atan2(y, x) * 180.0 / 3.14159;
    turnAngle(angle);
    
    // Then drive to it
    float distance = sqrt(x*x + y*y);
    driveDistance(distance);
  }
}
