#include "vex.h"
#include "Legacy-Template/drive.h"

using namespace vex;
using namespace legacy;

Drive::Drive(
  drive_setup setup_type,
  vex::motor_group DriveL,
  vex::motor_group DriveR,
  vex::inertial Gyro
) : DriveL(DriveL), DriveR(DriveR), Gyro(Gyro), current_drive_setup(setup_type) {
  // Initialize sensors
  Gyro.calibrate();
  while(Gyro.isCalibrating()) {
    wait(20, msec);
  }
}

void Drive::set_tank(int left, int right) {
  DriveL.spin(forward, left, percent);
  DriveR.spin(forward, right, percent);
}

void Drive::set_arcade(int throttle, int turn) {
  int left = throttle + turn;
  int right = throttle - turn;
  
  // Ensure we don't exceed 100%
  if(left > 100) left = 100;
  if(left < -100) left = -100;
  if(right > 100) right = 100;
  if(right < -100) right = -100;
  
  set_tank(left, right);
}

void Drive::tank_drive(int left, int right) {
  set_tank(left, right);
}

void Drive::arcade_drive(int throttle, int turn) {
  set_arcade(throttle, turn);
}

void Drive::drive_distance(float distance, int max_speed) {
  // Reset motor encoders
  DriveL.resetPosition();
  DriveR.resetPosition();
  
  // Calculate encoder counts for distance
  // (distance / wheel circumference) * motor gear ratio * encoder counts per revolution
  float counts = (distance / (3.25 * 3.14159)) * 1.0 * 360.0;
  
  // Set target position
  DriveL.spinTo(counts, degrees, max_speed, velocityUnits::pct, false);
  DriveR.spinTo(counts, degrees, max_speed, velocityUnits::pct);
}

void Drive::turn_degrees(float degrees, int max_speed) {
  // Reset gyro
  Gyro.resetRotation();
  
  // Calculate turn direction
  int direction = (degrees > 0) ? 1 : -1;
  
  // Turn until we reach target
  while(fabs(Gyro.rotation()) < fabs(degrees)) {
    set_tank(direction * max_speed, -direction * max_speed);
    wait(20, msec);
  }
  
  // Stop
  drive_stop();
}

void Drive::drive_voltage(int left_voltage, int right_voltage) {
  DriveL.spin(forward, left_voltage, volt);
  DriveR.spin(forward, right_voltage, volt);
}

float Drive::get_heading() {
  return Gyro.heading();
}

float Drive::get_absolute_heading() {
  return Gyro.rotation();
}

void Drive::reset_heading() {
  Gyro.resetRotation();
}

void Drive::drive_stop(vex::brakeType mode) {
  DriveL.stop(mode);
  DriveR.stop(mode);
}
