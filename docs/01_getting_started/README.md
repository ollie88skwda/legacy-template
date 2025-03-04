# Getting Started with VEX Robotics Programming

Welcome to your first step in learning how to program VEX robots! This guide will help you understand the basics of setting up your development environment and writing your first program.

## What You'll Learn
1. How to set up your programming environment
2. Understanding the basic structure of a VEX program
3. How to configure your robot's motors and sensors

## Setting Up Your Environment

### Step 1: Install VEXcode Pro V5
1. Go to [VEX Robotics website](https://www.vexrobotics.com/vexcode-download)
2. Download VEXcode Pro V5 for your operating system
3. Install the software following the installation wizard

### Step 2: Connect Your Robot
1. Turn on your V5 brain
2. Connect your computer to the V5 brain using the USB cable
3. Wait for the computer to recognize the robot

## Understanding Program Structure

Every VEX program has three main parts:

### 1. Pre-Autonomous (pre_auton)
```cpp
void pre_auton(void) {
  // This runs when you turn on the robot
  // Good for:
  // - Setting up starting positions
  // - Calibrating sensors
  // - Choosing autonomous routines
}
```

### 2. Autonomous (autonomous)
```cpp
void autonomous(void) {
  // This runs during the 15-second autonomous period
  // The robot moves by itself without driver control
  // Example: Drive forward 24 inches
  chassis.drive_distance(24);
}
```

### 3. User Control (usercontrol)
```cpp
void usercontrol(void) {
  // This runs during driver control
  // The robot is controlled using the controller
  while(1) {
    // Get joystick values
    double left = Controller1.Axis3.position();
    double right = Controller1.Axis2.position();
    
    // Set motor speeds
    chassis.set_tank(left, right);
    
    // Small delay to prevent CPU overuse
    task::sleep(20);
  }
}
```

## Configuring Your Robot

### Step 1: Plan Your Robot's Configuration
Before writing any code, make a list of all the components on your robot:
1. How many drive motors? (Usually 2 or 4)
2. What other motors do you have? (Lift, intake, etc.)
3. What sensors are you using? (Inertial sensor, etc.)

### Step 2: Set Up Motors in `robot-config.h`
Open `robot-config.h` and look for the motor declarations:
```cpp
// Drive Motors
extern motor leftFront;    // Left front drive motor
extern motor leftBack;     // Left back drive motor
extern motor rightFront;   // Right front drive motor
extern motor rightBack;    // Right back drive motor
```

### Step 3: Configure Motors in `robot-config.cpp`
Open `robot-config.cpp` and set up each motor:
```cpp
// Left drive motors
motor leftFront(PORT1, ratio18_1, false);  // Port 1, 18:1 gear ratio, not reversed
motor leftBack(PORT2, ratio18_1, false);   // Port 2, 18:1 gear ratio, not reversed

// Right drive motors (notice they're reversed!)
motor rightFront(PORT3, ratio18_1, true);  // Port 3, 18:1 gear ratio, reversed
motor rightBack(PORT4, ratio18_1, true);   // Port 4, 18:1 gear ratio, reversed
```

### Important Terms to Know:
- **PORT**: The number on the V5 brain where you plug in the motor
- **ratio18_1**: The gear ratio of the motor (18:1 is standard for drive motors)
- **true/false**: Whether the motor direction is reversed

## Next Steps
1. Make sure you can compile and download a program to your robot
2. Try running the basic drive code in usercontrol
3. Watch the brain screen during pre_auton to see robot information
4. Move on to the next module to learn about basic robot control!

## Common Issues and Solutions

### Motor Not Working?
1. Check if it's plugged into the correct port
2. Verify the port number in the code matches
3. Try reversing the motor (change false to true or vice versa)

### Robot Driving Backwards?
1. Your motors might need to be reversed
2. Check if your joystick values are negative when they should be positive

### Code Won't Compile?
1. Make sure all motors are properly declared in `robot-config.h`
2. Verify all motors are configured in `robot-config.cpp`
3. Check for missing semicolons or brackets

Remember: Take your time to understand each concept before moving on. If something doesn't work, try to figure out why - this is how you learn!
