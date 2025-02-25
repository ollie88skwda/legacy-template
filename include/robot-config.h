#pragma once
#include "vex.h"
#include "Legacy/01_basics/drive.h"

using namespace vex;

/*---------------------------------------------------------------------------*/
/*                          Robot Configuration                               */
/*                                                                            */
/*  INSTRUCTIONS:                                                             */
/*  1. Declare your motors and devices here                                  */
/*  2. Initialize them in robot-config.cpp                                   */
/*  3. Set up your drive system in main.cpp                                 */
/*---------------------------------------------------------------------------*/

// Brain - This is your robot's brain! Used for printing to the screen
extern brain Brain;

// Drive Motors - These are your main drive motors
extern motor leftFront;    // Left front drive motor
extern motor leftBack;     // Left back drive motor
extern motor rightFront;   // Right front drive motor
extern motor rightBack;    // Right back drive motor

// Controller - This is your main controller
extern controller Controller1;

/*---------------------------------------------------------------------------*/
/*                          Add Your Custom Motors                             */
/*                                                                            */
/*  Add your mechanism motors below. Follow this format:                      */
/*  extern motor motorName;  // Description of what this motor does           */
/*                                                                            */
/*  Example:                                                                  */
/*  extern motor intakeMotor;  // Motor for the ball intake                  */
/*  extern motor liftMotor;    // Motor for the main lift                    */
/*---------------------------------------------------------------------------*/

// Add your motors here:
// extern motor intakeMotor;  // Uncomment and rename as needed
// extern motor liftMotor;    // Uncomment and rename as needed

/*---------------------------------------------------------------------------*/
/*                            Add Your Sensors                                 */
/*                                                                            */
/*  Add any sensors (like a gyro) below. Follow this format:                 */
/*  extern device_type deviceName;  // Description of what this device does   */
/*                                                                            */
/*  Example:                                                                  */
/*  extern inertial Gyro;        // Inertial sensor for tracking rotation    */
/*  extern distance distSensor;  // Distance sensor for object detection     */
/*---------------------------------------------------------------------------*/

// Add your sensors here:
// extern inertial Gyro;  // Uncomment and rename as needed

// This function runs all the setup code for your robot
void vexcodeInit(void);
