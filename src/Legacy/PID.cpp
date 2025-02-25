#include "Legacy/PID.h"

PID::PID(float p, float i, float d, float minSettleError, float requiredSettleTime) {
  kP = p;
  kI = i;
  kD = d;
  minError = minSettleError;
  settleTime = requiredSettleTime;
}

float PID::calculate(float currentError) {
  // Store the current error
  error = currentError;
  
  // STEP 1: Calculate Proportional term
  // This provides the main corrective force
  float pTerm = kP * error;
  
  // STEP 2: Calculate Integral term
  // Only accumulate error if we're close to target (prevents integral windup)
  if (fabs(error) < 30) {
    totalError += error;
  }
  // Reset integral if we cross the target (helps prevent oscillation)
  if ((error > 0 && previousError < 0) || (error < 0 && previousError > 0)) {
    totalError = 0;
  }
  float iTerm = kI * totalError;
  
  // STEP 3: Calculate Derivative term
  // This helps dampen the movement and prevent overshooting
  float dTerm = kD * (error - previousError);
  
  // STEP 4: Update previous error for next iteration
  previousError = error;
  
  // STEP 5: Check settling status
  if (fabs(error) < minError) {
    timeSettled += 10;  // Assuming 10ms update rate
  } else {
    timeSettled = 0;
  }
  
  // STEP 6: Calculate and limit final output
  float output = pTerm + iTerm + dTerm;
  
  // Limit output to valid motor power range (-100 to 100)
  if (output > 100) output = 100;
  if (output < -100) output = -100;
  
  return output;
}

bool PID::isSettled() {
  return timeSettled >= settleTime;
}

void PID::reset() {
  error = 0;
  totalError = 0;
  previousError = 0;
  timeSettled = 0;
}
