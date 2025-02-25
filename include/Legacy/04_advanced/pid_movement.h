#pragma once
#include "vex.h"
#include "Legacy/03_pid/pid.h"

/**
 * File 4: Advanced Movement with PID
 * 
 * Now we'll combine our basic movement functions with PID control!
 * This gives us much more accurate and smooth movements.
 */

namespace AdvancedMovement {
  /**
   * Drive a specific distance using PID control
   * This is much more accurate than the basic version!
   * 
   * @param inches Distance to drive (positive = forward, negative = backward)
   */
  void driveDistance(float inches);
  
  /**
   * Turn to a specific angle using PID control
   * 
   * @param degrees Angle to turn (positive = right, negative = left)
   */
  void turnAngle(float degrees);
  
  /**
   * Drive to a specific point using PID control
   * This combines driving and turning!
   * 
   * @param x X coordinate to drive to (inches)
   * @param y Y coordinate to drive to (inches)
   */
  void driveToPoint(float x, float y);
}
