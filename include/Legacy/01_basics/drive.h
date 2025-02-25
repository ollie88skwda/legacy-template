#pragma once
#include "vex.h"

using namespace vex;

/**
 * Drive class for controlling a VEX robot's chassis.
 * Supports tank drive, arcade drive, and reverse arcade drive.
 */
class Drive {
  private:
    // Drive components
    motor_group DriveL;  // Left side motors
    motor_group DriveR;  // Right side motors
    inertial* Gyro;     // Optional gyro sensor
    
    // Drive settings
    double wheel_diameter;  // Wheel diameter in inches
    double drive_ratio;    // External gear ratio (if any)

  public:
    /**
     * Create a new drive system
     * @param DriveL The left side motors
     * @param DriveR The right side motors
     * @param wheel_diameter The wheel diameter in inches
     * @param drive_ratio The external gear ratio (if any)
     */
    Drive(motor_group DriveL, motor_group DriveR, 
          double wheel_diameter = 4.0, double drive_ratio = 1.0);

    /**
     * Add a gyro to enable more advanced features
     * @param port The port number of the inertial sensor
     */
    void add_gyro(int port);

    /**
     * Reset the gyro heading to 0 degrees
     */
    void reset_heading();

    /**
     * Get the current heading from the gyro
     * @return Current heading in degrees (0-360)
     */
    double get_heading();

    /**
     * Set the brake mode for all drive motors
     * @param mode The brake mode (coast, brake, or hold)
     */
    void set_brake_mode(brakeType mode);

    /**
     * Drive the robot using arcade control (one stick)
     * @param throttle Forward/backward speed (-100 to 100)
     * @param turn Turn speed (-100 to 100)
     */
    void arcade_drive(int throttle, int turn);

    /**
     * Drive the robot using tank control (two sticks)
     * @param left_speed Left side speed (-100 to 100)
     * @param right_speed Right side speed (-100 to 100)
     */
    void tank_drive(int left_speed, int right_speed);

    /**
     * Drive forward/backward a specific distance
     * @param inches Distance to drive (positive = forward, negative = backward)
     */
    void drive_distance(double inches);

    /**
     * Turn to a specific angle
     * @param degrees Angle to turn to (positive = right, negative = left)
     */
    void turn_to_angle(double degrees);

    /**
     * Control the drive using arcade control from the controller
     * Uses Channel 3 for throttle and Channel 1 for turning
     */
    void control_arcade();

    /**
     * Control the drive using arcade control from the controller with reversed turning
     * Uses Channel 3 for throttle and Channel 1 for turning (reversed)
     */
    void control_arcade_reverse();

    /**
     * Control the drive using tank control from the controller
     * Uses Channel 3 for left side and Channel 2 for right side
     */
    void control_tank();
};
