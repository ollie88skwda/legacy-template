#include "Legacy/robot.h"

// Constants for movement calculations
const float WHEEL_DIAMETER = 4.0;  // inches
const float WHEEL_CIRCUMFERENCE = WHEEL_DIAMETER * 3.14159;
const float TRACK_WIDTH = 12.0;    // Distance between wheels in inches

Robot::Robot(int leftPort, int rightPort) : 
  leftMotor(vex::motor(leftPort)), 
  rightMotor(vex::motor(rightPort)) {
  
  // Initialize PID controllers with example values
  // You'll need to tune these for your specific robot!
  
  // Drive PID (for forward/backward movement)
  // Example values: P=0.5, I=0.001, D=0.1
  drivePID = new PID(0.5, 0.001, 0.1);
  
  // Turn PID (for rotation)
  // Example values: P=0.8, I=0.001, D=0.2
  turnPID = new PID(0.8, 0.001, 0.2);
  
  // Configure motors
  leftMotor.setBrake(vex::brakeType::brake);
  rightMotor.setBrake(vex::brakeType::brake);
  leftMotor.resetPosition();
  rightMotor.resetPosition();
}

float Robot::getAveragePosition() {
  // Convert motor rotation to inches of movement
  float leftPos = (leftMotor.position(vex::rotationUnits::deg) / 360.0) * WHEEL_CIRCUMFERENCE;
  float rightPos = (rightMotor.position(vex::rotationUnits::deg) / 360.0) * WHEEL_CIRCUMFERENCE;
  return (leftPos + rightPos) / 2.0;
}

float Robot::getRotation() {
  // Convert differential in wheel rotations to robot rotation
  float leftPos = leftMotor.position(vex::rotationUnits::deg);
  float rightPos = rightMotor.position(vex::rotationUnits::deg);
  
  // Calculate robot rotation in degrees
  return (rightPos - leftPos) * (WHEEL_DIAMETER / TRACK_WIDTH);
}

void Robot::driveDistance(float inches) {
  // Reset encoders and PID controller
  leftMotor.resetPosition();
  rightMotor.resetPosition();
  drivePID->reset();
  
  while (!drivePID->isSettled()) {
    // Calculate error (difference between target and current position)
    float currentPos = getAveragePosition();
    float error = inches - currentPos;
    
    // Get motor power from PID controller
    float power = drivePID->calculate(error);
    
    // Apply power to motors
    leftMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
    rightMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
    
    // Brief delay to prevent hogging CPU
    vex::task::sleep(10);
  }
  
  // Stop motors once settled
  stop();
}

void Robot::turnAngle(float degrees) {
  // Reset encoders and PID controller
  leftMotor.resetPosition();
  rightMotor.resetPosition();
  turnPID->reset();
  
  while (!turnPID->isSettled()) {
    // Calculate error (difference between target and current angle)
    float currentAngle = getRotation();
    float error = degrees - currentAngle;
    
    // Get motor power from PID controller
    float power = turnPID->calculate(error);
    
    // Apply opposite powers to create rotation
    leftMotor.spin(vex::directionType::fwd, -power, vex::velocityUnits::pct);
    rightMotor.spin(vex::directionType::fwd, power, vex::velocityUnits::pct);
    
    // Brief delay to prevent hogging CPU
    vex::task::sleep(10);
  }
  
  // Stop motors once settled
  stop();
}

void Robot::stop() {
  leftMotor.stop();
  rightMotor.stop();
}
