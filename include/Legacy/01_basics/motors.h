#pragma once
#include "vex.h"

/**
 * File 1: Basic Motor Control
 * 
 * This is your starting point for VEX robotics programming!
 * Here you'll learn how to:
 * 1. Set up motors
 * 2. Control multiple motors
 * 3. Group motors together
 */

namespace Basics {
  // Motor Groups
  // A motor group is a collection of motors that work together
  enum class MotorGroup {
    LeftDrive,    // Left side drive motors
    RightDrive,   // Right side drive motors
    Intake,       // Intake motors
    Lift,         // Lift motors
    Shooter       // Shooter motors
  };

  /**
   * Add a motor to a group
   * Example: addMotor(MotorGroup::LeftDrive, 1, true);
   * 
   * @param group Which group to add the motor to
   * @param port The port number (1-21)
   * @param reversed Should the motor spin backwards? (true/false)
   */
  void addMotor(MotorGroup group, int port, bool reversed = false);

  /**
   * Set the power for all motors in a group
   * Example: setGroupPower(MotorGroup::Intake, 100);
   * 
   * @param group Which group to control
   * @param power Power level (-100 to 100)
   */
  void setGroupPower(MotorGroup group, int power);

  /**
   * Initialize all motors with their correct settings
   * Call this in pre_auton()
   */
  void initializeMotors();
  
  /**
   * Tank drive control (each stick controls one side)
   * 
   * @param leftPower Power for left motors (-100 to 100)
   * @param rightPower Power for right motors (-100 to 100)
   */
  void tankDrive(int leftPower, int rightPower);
  
  /**
   * Arcade drive control (one stick controls all movement)
   * 
   * @param forwardPower Power for forward/backward (-100 to 100)
   * @param turnPower Power for turning (-100 to 100)
   */
  void arcadeDrive(int forwardPower, int turnPower);
  
  /**
   * Stop all motors in a group
   * 
   * @param group Which group to stop
   */
  void stopGroup(MotorGroup group);

  /**
   * Stop all drive motors
   */
  void stopDrive();
}
