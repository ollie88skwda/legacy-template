# 04 - Autonomous Programming

Welcome to the autonomous programming module! This is where your robot starts to move on its own, making decisions and executing precise movements without driver input.

## 🎯 What You'll Learn

In this module, you'll learn how to:
1. Create autonomous routines
2. Use the constants system
3. Make precise movements
4. Select different routines during matches

## 📚 Key Concepts

### Constants System

The constants system (in `Legacy-Template/constants.h`) helps you:
- Store important values in one place
- Easily tune autonomous routines
- Share values between different functions

```cpp
// Example of using constants
void default_constants() {
    // These values can be adjusted to tune your autonomous
    const float DRIVE_SPEED = 80;      // Default drive speed (0-100%)
    const float TURN_SPEED = 50;       // Default turn speed (0-100%)
    const float RAMP_SPEED = 40;       // Speed for climbing ramps
}
```

### Autonomous Selection

We've implemented a simple autonomous selection system:
```cpp
// In main.cpp
while(!auto_started) {
    Brain.Screen.clearScreen();
    switch(current_auton_selection) {
        case 0:
            Brain.Screen.print("Autonomous: Drive Forward");
            break;
        case 1:
            Brain.Screen.print("Autonomous: Turn and Drive");
            break;
    }
    // ... selection code
}
```

This lets you:
- Create multiple autonomous routines
- Switch between them before matches
- Test different strategies

### Basic Movements

Your robot can now:
```cpp
// Drive a specific distance
chassis.drive_distance(24);  // Drive forward 24 inches

// Turn a specific amount
chassis.turn_degrees(90);    // Turn 90 degrees right

// Control drive voltage directly
chassis.drive_voltage(6, 6); // Drive forward at 6V
```

### Creating Routines

Here's how to create a new autonomous routine:
```cpp
void autonomous(void) {
    switch(current_auton_selection) {
        case 0:  // Basic drive forward
            chassis.drive_distance(24);
            break;
            
        case 1:  // Turn and drive
            chassis.drive_distance(24);
            chassis.turn_degrees(90);
            chassis.drive_distance(24);
            break;
    }
}
```

## 🛠️ Practice Exercises

1. **Basic Square Pattern**
   - Make your robot drive in a square
   - Use drive_distance() and turn_degrees()
   - Try different sizes of squares

2. **Figure Eight**
   - Create a figure-eight pattern
   - Use both left and right turns
   - Make it as smooth as possible

3. **Multiple Routines**
   - Add two more autonomous routines
   - Make them do different things
   - Practice switching between them

## 📝 Tips for Success

1. **Start Simple**
   - Begin with basic movements
   - Add complexity gradually
   - Test each part separately

2. **Use Constants**
   - Don't hardcode numbers
   - Make values easy to adjust
   - Comment what each value does

3. **Test Thoroughly**
   - Test on different field surfaces
   - Check battery levels affect performance
   - Make sure turns are consistent

4. **Add Comments**
   - Explain what each section does
   - Note important values
   - Document any special cases

## 🎮 Next Steps

Once you're comfortable with basic autonomous:
1. Try more complex movement patterns
2. Add sensor feedback for accuracy
3. Create competition-specific routines
4. Learn about PID control (in the next module)

## ❓ Common Issues

1. **Robot Doesn't Drive Straight**
   - Check wheel alignment
   - Verify motor connections
   - Consider using gyro feedback

2. **Turns Are Inconsistent**
   - Battery voltage affects performance
   - Surface friction matters
   - Gyro calibration is important

3. **Distance Is Off**
   - Measure wheel diameter carefully
   - Account for gear ratios
   - Consider wheel slippage

## 🤔 Need Help?

- Review the code comments
- Check the VEX Forum
- Ask your mentors
- Try debugging with print statements

Remember: Good autonomous routines come from lots of testing and fine-tuning. Don't get discouraged if it takes time to get things perfect!
