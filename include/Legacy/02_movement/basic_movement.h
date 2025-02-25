#pragma once
#include "vex.h"

/**
 * File 2: Basic Movement Functions
 * 
 * Now that we understand motors, let's create some basic movement functions!
 * Here you'll learn how to:
 * 1. Move forward/backward a specific distance
 * 2. Turn a specific number of degrees
 * 3. Use motor encoders for precise movement
 */

namespace Movement {
  // Constants for movement calculations
  const float WHEEL_DIAMETER = 4.0;  // inches
  const float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * 3.14159;
  const float TRACK_WIDTH = 12.0;    // Distance between wheels in inches
  
  /**
   * Drive forward or backward a specific distance
   * This uses motor encoders but NO PID control yet
   * 
   * @param inches Distance to drive (positive = forward, negative = backward)
   * @param power Motor power to use (0-100)
   */
  void driveDistance(float inches, int power);
  
  /**
   * Turn the robot a specific number of degrees
   * This uses motor encoders but NO PID control yet
   * 
   * @param degrees Degrees to turn (positive = right, negative = left)
   * @param power Motor power to use (0-100)
   */
  void turn(float degrees, int power);
  
  /**
   * Wait until the robot has finished its current movement
   * This checks the motor encoders to see if we've reached our target
   * 
   * @param timeout Maximum time to wait (in milliseconds)
   */
  void waitUntilSettled(int timeout = 5000);
}
