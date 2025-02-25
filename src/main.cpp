#include "vex.h"
#include "robot-config.h"

using namespace vex;

// A global instance of competition
competition Competition;

/*---------------------------------------------------------------------------*/
/*                          Legacy Template Config                             */
/*                                                                            */
/*  This is where you set up your robot's drive system. Follow the           */
/*  instructions below to configure your robot's motors and settings.         */
/*---------------------------------------------------------------------------*/

// Create the drive system
Drive chassis(
  // Left side motors - Add all your left drive motors here
  motor_group(),

  // Right side motors - Add all your right drive motors here
  motor_group(),

  // Drive settings
  4.125,    // Wheel diameter (inches) (4" omnis are actually 4.125")
  1.0     // Drive gear ratio (if your wheels are geared up/down from motors)
);

/*---------------------------------------------------------------------------*/
/*                          Drive Control Settings                             */
/*                                                                            */
/*  Choose how you want to control your robot during driver control.          */
/*---------------------------------------------------------------------------*/

// Choose your drive type: true for arcade, false for tank
bool arcade_drive = true;  // Change this to false if you want tank drive

/*---------------------------------------------------------------------------*/
/*                              Pre-Autonomous                                 */
/*                                                                            */
/*  This runs before autonomous starts. You can use it to set up your        */
/*  robot's starting position or reset sensors.                              */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initialize devices from robot-config.cpp
  vexcodeInit();
  
  // Reset sensors
  chassis.reset_heading();  // Reset gyro to 0
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                                */
/*                                                                            */
/*  This runs during the autonomous period. Write your autonomous code here.  */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // Example autonomous routine:
  
  // Drive forward 24 inches
  chassis.drive_distance(24);
  
  // Turn 90 degrees
  chassis.turn_to_angle(90);
  
  // Drive forward 12 inches
  chassis.drive_distance(12);
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                             */
/*                                                                            */
/*  This runs during the driver control period. Write your driver code here. */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    // Replace this line with:
    // chassis.control_tank(); for tank drive
    // chassis.control_arcade_reverse(); for reverse arcade drive
    chassis.control_arcade();
    

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

/*---------------------------------------------------------------------------*/
/*                                  Main Task                                 */
/*                                                                            */
/*  This is where the competition template starts. You shouldn't need to     */
/*  modify anything below this line.                                         */
/*---------------------------------------------------------------------------*/

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
