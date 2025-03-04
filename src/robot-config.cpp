#include "vex.h"
#include "robot-config.h"
#include "Legacy-Template/constants.h"

using namespace vex;

/*---------------------------------------------------------------------------*/
/*                     Welcome to Robot Configuration!                         */
/*                                                                            */
/* This is where we set up all the components we declared in robot-config.h.  */
/* For each component, we need to specify:                                    */
/* 1. What PORT it's plugged into                                            */
/* 2. What TYPE of component it is (like what gear ratio for motors)         */
/* 3. Whether it's REVERSED or not                                           */
/*                                                                            */
/* PORTS: Look at the brain when plugging in components. Each port has a     */
/* number. For motors, they're labeled 1-21. For 3-wire devices, they're     */
/* labeled A-H.                                                              */
/*                                                                            */
/* GEAR RATIOS: VEX V5 motors come in different gear ratios:                 */
/* - ratio6_1: Fast (6:1)                                                    */
/* - ratio18_1: Balanced (18:1)                                              */
/* - ratio36_1: Strong (36:1)                                                */
/*                                                                            */
/* REVERSED: If a motor spins the wrong way, we can reverse it in code       */
/* instead of rewiring it. Set 'true' to reverse, 'false' to keep normal.    */
/*---------------------------------------------------------------------------*/

// The Brain - This is automatically configured
brain Brain;

// The Controller - This is for driving your robot
controller Controller1 = controller(primary);

/*---------------------------------------------------------------------------*/
/*                            Drive Motors                                    */
/*                                                                            */
/* These are the motors that make your robot move. For each motor, we need   */
/* to specify:                                                               */
/* 1. The PORT number it's plugged into                                      */
/* 2. The GEAR RATIO (usually 18:1 for drive motors)                        */
/* 3. Whether it needs to be REVERSED                                        */
/*                                                                            */
/* NOTE: Right side motors are usually reversed because they're mounted      */
/* opposite to the left side motors!                                         */
/*---------------------------------------------------------------------------*/

// Left drive motors
motor leftFront(PORT1, ratio18_1, false);  // Port 1, 18:1 gear ratio, not reversed
motor leftBack(PORT2, ratio18_1, false);   // Port 2, 18:1 gear ratio, not reversed

// Right drive motors (notice they're reversed!)
motor rightFront(PORT3, ratio18_1, true);  // Port 3, 18:1 gear ratio, reversed
motor rightBack(PORT4, ratio18_1, true);   // Port 4, 18:1 gear ratio, reversed

/*---------------------------------------------------------------------------*/
/*                              Sensors                                       */
/*                                                                            */
/* Sensors help your robot understand its surroundings. The inertial sensor  */
/* is especially important as it helps your robot know which way it's        */
/* facing.                                                                   */
/*---------------------------------------------------------------------------*/

// Inertial sensor - helps track rotation
inertial InertialSensor(PORT5);  // Plugged into port 5

/*---------------------------------------------------------------------------*/
/*                            Setup Functions                                 */
/*                                                                            */
/* These functions run when your program starts. They help set up your       */
/* robot and make sure everything is working properly.                       */
/*---------------------------------------------------------------------------*/

// This function runs when the program starts
void vexcodeInit(void) {
  // Calibrate the inertial sensor
  InertialSensor.calibrate();
  
  // Wait for calibration to finish
  while(InertialSensor.isCalibrating()) {
    wait(20, msec);
  }
  
  // Print a message when everything is ready
  Brain.Screen.print("Robot is ready!");
}
