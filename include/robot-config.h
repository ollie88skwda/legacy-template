#pragma once
#include "vex.h"
#include "Legacy-Template/drive.h"

using namespace vex;

/*---------------------------------------------------------------------------*/
/*                        Welcome to Robot Configuration!                      */
/*                                                                            */
/* This is where we declare all the parts that make up your robot. Think of  */
/* this like making a list of all the components you'll need before building */
/* something - you want to know what pieces you have before you start!       */
/*                                                                            */
/* IMPORTANT TERMS:                                                           */
/* - 'extern': This keyword tells the program that these variables will be    */
/*   defined in another file (robot-config.cpp)                              */
/* - 'motor': This is the type of device we're declaring                     */
/* - The name after 'motor': This is what we'll call this motor in our code  */
/*---------------------------------------------------------------------------*/

// The Brain is the command center of your robot
extern brain Brain;

// The Controller is what you use to drive your robot
extern controller Controller1;

/*---------------------------------------------------------------------------*/
/*                              Drive Motors                                  */
/*                                                                            */
/* These are the motors that make your robot move around the field. Most     */
/* robots use either 2 or 4 drive motors:                                    */
/*                                                                            */
/* 2-motor drive (simple):        4-motor drive (more powerful):             */
/* - 1 left motor                 - 1 left front motor                       */
/* - 1 right motor                - 1 left back motor                        */
/*                                - 1 right front motor                       */
/*                                - 1 right back motor                        */
/*---------------------------------------------------------------------------*/

// Drive Motors - Start by uncommenting the motors you're using
// extern motor leftDrive;      // For 2-motor drive
// extern motor rightDrive;     // For 2-motor drive

extern motor leftFront;    // For 4-motor drive
extern motor leftBack;     // For 4-motor drive
extern motor rightFront;   // For 4-motor drive
extern motor rightBack;    // For 4-motor drive

/*---------------------------------------------------------------------------*/
/*                              Other Motors                                  */
/*                                                                            */
/* These are motors for other mechanisms on your robot, like:                */
/* - Lift arms                                                               */
/* - Intakes                                                                 */
/* - Shooters                                                                */
/* - Catapults                                                               */
/*                                                                            */
/* To add a new motor:                                                       */
/* 1. Uncomment one of the lines below                                       */
/* 2. Change the name to something that describes what it does               */
/* 3. Add a comment explaining what this motor is for                        */
/*---------------------------------------------------------------------------*/

// Add your mechanism motors here:
// extern motor liftMotor;      // Motor for the main lift
// extern motor intakeMotor;    // Motor for collecting game pieces
// extern motor shooterMotor;   // Motor for shooting game pieces

/*---------------------------------------------------------------------------*/
/*                                Sensors                                     */
/*                                                                            */
/* Sensors help your robot understand its surroundings. Common sensors are:  */
/* - Inertial: Measures rotation (like a gyroscope)                         */
/* - Distance: Measures how far away objects are                            */
/* - Optical: Detects colors and objects                                    */
/* - Limit Switch: Detects when something is pressed                        */
/*---------------------------------------------------------------------------*/

// Add your sensors here:
extern inertial InertialSensor;  // Helps track robot rotation
// extern distance DistanceSensor;  // Measures distance to objects
// extern optical OpticalSensor;    // Detects colors/objects
// extern limit LimitSwitch;        // Detects when pressed

/*---------------------------------------------------------------------------*/
/*                            Function Declarations                           */
/*                                                                            */
/* These functions will be defined in robot-config.cpp. They help set up     */
/* your robot when the program starts.                                       */
/*---------------------------------------------------------------------------*/

// This function runs all the setup code for your robot
void vexcodeInit(void);

// This function sets up default values for autonomous routines
void default_constants(void);
