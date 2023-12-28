# The Legend of Zelda (NES) Recreation with CSFML
```diff
- WARNING! -

This repository is a work in progress
```

## Overview
Welcome to the recreation of the classic NES game, The Legend of Zelda, using CSFML! This project aims to bring the nostalgic experience to the desktop using the C language and the Simple and Fast Multimedia Library (CSFML). Dive into the world of Hyrule, embark on a quest to save Princess Zelda, and enjoy the classic gameplay with a modern touch.

## Features
- **Classic Gameplay:** Experience the game as it was meant to be played, with all the original levels, enemies, and puzzles.
- **Enhanced Graphics:** While keeping the classic look and feel, enjoy enhanced graphics powered by CSFML.
- **Custom Controls:** Configurable keyboard controls for a personalized gaming experience.

## Platform Compatibility

### Windows and Linux
This project is designed to be compatible with both Windows and Linux operating systems.

#### Windows:
- Ensure you have the latest version of CMake and a C compiler like MinGW or Visual Studio.
- CSFML and its dependencies should be installed and properly configured in your system path.
- Follow the standard CMake build process as outlined in the installation section. If you encounter any path issues, verify that all required libraries are correctly referenced.

#### Linux:
- Linux users will need the usual build-essential package, CMake, and the appropriate CSFML packages for their distribution.
- Most dependencies can be installed via your distribution's package manager.
- After installation, follow the CMake build instructions. Linux environments typically handle library paths well, but check that all CSFML paths are correct if you encounter issues.


## Getting Started
### Prerequisites
- GCC or any C compiler
- CSFML (Download and installation instructions [here](https://www.sfml-dev.org/download/csfml/))

### Installation
1. **Clone the repository:**
   ```
   git clone git@github.com:nathan-casabieille/myZelda.git
   ```
2. **Navigate to the project directory:**
   ```
   cd Zelda
   ```
3. **Create a build directory and navigate into it:**
   ```
   mkdir build && cd build
   ```
4. **Generate the Makefile with CMake:**
   ```
   cmake ..
   ```
5. **Compile the game:**
   ```
   make
   ```

# Usage
From the build directory, run the game executable:
  ```
  ./Zelda
  ```
Use the arrow keys to move Link around the world of Hyrule.
Press 'CTRL' to attack and 'E' to interact with the environment.

# Contact

Nathan Casabieille - nathan.casabieille1@gmail.com

Enjoy the world of Hyrule with a blend of nostalgia and modern tech!
