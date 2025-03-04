#pragma once
#include "vex.h"

// This tells the compiler we're using the vex namespace
using namespace vex;

/*---------------------------------------------------------------------------*/
/*                              Drive Class                                    */
/*                                                                            */
/* This class handles all the movement of your robot. It has functions for:   */
/* - Tank drive (each stick controls one side of the robot)                   */
/* - Arcade drive (one stick controls forward/back, one controls turning)     */
/* - Moving specific distances                                                */
/* - Turning specific amounts                                                 */
/*---------------------------------------------------------------------------*/

namespace legacy {

// Different ways to set up your drive
enum class drive_setup {
  ZERO_TRACKER_NO_ODOM,  // Basic setup - no special tracking
  ZERO_TRACKER_ODOM,     // Adds odometry for position tracking
  TANK_ONE_ENCODER,      // Uses one encoder for tracking
  TANK_TWO_ENCODER,      // Uses two encoders for better tracking
  HOLONOMIC_TWO_ENCODER, // For X-drive or mecanum wheels
  HOLONOMIC_THREE_ENCODER // Most accurate holonomic tracking
};

class Drive {
  private:
    vex::motor_group DriveL;
    vex::motor_group DriveR;
    vex::inertial Gyro;
    drive_setup current_drive_setup = drive_setup::ZERO_TRACKER_NO_ODOM;

  public:
    Drive(
      drive_setup setup_type,
      vex::motor_group DriveL,
      vex::motor_group DriveR,
      vex::inertial Gyro
    );

    // Basic drive functions
    void set_tank(int left, int right);  // Added back for compatibility
    void set_arcade(int throttle, int turn);  // Added back for compatibility
    void tank_drive(int left, int right);
    void arcade_drive(int throttle, int turn);
    
    // Advanced movement functions
    void drive_distance(float distance, int max_speed = 100);
    void turn_degrees(float degrees, int max_speed = 100);
    void drive_voltage(int left_voltage, int right_voltage);
    
    // Sensor functions
    float get_heading();
    float get_absolute_heading();  // Added back for compatibility
    void reset_heading();
    void drive_stop(vex::brakeType mode = vex::brakeType::brake);  // Added back
};

} // namespace legacy
