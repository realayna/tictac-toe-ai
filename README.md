# Tic-Tac-Toe AI

  

This is a simple implementation of the classic Tic-Tac-Toe game with an AI opponent. You can play against the AI, and it uses the minimax algorithm to make intelligent moves.

  

## Table of Contents

-  [Getting Started](#getting-started)

-  [How to Play](#how-to-play)

-  [AI Implementation](#ai-implementation)

-  [Project Structure](#project-structure)

-  [Contributing](#contributing)

-  [License](#license)

  

## Getting Started

  

### Prerequisites

  

Before you begin, ensure you have met the following requirements:

  

- C++ Compiler

- CMake (for building)

  

### Building the Project

  

To build the project, follow these steps:

  

1. Clone the repository to your local machine:

  

```shell
git clone <rhttps://github.com/realayna/tictac-toe-ai>
```
  
  

2. Navigate to the project directory:

```shell
cd tic-tac-toe-ai
```
  

3. Create a build directory and navigate to it:

```shell
mkdir build
cd build
```
  

4. Generate build files with CMake:

```shell
cmake ..
  ```

5. Build the project:

```shell
make
```
### Running the Game

After building the project, you can run the Tic-Tac-Toe game:

```shell
./tic-tac-toe-ai
```
## How to Play

-   The game is played on a 3x3 board.
-   You (PLAYER_O) play against the AI (PLAYER_X).
-   Enter your moves by specifying the row and column (1-based) where you want to place your mark.
-   The AI will take its turn immediately after you make your move.
-   The game ends when there's a winner or a draw.

## AI Implementation

The AI opponent in this game is implemented using the minimax algorithm. It explores all possible moves to find the best one for the AI and make the game challenging for the player.

## Project Structure

-   `main.cpp`: Contains the main game loop and user interaction.
-   `tictactoe.h`: Header file defining constants, data structures, and function prototypes.
-   `tictactoe.cpp`: Implementation of game logic and AI using minimax.
-   `CMakeLists.txt`: CMake configuration file for building the project.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

1.  Fork the repository.
2.  Create a new branch for your feature or bug fix.
3.  Make your changes and commit them with descriptive messages.
4.  Push your branch to your fork.
5.  Open a pull request to the main repository's `main` branch.




