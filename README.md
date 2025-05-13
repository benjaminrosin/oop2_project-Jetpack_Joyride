# Jetpack Joyride Clone

A C++ implementation of the popular game Jetpack Joyride using SFML graphics library.

## Description

This project is a clone of the classic Jetpack Joyride game where players control a character with a jetpack, avoiding obstacles, collecting coins, and trying to achieve the highest score possible. The game features various power-ups, obstacles, and enemies that make the gameplay challenging and entertaining.

## Features

- Player character with jetpack mechanics
- Multiple game objects and obstacles:
  - Scientists
  - Missiles with warning system
  - Laser beams
  - Coins
  - Power-ups (Speed, Power, Money)
- Score system with high score tracking
- Background music and sound effects
- Smooth animations
- Menu system with:
  - New Game
  - High Scores
  - Help screens
- Pause and mute functionality

## Prerequisites

- CMake (version 3.26 or higher)
- SFML 2.6.0
- C++ compiler with C++17 support
- Windows operating system

## Building the Project

1. Make sure you have SFML 2.6.0 installed at `C:/SFML/SFML-2.6.0`
2. Clone the repository
3. Create a build directory:
```bash
mkdir build
cd build
```
4. Configure and build the project:
```bash
cmake ..
cmake --build .
```

## Controls

- Use the spacebar/up arrow to control the jetpack
- ESC to pause the game
- Click the mute button to toggle sound
- Click the back button to return to the main menu

## Project Structure

- `src/` - Source files
- `include/` - Header files
- `resources/` - Game assets (images, fonts, sounds)
- `cmake/` - CMake configuration files

## Game Components

### Player
- Regular walking and jumping states
- Tank power-up state
- Collision detection with various objects

### Objects
- Static game objects (coins, power-ups)
- Moving game objects (missiles, scientists)
- Different collision behaviors for each object type

### States
- Player animation states
- Menu states
- Game states

## Authors

- Benjamin Rosin
- Yochai Benita

## Build Configurations

The project supports multiple build configurations:
- Debug (x64)
- Release (x64)
- Zip (for project submission)
- ZipBackup (with timestamp) 