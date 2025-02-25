#include "Legacy/01_basics/motors.h"

/**
 * Example: How to set up motors for your robot
 * 
 * This file shows you how to add motors to your robot.
 * Copy the parts you need into your pre_auton() function!
 */

void pre_auton(void) {
  // First, initialize the motor system
  Basics::initializeMotors();
  
  // Now let's add motors!
  // Format: addMotor(Group, Port, Reversed)
  
  // DRIVE MOTORS
  // Left side
  Basics::addMotor(Basics::MotorGroup::LeftDrive, 1, true);   // Front left
  Basics::addMotor(Basics::MotorGroup::LeftDrive, 11, true);  // Back left
  
  // Right side
  Basics::addMotor(Basics::MotorGroup::RightDrive, 2, false); // Front right
  Basics::addMotor(Basics::MotorGroup::RightDrive, 12, false);// Back right
  
  // MECHANISM MOTORS
  // Intake
  Basics::addMotor(Basics::MotorGroup::Intake, 3, false);     // Single intake motor
  
  // Lift (two motors working together)
  Basics::addMotor(Basics::MotorGroup::Lift, 4, false);       // Left lift
  Basics::addMotor(Basics::MotorGroup::Lift, 5, true);        // Right lift (reversed)
  
  // Shooter
  Basics::addMotor(Basics::MotorGroup::Shooter, 6, false);    // Shooter motor
}

// Example of how to control these motors in your code:
void exampleControls() {
  // Drive controls (already implemented in main.cpp)
  Basics::arcadeDrive(50, 0);  // Drive forward at 50% power
  
  // Intake control
  if (Controller1.ButtonR1.pressing()) {
    // Intake in
    Basics::setGroupPower(Basics::MotorGroup::Intake, 100);
  }
  else if (Controller1.ButtonR2.pressing()) {
    // Intake out
    Basics::setGroupPower(Basics::MotorGroup::Intake, -100);
  }
  else {
    // Stop intake
    Basics::stopGroup(Basics::MotorGroup::Intake);
  }
  
  // Lift control
  if (Controller1.ButtonL1.pressing()) {
    // Lift up
    Basics::setGroupPower(Basics::MotorGroup::Lift, 100);
  }
  else if (Controller1.ButtonL2.pressing()) {
    // Lift down
    Basics::setGroupPower(Basics::MotorGroup::Lift, -100);
  }
  else {
    // Hold lift in place
    Basics::stopGroup(Basics::MotorGroup::Lift);
  }
  
  // Shooter control
  if (Controller1.ButtonA.pressing()) {
    // Run shooter
    Basics::setGroupPower(Basics::MotorGroup::Shooter, 100);
  }
  else {
    // Stop shooter
    Basics::stopGroup(Basics::MotorGroup::Shooter);
  }
}
