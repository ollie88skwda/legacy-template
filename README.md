# Legacy Template for VEX Robotics

A beginner-friendly template designed to teach VEX robotics programming step by step. This template focuses on practical implementation rather than C++ theory, making it perfect for new robotics programmers.

## Getting Started

1. Create a new VEXcode Pro V5 project
2. Copy these template files into your project
3. Open the files in numerical order (01 → 05)
4. Follow the comments and examples in each file

## Learning Path

This template is organized into numbered sections, each building on the previous:

### 1️⃣ Basics (01_basics/)
- Learn how to configure motors
- Basic movement commands (tank drive, arcade drive)
- First steps in robot control

### 2️⃣ Movement (02_movement/)
- Simple forward/backward movement
- Basic turning
- Using motor encoders for precise distance
- Perfect for first-time programmers

### 3️⃣ PID Control (03_pid/)
- Introduction to PID control
- Step-by-step PID implementation
- Detailed tuning guide
- Make your robot move smoothly and accurately

### 4️⃣ Advanced Movement (04_advanced/)
- Combine PID with movement commands
- Drive to specific coordinates
- Complex movement patterns
- Professional-level robot control

### 5️⃣ Autonomous (05_autonomous/)
- Create autonomous routines
- Example programs from basic to advanced
- Competition-ready templates
- Skills challenge examples

## Quick Start Guide

1. **First Program**: Start with `01_basics/motors.cpp`
   ```cpp
   // Example: Basic tank drive
   Basics::tankDrive(50, 50);  // Drive forward at 50% power
   ```

2. **Simple Movement**: Try `02_movement/basic_movement.cpp`
   ```cpp
   // Example: Drive forward 12 inches
   Movement::driveDistance(12, 50);
   ```

3. **PID Movement**: Move to `04_advanced/pid_movement.cpp`
   ```cpp
   // Example: Drive to a point
   AdvancedMovement::driveToPoint(24, 24);  // Drive to (24,24)
   ```

## Common Questions

### "Where do I start?"
Start with `01_basics/motors.cpp`. Read through the comments and try the basic movement commands.

### "What's PID and why do I need it?"
PID makes your robot move smoothly and accurately. Start with the basic movement functions, then move to PID when you're ready for more precise control.

### "How do I tune PID?"
Check `03_pid/tuning.h` for a complete guide on PID tuning. It includes:
- Step-by-step tuning process
- Common problems and solutions
- Recommended starting values

### "How do I create an autonomous routine?"
Look at the examples in `05_autonomous/auto_routines.cpp`. Start with `simpleAuto()` and work your way up to more complex routines.

## Tips for Success

1. **Read the Comments**: Each file has detailed comments explaining how things work
2. **Start Simple**: Master basic movements before moving to PID
3. **Test Often**: Try each new function as you learn it
4. **Tune Carefully**: Small changes in PID values can make big differences

## Need Help?

1. Read the comments in each file
2. Try the example code
3. Test with small movements first
4. Ask your mentors for help with PID tuning

Remember: Good robot code starts with understanding the basics. Take your time with each section before moving to the next!
#   l e g a c y - t e m p l a t e  
 