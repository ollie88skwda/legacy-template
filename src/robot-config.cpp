#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors - Modify these based on your robot's configuration!

/*---------------------------------------------------------------------------*/
/*                            Drive Configuration                              */
/*---------------------------------------------------------------------------*/

// Example drive motor configuration (uncomment and modify for your robot):
/*
// Left drive motors
motor leftFront(PORT1, ratio18_1, false);  // Port 1, 18:1 gear ratio, not reversed
motor leftBack(PORT2, ratio18_1, false);   // Port 2, 18:1 gear ratio, not reversed

// Right drive motors (reversed because they are on the opposite side)
motor rightFront(PORT3, ratio18_1, true);  // Port 3, 18:1 gear ratio, reversed
motor rightBack(PORT4, ratio18_1, true);   // Port 4, 18:1 gear ratio, reversed

// Optional: Inertial sensor for gyro functions
inertial DriveInertial(PORT5);             // Port 5, inertial sensor
*/

/*---------------------------------------------------------------------------*/
/*                             Arm Configuration                               */
/*---------------------------------------------------------------------------*/

// Example arm motor configuration (uncomment and modify for your robot):
/*
// Arm motors (could be paired in a motor group for synchronization)
motor armLeft(PORT6, ratio36_1, false);    // Port 6, 36:1 gear ratio, not reversed
motor armRight(PORT7, ratio36_1, true);    // Port 7, 36:1 gear ratio, reversed
*/

/*---------------------------------------------------------------------------*/
/*                           Intake Configuration                              */
/*---------------------------------------------------------------------------*/

// Example intake motor configuration (uncomment and modify for your robot):
/*
// Intake motors
motor intakeLeft(PORT8, ratio6_1, false);  // Port 8, 6:1 gear ratio, not reversed
motor intakeRight(PORT9, ratio6_1, true);  // Port 9, 6:1 gear ratio, reversed
*/

/*---------------------------------------------------------------------------*/
/*                         Controller Configuration                            */
/*---------------------------------------------------------------------------*/

// VEX Controller - Primary controller for the robot
controller Controller1 = controller(primary);

// Optional: Secondary controller for partner control
// controller Controller2 = controller(partner);

/*---------------------------------------------------------------------------*/
/*                         Sensor Configuration                                */
/*---------------------------------------------------------------------------*/

// Example sensor configurations (uncomment and modify for your robot):
/*
// Distance sensor for object detection
distance DistanceSensor = distance(PORT10);

// Optical sensor for line following or color detection
optical OpticalSensor = optical(PORT11);

// Limit switch for arm limits
limit LimitSwitch = limit(Brain.ThreeWirePort.A);

// Rotation sensor for tracking movement
rotation RotationSensor = rotation(PORT12, false); // not reversed
*/

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 */
void vexcodeInit(void) {
  // Initialization code for sensors and motors can go here
  // Example: calibrating the inertial sensor
  /*
  DriveInertial.calibrate();
  while(DriveInertial.isCalibrating()) {
    wait(20, msec);
  }
  */
}
