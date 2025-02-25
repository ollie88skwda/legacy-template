#include "Legacy/01_basics/drive.h"
#include "vex.h"
#include "robot-config.h"

using namespace vex;

Drive::Drive(motor_group DriveL, motor_group DriveR, 
             double wheel_diameter, double drive_ratio)
  : DriveL(DriveL),
    DriveR(DriveR),
    Gyro(nullptr),
    wheel_diameter(wheel_diameter),
    drive_ratio(drive_ratio) {
}

void Drive::add_gyro(int port) {
  // Create a new inertial sensor on the specified port
  Gyro = new inertial(port);
  
  // Calibrate the gyro (this takes about 2 seconds)
  Gyro->calibrate();
  while(Gyro->isCalibrating()) {
    wait(20, msec);  // Wait for calibration to finish
  }
}

void Drive::reset_heading() {
  if (Gyro != nullptr) {
    Gyro->resetRotation();
  }
}

double Drive::get_heading() {
  if (Gyro != nullptr) {
    return Gyro->rotation();
  }
  return 0.0;  // Return 0 if no gyro is attached
}

void Drive::set_brake_mode(brakeType mode) {
  DriveL.setStopping(mode);
  DriveR.setStopping(mode);
}

void Drive::arcade_drive(int throttle, int turn) {
  // Calculate left and right motor speeds
  int left_speed = throttle + turn;
  int right_speed = throttle - turn;

  // Make sure speeds don't exceed 100%
  if (left_speed > 100) left_speed = 100;
  if (left_speed < -100) left_speed = -100;
  if (right_speed > 100) right_speed = 100;
  if (right_speed < -100) right_speed = -100;

  // Set motor speeds
  DriveL.spin(forward, left_speed, percent);
  DriveR.spin(forward, right_speed, percent);
}

void Drive::tank_drive(int left_speed, int right_speed) {
  // Make sure speeds don't exceed 100%
  if (left_speed > 100) left_speed = 100;
  if (left_speed < -100) left_speed = -100;
  if (right_speed > 100) right_speed = 100;
  if (right_speed < -100) right_speed = -100;

  // Set motor speeds
  DriveL.spin(forward, left_speed, percent);
  DriveR.spin(forward, right_speed, percent);
}

void Drive::drive_distance(double inches) {
  // Calculate degrees to rotate based on wheel size and gear ratio
  double degrees = (inches / (wheel_diameter * M_PI)) * 360.0 * drive_ratio;
  
  // Reset motor encoders
  DriveL.resetPosition();
  DriveR.resetPosition();
  
  // Set motor positions
  DriveL.spinTo(degrees, rotationUnits::deg, false); // Start spinning
  DriveR.spinTo(degrees, rotationUnits::deg, true);  // Wait for completion
}

void Drive::turn_to_angle(double degrees) {
  if (Gyro == nullptr) {
    // If no gyro, use basic turning
    double turn_circumference = 10.5 * M_PI; // Robot's turning diameter
    double inches = (degrees / 360.0) * turn_circumference;
    double motor_degrees = (inches / (wheel_diameter * M_PI)) * 360.0 * drive_ratio;
    
    DriveL.resetPosition();
    DriveR.resetPosition();
    
    DriveL.spinTo(motor_degrees, rotationUnits::deg, false);
    DriveR.spinTo(-motor_degrees, rotationUnits::deg, true);
  } else {
    // Use gyro for precise turning
    double start_angle = Gyro->rotation();
    double target_angle = start_angle + degrees;
    
    while (fabs(Gyro->rotation() - target_angle) > 2.0) {
      double error = target_angle - Gyro->rotation();
      double turn_power = error * 0.5;  // Simple P controller
      
      // Limit turn power
      if (turn_power > 50) turn_power = 50;
      if (turn_power < -50) turn_power = -50;
      
      // Apply turn power
      DriveL.spin(forward, turn_power, percent);
      DriveR.spin(forward, -turn_power, percent);
      wait(20, msec);
    }
    
    // Stop motors
    DriveL.stop();
    DriveR.stop();
  }
}

void Drive::control_arcade() {
  // Get controller values
  int throttle = Controller1.Axis3.position();  // Up/down on left stick
  int turn = Controller1.Axis1.position();      // Left/right on right stick
  
  // Add deadband to prevent drift
  if (abs(throttle) < 5) throttle = 0;
  if (abs(turn) < 5) turn = 0;
  
  // Drive using arcade control
  arcade_drive(throttle, turn);
}

void Drive::control_arcade_reverse() {
  // Get controller values
  int throttle = Controller1.Axis3.position();  // Up/down on left stick
  int turn = Controller1.Axis1.position();      // Left/right on right stick
  
  // Add deadband to prevent drift
  if (abs(throttle) < 5) throttle = 0;
  if (abs(turn) < 5) turn = 0;
  
  // Drive using arcade control with reversed turning
  arcade_drive(throttle, -turn);  // Note the negative turn value
}

void Drive::control_tank() {
  // Get controller values
  int left_speed = Controller1.Axis3.position();   // Up/down on left stick
  int right_speed = Controller1.Axis2.position();  // Up/down on right stick
  
  // Add deadband to prevent drift
  if (abs(left_speed) < 5) left_speed = 0;
  if (abs(right_speed) < 5) right_speed = 0;
  
  // Drive using tank control
  tank_drive(left_speed, right_speed);
}
