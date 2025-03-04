# Legacy Template for VEX Robotics

A beginner-friendly template for VEX robotics programming, designed to help new teams get started with intermediate to advanced code concepts.

## 🎯 Purpose

This template is specifically designed to:
- Teach VEX robotics programming (not general C++)
- Provide a step-by-step learning path
- Include detailed explanations for each concept
- Serve as a foundation for competition-ready code

## 📚 Learning Path

### 1. Getting Started
- Basic robot setup and configuration
- Understanding the program structure
- Running your first program

### 2. Basic Control
- Tank drive implementation
- Arcade drive implementation
- Using the VEX controller
- Basic motor control

### 3. Drive Systems
- Different drive types
- Wheel measurements
- Motor groups
- Basic movement functions

### 4. Autonomous Programming
- Creating autonomous routines
- Distance-based movement
- Turn functions
- Sensor integration

### 5. Advanced Features
- Advanced autonomous functions
- PID control
- Odometry
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
│       └── drive.cpp      # Drive system
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
   - Update motor ports and configurations
   - Save and download to your robot

## 📖 Documentation

Each module in the `docs/` folder contains:
- Detailed explanations of concepts
- Step-by-step tutorials
- Code examples
- Best practices
- Common issues and solutions

Start with `docs/01_getting_started/` and work your way through each module in order.

## 🛠️ Features

- **Modular Design**: Easy to understand and modify
- **Educational Comments**: Learn as you code
- **Flexible Setup**: Supports different drive configurations
- **Competition Ready**: Built for VEX robotics competitions
- **Expandable**: Add your own features as you learn

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