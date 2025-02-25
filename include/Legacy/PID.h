#pragma once
#include "vex.h"

/**
 * @brief PID (Proportional-Integral-Derivative) Controller Class
 * 
 * This class implements a PID controller for precise robot movements.
 * 
 * How PID Works:
 * 1. Proportional (P): Responds directly to the error
 *    - Like a spring: the further from target, the stronger the response
 *    - If robot is 100 units away, it moves faster than if 10 units away
 * 
 * 2. Integral (I): Accumulates error over time
 *    - Helps overcome consistent small errors
 *    - If robot is slightly off target for a while, gradually increases power
 * 
 * 3. Derivative (D): Responds to rate of change
 *    - Acts like a dampener to prevent overshooting
 *    - Slows down the response as we approach the target
 */
class PID {
private:
  // Current error (difference between target and current position)
  float error = 0;
  
  // PID Constants (you'll need to tune these for your robot)
  float kP = 0;  // Proportional constant
  float kI = 0;  // Integral constant
  float kD = 0;  // Derivative constant
  
  // Error accumulation for I term
  float totalError = 0;
  float previousError = 0;
  
  // Settling parameters
  float minError;        // Minimum error to consider settled
  float settleTime;      // Time needed to be within minError to be settled
  float timeSettled = 0; // Time spent within minError
  
public:
  /**
   * @brief Create a new PID controller
   * 
   * @param p Proportional constant (responds to current error)
   * @param i Integral constant (responds to accumulated error)
   * @param d Derivative constant (responds to change in error)
   * @param minSettleError Minimum error to consider the robot settled
   * @param requiredSettleTime Time (ms) robot must be settled
   */
  PID(float p, float i, float d, float minSettleError = 2.0, float requiredSettleTime = 250);
  
  /**
   * @brief Calculate the next motor power value
   * 
   * @param currentError Difference between target and current position
   * @return float Motor power (-100 to 100)
   */
  float calculate(float currentError);
  
  /**
   * @brief Check if the robot has reached and settled at the target
   * 
   * @return true if settled, false otherwise
   */
  bool isSettled();
  
  /**
   * @brief Reset the PID controller for a new movement
   */
  void reset();
};
