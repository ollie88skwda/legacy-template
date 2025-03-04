# Understanding Drive Systems

Now that you know how to control your robot's motors, let's dive deeper into different drive systems and how they work. This knowledge will help you build more effective robots!

## What You'll Learn
1. Different types of drive systems
2. How to calculate wheel measurements
3. Understanding gear ratios
4. Advanced movement techniques

## Types of Drive Systems

### 1. Tank Drive (Most Common)
- Uses two sets of wheels (left and right)
- Simple and reliable
- Good for:
  - Most competition tasks
  - Pushing and defense
  - Simple programming

```cpp
// Tank drive configuration
Drive chassis(
  ZERO_TRACKER_NO_ODOM,  // Basic drive mode
  
  // Left motors
  motor_group(leftFront, leftBack),
  
  // Right motors
  motor_group(rightFront, rightBack),
  
  PORT1,      // Inertial sensor port
  3.25,       // Wheel diameter
  1.0,        // External gear ratio
  360         // Gyro scale
);
```

### 2. X-Drive (Holonomic)
- Uses four wheels at 45° angles
- Can move in any direction
- Good for:
  - Quick direction changes
  - Strafing (sideways movement)
  - Complex maneuvers

```cpp
// X-drive configuration
Drive chassis(
  HOLONOMIC_TWO_ENCODER,  // Holonomic drive mode
  
  // Motors in this order: LF, RF, LB, RB
  motor_group(leftFront),
  motor_group(rightFront),
  motor_group(leftBack),
  motor_group(rightBack),
  
  PORT1,      // Inertial sensor port
  3.25,       // Wheel diameter
  1.0,        // External gear ratio
  360         // Gyro scale
);
```

### 3. H-Drive
- Uses standard wheels plus a center omni wheel
- Can strafe left/right
- Good for:
  - Controlled sideways movement
  - Combining tank and strafe

## Understanding Wheel Measurements

### Wheel Types
1. **Standard Wheels**
   - Good traction
   - Can't slide sideways
   - Best for tank drive
   - Actual diameter = Listed diameter

2. **Omni Wheels**
   - Can slide sideways
   - Less traction than standard
   - Good for X-drive
   - Actual diameter ≈ Listed diameter + 0.125"

3. **Mecanum Wheels**
   - Rollers at 45° angles
   - Can create sideways movement
   - Complex to program
   - Measure carefully!

### Measuring for Your Code
```cpp
// Example wheel measurements
3.25,  // Standard 3.25" wheel
4.125, // 4" omni wheel (actually 4.125")
2.75   // 2.75" tracking wheel
```

## Understanding Gear Ratios

### What is a Gear Ratio?
- Relationship between motor rotation and wheel rotation
- Written as input:output or decimal
- Example: 36:60 = 0.6 (motor turns 0.6 times for each wheel turn)

### Common Ratios
1. **1:1 (1.0)**
   - Motor connects directly to wheel
   - Simple but not always ideal
   
2. **2:3 (0.667)**
   - Motor spins less than wheel
   - More speed, less torque
   
3. **3:2 (1.5)**
   - Motor spins more than wheel
   - More torque, less speed

### Calculating Your Ratio
```
Gear Ratio = (Motor Gear Teeth) / (Wheel Gear Teeth)

Example:
- Motor gear: 12 teeth
- Wheel gear: 36 teeth
- Ratio = 12/36 = 0.333
```

## Advanced Movement Techniques

### 1. Smooth Acceleration
Instead of moving instantly to full speed, gradually increase power:

```cpp
void smooth_drive(double target_speed) {
  double current_speed = 0;
  while(current_speed < target_speed) {
    current_speed += 5;  // Increase by 5% each time
    chassis.set_tank(current_speed, current_speed);
    task::sleep(20);
  }
}
```

### 2. Turn Correction
Use the inertial sensor to maintain straight lines:

```cpp
void straight_drive(double distance) {
  double start_heading = chassis.get_heading();
  
  while(!chassis.is_at_distance(distance)) {
    double current_heading = chassis.get_heading();
    double correction = (start_heading - current_heading) * 2.0;
    
    chassis.set_tank(50 + correction, 50 - correction);
    task::sleep(20);
  }
}
```

### 3. Point Turns vs. Swing Turns
- **Point Turn**: Both sides move opposite directions
- **Swing Turn**: One side moves while other stays still

```cpp
// Point turn (turn in place)
chassis.set_tank(50, -50);

// Swing turn (pivot on one side)
chassis.set_tank(50, 0);  // Right swing turn
chassis.set_tank(0, 50);  // Left swing turn
```

## Practice Exercises

1. **Wheel Measurements**
   - Measure all wheels on your robot
   - Calculate the actual diameter for omni wheels
   - Update your chassis configuration

2. **Gear Ratios**
   - Count teeth on all gears in your drive
   - Calculate the final gear ratio
   - Test if the robot moves as expected

3. **Movement Patterns**
   - Drive in a square using point turns
   - Drive in a square using swing turns
   - Compare the time and accuracy of each

## Common Issues and Solutions

### Robot Curves While Driving Straight?
1. Check wheel sizes are identical
2. Verify gear ratios are the same on both sides
3. Use turn correction with the inertial sensor

### Inconsistent Turning?
1. Calibrate your inertial sensor
2. Use slower turns for more accuracy
3. Account for momentum in your turns

### Wheels Slipping?
1. Check if wheels are worn
2. Reduce acceleration
3. Consider different wheel types

Remember: Every robot is unique! Experiment with different settings and techniques to find what works best for your specific robot design.
