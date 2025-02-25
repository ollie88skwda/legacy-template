#pragma once
#include "vex.h"

/**
 * File 3: PID Control
 * 
 * Now we're getting to the exciting part - PID control!
 * PID helps us move more accurately by constantly adjusting our motor power.
 * 
 * Think of it like this:
 * - If you're driving a car to a spot 100 feet away:
 *   P (Proportional): Drive faster when far away, slower when close
 *   I (Integral): If you're consistently a little short, gradually increase power
 *   D (Derivative): Start slowing down early so you don't overshoot
 */

class PID {
private:
  // Current state
  float error = 0;          // How far we are from target
  float lastError = 0;      // Previous error (for derivative)
  float totalError = 0;     // Sum of all errors (for integral)
  float settledTime = 0;    // How long we've been at our target
  
  // PID constants (you'll tune these in tuning.h)
  float kP;  // Proportional - Main driving force
  float kI;  // Integral - Helps overcome small, consistent errors
  float kD;  // Derivative - Helps prevent overshooting
  
  // Settling parameters
  float minError;        // How close we need to be to target
  float settleTime;      // How long we need to stay at target
  
public:
  /**
   * Create a new PID controller
   * 
   * @param p Proportional constant
   * @param i Integral constant
   * @param d Derivative constant
   * @param minSettleError How close to target is "good enough"
   * @param requiredSettleTime How long to stay at target
   */
  PID(float p, float i, float d, float minSettleError = 2.0, float settleTime = 250);
  
  /**
   * Calculate the next motor power value
   * 
   * @param currentError Distance from target
   * @return Motor power (-100 to 100)
   */
  float calculate(float currentError);
  
  /**
   * Check if we've reached and stayed at our target
   */
  bool isSettled();
  
  /**
   * Reset the PID controller for a new movement
   */
  void reset();
};
