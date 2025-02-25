#pragma once

/**
 * File 3.5: PID Tuning Guide
 * 
 * Tuning PID constants is both an art and a science.
 * This file will guide you through the process of tuning your PID controllers.
 * 
 * General Tuning Process:
 * 1. Start with all constants at 0
 * 2. Increase kP until the robot moves to target with some oscillation
 * 3. Increase kD to reduce oscillation
 * 4. If needed, add a small amount of kI to correct steady-state error
 * 
 * Common Issues and Solutions:
 * 
 * Problem: Robot oscillates around target
 * Solution: 
 * - Decrease kP
 * - Increase kD
 * - Make sure kI isn't too high
 * 
 * Problem: Robot moves too slowly
 * Solution:
 * - Increase kP
 * - Make sure kD isn't too high
 * 
 * Problem: Robot doesn't quite reach target
 * Solution:
 * - Increase kI slightly
 * - Decrease minSettleError
 * 
 * Starting Values for Different Movement Types:
 */

namespace PIDTuning {
  // Drive straight PID
  // These values control forward/backward movement
  struct DrivePIDConstants {
    static constexpr float kP = 0.5;   // Start here, adjust as needed
    static constexpr float kI = 0.001; // Start very small
    static constexpr float kD = 0.1;   // Usually about 1/5 of kP
    
    // Settling parameters
    static constexpr float minError = 0.5;    // Inches
    static constexpr float settleTime = 250;  // Milliseconds
  };
  
  // Turn PID
  // These values control rotation
  struct TurnPIDConstants {
    static constexpr float kP = 0.8;   // Usually higher than drive kP
    static constexpr float kI = 0.001; // Start very small
    static constexpr float kD = 0.2;   // Usually about 1/4 of kP
    
    // Settling parameters
    static constexpr float minError = 1.0;    // Degrees
    static constexpr float settleTime = 250;  // Milliseconds
  };
}
