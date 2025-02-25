#include "Legacy/01_basics/motors.h"
#include <vector>
#include <map>

namespace Basics {
  // Store our motors in groups
  std::map<MotorGroup, std::vector<vex::motor*>> motorGroups;

  void addMotor(MotorGroup group, int port, bool reversed) {
    // Create a new motor
    vex::motor* newMotor = new vex::motor(port, reversed);
    
    // Add it to its group
    motorGroups[group].push_back(newMotor);
  }

  void setGroupPower(MotorGroup group, int power) {
    // Make sure power is within valid range
    if (power > 100) power = 100;
    if (power < -100) power = -100;

    // Set power for all motors in the group
    for (vex::motor* motor : motorGroups[group]) {
      motor->spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
    }
  }

  void initializeMotors() {
    // Clear any existing motors
    motorGroups.clear();

    // Example: How to add motors
    // You can copy these lines and change the numbers to match your robot!
    
    // Left drive motors
    addMotor(MotorGroup::LeftDrive, 1, true);   // Port 1, reversed
    addMotor(MotorGroup::LeftDrive, 11, true);  // Port 11, reversed
    
    // Right drive motors
    addMotor(MotorGroup::RightDrive, 2, false); // Port 2, not reversed
    addMotor(MotorGroup::RightDrive, 12, false);// Port 12, not reversed
    
    // Example: Add an intake motor
    addMotor(MotorGroup::Intake, 3, false);     // Port 3, not reversed
    
    // Configure all motors
    for (auto& group : motorGroups) {
      for (vex::motor* motor : group.second) {
        // Set brake mode
        motor->setBrake(vex::brakeType::brake);
        
        // Reset position
        motor->resetPosition();
        
        // Set velocity units to percentage
        motor->setVelocityUnits(vex::velocityUnits::pct);
      }
    }
  }
  
  void tankDrive(int leftPower, int rightPower) {
    // Set power for each side of the drive
    setGroupPower(MotorGroup::LeftDrive, leftPower);
    setGroupPower(MotorGroup::RightDrive, rightPower);
  }
  
  void arcadeDrive(int forwardPower, int turnPower) {
    // Convert arcade (forward/turn) to tank (left/right)
    int leftPower = forwardPower + turnPower;
    int rightPower = forwardPower - turnPower;
    
    // Use tank drive to actually move
    tankDrive(leftPower, rightPower);
  }
  
  void stopGroup(MotorGroup group) {
    // Stop all motors in the group
    setGroupPower(group, 0);
  }
  
  void stopDrive() {
    // Stop both drive motor groups
    stopGroup(MotorGroup::LeftDrive);
    stopGroup(MotorGroup::RightDrive);
  }
}
