#include "Legacy/03_pid/pid.h"

PID::PID(float p, float i, float d, float minSettleError, float requiredSettleTime) {
  // Store our constants
  kP = p;
  kI = i;
  kD = d;
  minError = minSettleError;
  settleTime = requiredSettleTime;
}

float PID::calculate(float currentError) {
  // Step 1: Store the error
  error = currentError;
  
  // Step 2: Calculate P term
  // This is the main driving force
  // If we're far from target, go fast
  // If we're close to target, go slow
  float pTerm = kP * error;
  
  // Step 3: Calculate I term
  // This helps overcome consistent small errors
  // Only start accumulating when we're close to target
  if (fabs(error) < 30) {  // Only accumulate within 30 units
    totalError += error;
  }
  // Reset accumulation if we cross the target
  if ((error > 0 && lastError < 0) || (error < 0 && lastError > 0)) {
    totalError = 0;
  }
  float iTerm = kI * totalError;
  
  // Step 4: Calculate D term
  // This helps prevent overshooting
  // If error is changing quickly, apply opposite force
  float dTerm = kD * (error - lastError);
  
  // Step 5: Update last error for next time
  lastError = error;
  
  // Step 6: Check if we're settled
  if (fabs(error) < minError) {
    settledTime += 10;  // Add 10ms to settled time
  } else {
    settledTime = 0;    // Reset if we move outside target
  }
  
  // Step 7: Calculate final output
  float output = pTerm + iTerm + dTerm;
  
  // Step 8: Limit output to valid motor power
  if (output > 100) output = 100;
  if (output < -100) output = -100;
  
  return output;
}

bool PID::isSettled() {
  return settledTime >= settleTime;
}

void PID::reset() {
  error = 0;
  lastError = 0;
  totalError = 0;
  settledTime = 0;
}
