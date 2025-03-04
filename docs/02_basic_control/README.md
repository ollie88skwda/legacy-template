# Basic Robot Control

Now that you understand how to set up your robot, let's learn how to make it move! This guide will teach you the basics of controlling your robot's motors.

## What You'll Learn
1. How motors work in VEX V5
2. Different ways to control motors
3. How to read controller input
4. Basic movement commands

## Understanding VEX V5 Motors

### Motor Basics
- Motors spin from -100% to +100% power
- Positive = forward/clockwise
- Negative = backward/counterclockwise
- 0 = stopped

### Motor Types (Gear Ratios)
1. Red Cartridge (36:1)
   - Most torque (strength)
   - Slowest speed
   - Good for: Lifts, heavy mechanisms
   
2. Green Cartridge (18:1)
   - Balanced torque and speed
   - Good for: Drive motors
   
3. Blue Cartridge (6:1)
   - Fastest speed
   - Least torque
   - Good for: Flywheels, light mechanisms

## Controlling Your Robot

### 1. Tank Drive
Each joystick controls one side of the robot:
- Left joystick → Left motors
- Right joystick → Right motors

```cpp
void usercontrol(void) {
  while(1) {
    // Get joystick positions (-100 to +100)
    double left = Controller1.Axis3.position();
    double right = Controller1.Axis2.position();
    
    // Set motor speeds
    chassis.set_tank(left, right);
    
    task::sleep(20);  // Small delay
  }
}
```

### 2. Arcade Drive
One joystick controls both forward/backward and turning:
- Up/Down = Forward/Backward
- Left/Right = Turn

```cpp
void usercontrol(void) {
  while(1) {
    // Get joystick positions
    double forward = Controller1.Axis3.position();  // Up/down
    double turn = Controller1.Axis1.position();     // Left/right
    
    // Set motor speeds
    chassis.set_arcade(forward, turn);
    
    task::sleep(20);
  }
}
```

## Basic Movement Commands

### 1. Simple Motor Control
```cpp
// Set a specific motor speed
leftFront.spin(forward, 50, percent);  // Spin at 50% speed forward
rightFront.spin(reverse, 75, percent); // Spin at 75% speed backward

// Stop a motor
leftFront.stop();  // Motor will coast to a stop
leftFront.stop(hold);  // Motor will actively hold position
```

### 2. Drive Commands
```cpp
// Drive forward/backward
chassis.drive_distance(24);     // Drive forward 24 inches
chassis.drive_distance(-12);    // Drive backward 12 inches

// Turn
chassis.turn_degrees(90);       // Turn right 90 degrees
chassis.turn_degrees(-90);      // Turn left 90 degrees

// Drive for a specific time
chassis.drive(forward, 50, percent);  // Drive forward at 50% speed
wait(2, seconds);                     // Wait for 2 seconds
chassis.stop();                       // Stop driving
```

## Using the Controller

### Controller Buttons
```cpp
// Check if a button is being pressed
if(Controller1.ButtonA.pressing()) {
  // Do something while A is pressed
}

// Check if a button was just pressed
if(Controller1.ButtonB.pressing() && !lastBPressed) {
  // Do something once when B is first pressed
}
lastBPressed = Controller1.ButtonB.pressing();
```

### Controller Layout
- Joysticks: Axis1 through Axis4
- Buttons: A, B, X, Y
- Bumpers: L1, L2, R1, R2
- Arrows: Up, Down, Left, Right

## Practice Exercises

1. **Basic Movement**
   - Make the robot drive forward for 2 seconds
   - Make it turn 90 degrees right
   - Drive backward for 1 second
   - Turn 90 degrees left

2. **Button Controls**
   - Make button A drive forward
   - Make button B drive backward
   - Make button X turn right
   - Make button Y turn left

3. **Combined Controls**
   - Use tank drive normally
   - When L1 is held, switch to arcade drive
   - When R1 is held, drive at half speed

## Common Issues and Solutions

### Robot Not Moving Straight?
1. Check if all motors are spinning at the same speed
2. Verify motor reversals are correct
3. Make sure wheels are the same size

### Jerky Movement?
1. Add a small deadzone to ignore tiny joystick movements
2. Use smoother acceleration
3. Check for loose wheels or motors

### Delayed Response?
1. Reduce the sleep time (but not below 10ms)
2. Check for complex calculations in your loop
3. Make sure your battery is charged

Remember: Practice makes perfect! Try different combinations of controls to find what works best for your robot and driving style.
