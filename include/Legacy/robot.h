#pragma once
#include "vex.h"
#include "Legacy/PID.h"

/**
 * @brief Robot Configuration and Movement Class
 * 
 * This class handles basic robot setup and movement functions.
 * It provides simple examples of how to use the PID controller
 * for precise movements.
 */
class Robot {
private:
  // Motor Configuration
  vex::motor leftMotor;   // Left drive motor
  vex::motor rightMotor;  // Right drive motor
  
  // PID Controllers
  PID* drivePID;    // For forward/backward movement
  PID* turnPID;     // For turning movements
  
  // Helper functions
  float getAveragePosition();
  float getRotation();
  
public:
  /**
   * @brief Create a new Robot controller
   * 
   * @param leftPort Port number for left motor
   * @param rightPort Port number for right motor
   */
  Robot(int leftPort, int rightPort);
  
  /**
   * @brief Drive forward/backward a specific distance
   * 
   * Example usage:
   * ```cpp
   * // Drive forward 12 inches
   * robot.driveDistance(12);
   * 
   * // Drive backward 6 inches
   * robot.driveDistance(-6);
   * ```
   * 
   * @param inches Distance to drive (positive = forward, negative = backward)
   */
  void driveDistance(float inches);
  
  /**
   * @brief Turn to a specific angle
   * 
   * Example usage:
   * ```cpp
   * // Turn 90 degrees clockwise
   * robot.turnAngle(90);
   * 
   * // Turn 45 degrees counter-clockwise
   * robot.turnAngle(-45);
   * ```
   * 
   * @param degrees Angle to turn (positive = clockwise, negative = counter-clockwise)
   */
  void turnAngle(float degrees);
  
  /**
   * @brief Stop all motors
   */
  void stop();
};
