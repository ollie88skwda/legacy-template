# Legacy Template for VEX Robotics

A beginner-friendly template for VEX robotics programming, designed to help new teams get started with intermediate to advanced code concepts.

## 🎯 Purpose

This template is specifically designed to:
- Teach VEX robotics programming (not general C++)
- Provide a step-by-step learning path
- Include detailed explanations for each concept
- Serve as a foundation for competition-ready code

## 📚 Current Implementation

Here's what's currently implemented in the code:

### 1. Basic Robot Configuration (`robot-config.cpp`, `robot-config.h`)
- Motor setup and configuration
- Controller setup
- Inertial sensor setup
- Basic initialization functions

### 2. Drive System (`Legacy-Template/drive.cpp`, `drive.h`)
- Tank drive implementation
- Arcade drive implementation
- Basic movement functions:
  - Drive by voltage
  - Turn by degrees
  - Drive distance
  - Get heading

### 3. Autonomous Framework (`main.cpp`, `Legacy-Template/constants.h`)
- Autonomous routine selection
- Basic autonomous functions
- Constants system for autonomous values

### 4. User Control (`main.cpp`)
- Tank drive control
- Real-time status display
- Controller input handling

## 🎓 Learning Modules

The `docs/` folder contains detailed tutorials that match our implementation:

### 1. Getting Started
- Understanding the VEX V5 system
- Project structure explanation
- Basic robot configuration
- Your first program

### 2. Basic Control
- Understanding motor groups
- Tank vs arcade drive
- Controller input basics
- Basic movement commands

### 3. Drive Systems
- Creating a drive class
- Movement functions
- Sensor integration
- Basic autonomous movements

### 4. Autonomous Programming
- Creating autonomous routines
- Using the constants system
- Basic autonomous functions
- Autonomous selection system

### 5. Advanced Features (Coming Soon)
- PID control
- Odometry
- Advanced autonomous
- Path following

## 📁 Project Structure

```
Legacy-Template/
├── docs/                    # Educational documentation
│   ├── 01_getting_started/
│   ├── 02_basic_control/
│   ├── 03_drive_systems/
│   ├── 04_autonomous/
│   └── 05_advanced_features/
├── include/                 # Header files
│   ├── robot-config.h      # Robot configuration
│   └── Legacy-Template/    # Core functionality
│       ├── drive.h         # Drive system
│       └── constants.h     # Autonomous constants
├── src/                    # Implementation files
│   ├── main.cpp           # Main program
│   ├── robot-config.cpp   # Robot configuration
│   └── Legacy-Template/   # Core implementations
│       ├── drive.cpp      # Drive system
│       └── constants.cpp  # Constants implementation
└── README.md              # This file
```

## 🚀 Getting Started

1. **Install Required Software**
   - Download and install [VEXcode Pro V5](https://www.vexrobotics.com/vexcode-download)
   - Clone this repository or download as ZIP

2. **Open the Project**
   - Open VEXcode Pro V5
   - File -> Open -> Navigate to the downloaded folder
   - Select the project file

3. **Configure Your Robot**
   - Open `src/robot-config.cpp`
   - Update motor ports and configurations:
     ```cpp
     // Left drive motors
     motor leftFront(PORT1, ratio18_1, false);  // Port 1, 18:1 gear ratio
     motor leftBack(PORT2, ratio18_1, false);   // Port 2, 18:1 gear ratio
     
     // Right drive motors
     motor rightFront(PORT3, ratio18_1, true);  // Port 3, 18:1 gear ratio
     motor rightBack(PORT4, ratio18_1, true);   // Port 4, 18:1 gear ratio
     
     // Sensors
     inertial InertialSensor(PORT5);           // Port 5
     ```
   - Save and download to your robot

## 🛠️ Current Features

- **Drive System**
  - Tank and arcade drive modes
  - Basic autonomous movements
  - Inertial sensor integration
  - Voltage-based motor control

- **Autonomous**
  - Multiple routine selection
  - Basic movement commands
  - Constants system for configuration
  - Screen-based routine selector

- **User Control**
  - Tank drive implementation
  - Real-time status display
  - Smooth motor control
  - Controller deadband handling

## 📖 Documentation

Each module in the `docs/` folder contains:
- Detailed explanations of concepts
- Step-by-step tutorials
- Code examples
- Best practices
- Common issues and solutions

Start with `docs/01_getting_started/` and work your way through each module in order.

## 🤝 Contributing

Found a bug or want to add a feature? We welcome contributions:
1. Fork the repository
2. Create a new branch
3. Make your changes
4. Submit a pull request

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.

## ❓ Need Help?

- Check the documentation in the `docs/` folder
- Review the comments in the code
- Join the [VEX Forum](https://www.vexforum.com/)
- Ask your mentors or teammates

---
Made with ❤️ by VEX teams, for VEX teams