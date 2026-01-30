# 🐍 Classic Snake Game - C++ & SFML

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus)
![Library](https://img.shields.io/badge/Library-SFML%202.6.2-brightgreen?style=for-the-badge)
![Build](https://img.shields.io/badge/Build-GNU%20Make-orange?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

A modern, feature-rich implementation of the classic Snake game built with C++ and the SFML (Simple and Fast Multimedia Library). This project showcases object-oriented programming principles, game loop architecture, and real-time graphics rendering.

## 📑 Table of Contents

- [Demo](#-demo)
- [Features](#-features)
- [Technologies Used](#-technologies-used)
- [Prerequisites](#-prerequisites)
- [Setup & Installation](#-setup--installation)
- [How to Run in VS Code](#-how-to-run-in-vs-code)
- [Controls](#-controls)
- [Project Structure](#-project-structure)
- [File Descriptions](#-file-descriptions)
- [Gameplay Mechanics](#-gameplay-mechanics)
- [License](#-license)

## 🎥 Demo

https://github.com/user-attachments/assets/ab3b6264-8c60-49ad-b3f1-b05f74f8a972

## ✨ Features

- **Classic Snake Gameplay**: Navigate the snake to eat apples and grow longer
- **Score Tracking**: Real-time score display with persistent score tracking
- **Lives System**: Three lives with visual feedback on collisions
- **Collision Detection**: Self-collision and boundary collision mechanics
- **Smooth Graphics**: 60 FPS rendering with SFML
- **Message Log**: In-game textbox displaying game events and scores
- **Fullscreen Support**: Toggle fullscreen mode with F5
- **Customizable Difficulty**: Speed increases as the snake grows

## 🛠 Technologies Used

- **Language**: C++ (Modern C++ standards)
- **Graphics Library**: SFML 2.6.2 (Simple and Fast Multimedia Library)

## 📋 Prerequisites

Before you begin, ensure you have the following installed on your system:

### 1. **MinGW-w64 (GCC Compiler)**
   - Download and install MinGW-w64 from [MinGW-w64 Downloads](https://www.mingw-w64.org/downloads/)
   - Add the MinGW `bin` directory to your system PATH
   - Verify installation:
     ```bash
     g++ --version
     ```

### 2. **SFML Library (Version 2.6.2)**
   - Download SFML 2.6.2 for MinGW from [SFML Downloads](https://www.sfml-dev.org/download.php)
   - Extract to a location (e.g., `C:/librariesSFML/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/`)
   - **Important**: Update the `SFML_PATH` variable in the `Makefile` to match your SFML installation path

### 3. **GNU Make**
   - Install Make for Windows (usually comes with MinGW)
   - Verify installation:
     ```bash
     make --version
     ```

### 4. **Visual Studio Code** (Recommended IDE)
   - Download from [VS Code Official Site](https://code.visualstudio.com/)
   - Recommended Extensions:
     - C/C++ (Microsoft)
     - C/C++ Extension Pack
     - Makefile Tools

## 🔧 Setup & Installation

### Step 1: Clone the Repository

```bash
git clone https://github.com/amr10w/SnakeGame-SFML.git
cd SnakeGame-SFML
```

### Step 2: Configure SFML Path

Open the `Makefile` and update line 3 with your SFML installation path:

```makefile
SFML_PATH = C:/librariesSFML/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2
```

**Note**: Use forward slashes (`/`) in the path, even on Windows.

### Step 3: Verify Font File

Ensure the font file exists at:
```
src/arial.ttf
```
This font is used for the score display and textbox rendering.

### Step 4: Copy SFML DLLs

The following SFML DLL files should be in your project root directory (they're already included):
- `sfml-graphics-2.dll`
- `sfml-window-2.dll`
- `sfml-system-2.dll`
- `sfml-audio-2.dll`
- `openal32.dll`

## 🚀 How to Run in VS Code

### Method 1: Using the VS Code Terminal

1. **Open the project in VS Code**:
   ```bash
   code .
   ```

2. **Open the integrated terminal** (`Ctrl + ~` or `View > Terminal`)

3. **Build the project**:
   ```bash
   make
   ```
   This will compile all `.cpp` files and create `main.exe`

4. **Run the game**:
   ```bash
   ./main.exe
   ```

### Method 2: Using Build Tasks (Optional)

1. Create `.vscode/tasks.json` with build and run tasks
2. Press `Ctrl + Shift + B` to build
3. Use `Ctrl + Shift + P` → `Tasks: Run Task` → `Run Game`

## 🎮 Controls

| Key | Action |
|-----|--------|
| **W** | Move Up |
| **A** | Move Left |
| **S** | Move Down |
| **D** | Move Right |
| **F5** | Toggle Fullscreen |
| **Close Window** | Exit Game |

### Gameplay Rules:
- **Objective**: Guide the snake to eat red apples
- **Growth**: Each apple eaten increases the snake's length and score by 10 points
- **Lives**: You have 3 lives. Lose a life when the snake collides with itself
- **Game Over**: Occurs when you hit the boundary walls or run out of lives
- **Auto-Reset**: Game automatically resets after game over

## 📁 Project Structure

This is what you'll find after cloning the repository:

```
SnakeGame-SFML/
│
├── golden_varsity/          # Additional font resources
├── src/
│   └── arial.ttf           # Font file for text rendering
│
├── .gitignore              # Git ignore file
├── Game.cpp                # Game loop and orchestration implementation
├── Game.h                  # Game class header
├── LICENSE                 # MIT License
├── main.cpp                # Entry point of the application
├── README.md               # This file
├── Snake.cpp               # Snake entity implementation
├── Snake.h                 # Snake class header
├── Textbox.cpp             # Message display implementation
├── Textbox.h               # Textbox class header
├── Window.cpp              # Window management implementation
├── Window.h                # Window class header
├── World.cpp               # Game world implementation
└── World.h                 # World class header
```

**Note**: After building the project, the following files will be generated:
- `*.o` - Object files (Game.o, Snake.o, World.o, Window.o, Textbox.o, main.o)
- `main.exe` - Compiled executable
- `*.dll` - SFML runtime libraries (you'll need to copy these from your SFML installation)


## 📝 File Descriptions

### Core Game Files

#### `main.cpp`
**Purpose**: Application entry point  
**Functionality**: Creates an instance of the `Game` class and starts the game loop. This is a minimal file that delegates all game logic to the `Game` class.

---

#### `Game.h` / `Game.cpp`
**Purpose**: Central game orchestrator  
**Functionality**:
- Manages the main game loop (`run()` method)
- Coordinates all game subsystems (Window, World, Snake, Textbox)
- Handles input processing (WASD keyboard controls)
- Updates game state based on elapsed time
- Renders all game elements in the correct order
- Manages score display and game-over logic
- Uses time-based updates to maintain consistent gameplay speed

**Key Methods**:
- `HandleInput()`: Processes keyboard input and validates movement
- `Update()`: Updates game state using frame-independent timing
- `Render()`: Draws all game objects to the window
- `addText()`: Adds messages to the textbox on game events

---

#### `Snake.h` / `Snake.cpp`
**Purpose**: Snake entity and behavior implementation  
**Functionality**:
- Manages snake body as a vector of segments (`SnakeContainer`)
- Handles movement in four directions (Up, Down, Left, Right)
- Implements growth mechanism when eating apples
- Detects self-collision and cuts the snake accordingly
- Tracks lives, score, and game-over state
- Renders the snake with a yellow head and green body

**Key Features**:
- **Movement Validation**: Prevents 180-degree turns (e.g., can't go from Up to Down directly)
- **Physical Direction Tracking**: `GetPhysicalDirection()` determines actual movement direction
- **Self-Collision**: Checks if the head collides with the body (requires minimum 5 segments)
- **Segment System**: Each segment tracked as a position (`sf::Vector2i`)

**Key Methods**:
- `Tick()`: Updates snake position each game frame
- `Move()`: Shifts all body segments to follow the head
- `Extend()`: Adds a new segment when eating an apple
- `CheckCollision()`: Detects and handles self-collision
- `Cut(int segments)`: Removes segments and decreases lives

---

#### `World.h` / `World.cpp`
**Purpose**: Game environment and obstacle management  
**Functionality**:
- Defines the game world grid (based on block size of 16 pixels)
- Manages apple spawning and positioning
- Renders boundary walls (dark red rectangles)
- Detects collisions between snake and walls
- Triggers game-over when snake hits boundaries

**Key Features**:
- **Grid System**: Divides the window into a grid of blocks
- **Apple Respawn**: Randomly places apples within safe boundaries
- **Boundary Detection**: Monitors if snake exceeds grid limits
- **Visual Elements**: Draws red circular apples and boundary walls

**Key Methods**:
- `RespawnApple()`: Places apple at random grid position
- `Update(Snake& player)`: Checks for apple collection and boundary collision
- `Render()`: Draws boundaries and apple

---

#### `Window.h` / `Window.cpp`
**Purpose**: Window and rendering context management  
**Functionality**:
- Creates and manages the SFML render window
- Handles window events (close, key presses)
- Provides drawing surface for all game objects
- Supports fullscreen toggle (F5 key)
- Manages window lifecycle (creation, destruction)

**Key Features**:
- **Default Size**: 800x600 window
- **Event Polling**: Processes window events each frame
- **Fullscreen Mode**: Toggles between windowed and fullscreen
- **Clean Rendering**: `BeginDraw()` clears, `EndDraw()` displays

**Key Methods**:
- `Create()`: Instantiates the SFML window
- `Update()`: Polls events and handles window state
- `BeginDraw()` / `EndDraw()`: Frame rendering boundaries
- `ToggleFullscreen()`: Switches display mode

---

#### `Textbox.h` / `Textbox.cpp`
**Purpose**: In-game message and notification system  
**Functionality**:
- Displays game events in a scrolling textbox
- Shows game-over messages and scores
- Maintains a limited message history (maximum 6 messages)
- Renders with a semi-transparent backdrop

**Key Features**:
- **Message Queue**: Stores up to 6 recent messages
- **Auto-Scrolling**: Removes oldest message when limit exceeded
- **Styling**: White text on semi-transparent gray background
- **Font Access**: Provides font for other game elements (score display)

**Key Methods**:
- `Setup()`: Configures textbox position, size, and font
- `Add(string message)`: Appends a new message
- `Render()`: Draws visible messages to the window
- `Clear()`: Removes all messages

---

### Build System

#### `Makefile`
**Purpose**: Automated build configuration  
**Functionality**:
- Defines compiler flags and include paths
- Links SFML libraries (graphics, window, system, audio, opengl32)
- Provides multiple build targets:
  - `make` / `make all`: Builds with console window (for debugging)
  - `make gui`: Builds GUI-only version (no console)
  - `make clean`: Removes compiled files (`.o` and `.exe`)
  - `make compile`: Only compiles `.cpp` to `.o` files

**Configuration**:
- **SFML_PATH**: Must be updated to your SFML installation directory
- **INCLUDE**: Adds SFML header files to compiler search path
- **LIBS**: Links required SFML libraries
- **Wildcard Compilation**: Automatically finds all `.cpp` files in current and `coding/` directories

---

### Supporting Files

#### `src/arial.ttf`
**Purpose**: Font resource for text rendering  
**Usage**: Loaded by `Textbox` class for displaying messages and scores

#### `LICENSE`
**Purpose**: MIT License for open-source usage  
**Details**: Grants permission to use, modify, and distribute the code

## 🎯 Gameplay Mechanics

### Scoring System
- **+10 points** for each apple eaten
- Score displayed in real-time at the top-left corner
- Score resets to 0 on game over

### Lives System
- Lose a life when snake collides with itself
- Game over occurs at wall collision or snake collides with itself

### Speed Progression
- Base speed: 15 updates per second
- Speed can be adjusted in `Snake::Reset()` method

### Collision Rules
1. **Self-Collision**: Requires minimum 5 body segments before detection
2. **Wall Collision**: Instant game over
3. **Apple Collision**: Triggers growth and score increase


## 📄 License

This project is licensed under the **MIT License**.

See the [LICENSE](LICENSE) file for full details.

## Author

**Amr Wahidi**

- GitHub: [@amr10w](https://github.com/amr10w)
- Repository: [SnakeGame-SFML](https://github.com/amr10w/SnakeGame-SFML)

---

### 🎮 Enjoy the Game!

If you encounter any issues or have suggestions, please open an issue on GitHub. Contributions are welcome!

**Happy Coding!** 🐍✨
