#include "vex.h"
#include "robot-config.h"
#include "Legacy-Template/drive.h"
#include "Legacy-Template/constants.h"

using namespace vex;
using namespace legacy;

// A global instance of competition
competition Competition;

// Create our drive system
legacy::Drive chassis(
  drive_setup::ZERO_TRACKER_NO_ODOM,  // Using enum class syntax
  motor_group(leftFront, leftBack),   // Left motors
  motor_group(rightFront, rightBack), // Right motors
  InertialSensor                      // Gyro sensor
);

// Variables for autonomous selection
int current_auton_selection = 0;  // Keeps track of which autonomous routine to run
bool auto_started = false;        // Indicates if autonomous has started

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                           */
/*                                                                            */
/* You may want to perform some actions before the competition starts.        */
/* Do them in the following function.  You must return from this function     */
/* or the autonomous and usercontrol tasks will not be started.              */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initialize robot configuration
  vexcodeInit();
  
  // Set up default constants
  legacy::default_constants();

  // Allow time to select autonomous routine
  while(!auto_started) {
    // Display current selection on the screen
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1,1);
    switch(current_auton_selection) {
      case 0:
        Brain.Screen.print("Autonomous: Drive Forward");
        break;
      case 1:
        Brain.Screen.print("Autonomous: Turn and Drive");
        break;
    }
    
    // Check for button press to change selection
    if(Brain.Screen.pressing()) {
      current_auton_selection++;
      if(current_auton_selection > 1) current_auton_selection = 0;
      wait(200, msec); // Debounce delay
    }
    
    wait(20, msec); // Don't hog the CPU
  }
}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                               */
/*                                                                            */
/* This task is used to control your robot during the autonomous phase of    */
/* a VEX Competition.                                                        */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  auto_started = true;  // Mark that autonomous has started
  
  // Run the selected autonomous routine
  switch(current_auton_selection) {
    case 0:  // Basic drive forward
      chassis.drive_distance(24);  // Drive forward 24 inches
      break;
      
    case 1:  // Turn and drive
      chassis.drive_distance(24);  // Drive forward 24 inches
      chassis.turn_degrees(90);    // Turn 90 degrees right
      chassis.drive_distance(24);  // Drive forward 24 inches
      break;
  }
}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                             */
/*                                                                            */
/* This task is used to control your robot during the user control phase of  */
/* a VEX Competition.                                                        */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  while (1) {
    // Get the controller's joystick values
    int left_speed = Controller1.Axis3.position();
    int right_speed = Controller1.Axis2.position();
    
    // Update the drive based on controller input
    chassis.set_tank(left_speed, right_speed);
    
    // Display some useful information on the brain's screen
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(5, 20, "Left Speed: %d", left_speed);
    Brain.Screen.printAt(5, 40, "Right Speed: %d", right_speed);
    Brain.Screen.printAt(5, 60, "Heading: %f deg", chassis.get_absolute_heading());
    
    // A brief delay to prevent wasted resources
    wait(20, msec);
  }
}

/*---------------------------------------------------------------------------*/
/*                          Main Competition Template                         */
/*                                                                            */
/* Do not modify the code in this task unless you know what you're doing.    */
/* This task is used to run the user control and autonomous programs.        */
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
