#pragma once
#include "vex.h"

/**
 * File 5: Autonomous Routines
 * 
 * This is where you'll create your autonomous routines!
 * An autonomous routine is a sequence of movements that your robot
 * performs automatically at the start of a match.
 * 
 * Tips for Good Autonomous:
 * 1. Test each movement separately before combining them
 * 2. Use waitUntilSettled() between movements
 * 3. Add small delays if movements interfere with each other
 * 4. Comment your code well - you'll thank yourself later!
 */

namespace Autonomous {
  /**
   * Simple autonomous that drives forward and back
   * This is a good starting point for learning autonomous
   */
  void simpleAuto();
  
  /**
   * More complex autonomous that makes a square
   * This shows how to combine multiple movements
   */
  void squareAuto();
  
  /**
   * Competition autonomous
   * This is where you'll put your real autonomous routine
   */
  void competitionAuto();
  
  /**
   * Skills autonomous
   * This is for the skills challenge where you have 60 seconds
   */
  void skillsAuto();
}
