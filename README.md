# Tic-Tac-Toe

Visualize este documento também em português: [README.pt-br.md](README.pt-br.md)

This repository hosts the source code of **Tic-Tac-Toe** developed as part of the **Programming Logic** course project taught by Prof. Marcos Quiles.

### Group Members

| Full Name               |
| :---                    |
| Mateus G. P. Campos     |

---

## Project Description

**Tic-Tac-Toe** is an interactive application developed in **C** to demonstrate the application of fundamental logic programming concepts: variables, control flow structures, matrices, and code modularization through functions.

## Main Features

*   **Player vs Player Mode**: Two players can play alternately
*   **Player vs Computer Mode**: The player faces the computer with basic AI
*   **Artificial Intelligence**: 
    - **Basic Level**: Computer chooses random position
    - **Intermediate Level** (Bonus): Computer detects and blocks threats
*   **Input Validation**: Error handling for invalid moves
*   **Terminal Interface**: Visual 3x3 board with real-time feedback

---

## Technologies and Tools

| Category               | Technology | Description                                                                              |
| :---                   | :---       | :---                                                                                   |
| **Language**           | C          | Programming language for implementing computational logic                              |
| **Compiler**           | GCC        | Standard compiler for C on Unix-like systems                                          |
| **Version Control**    | Git        | Distributed version control system for code management                                |

---

## Applied Concepts

As per project requirements, the code implements:

*   **Matrices**: Representation of the 3x3 board
*   **Loops**: Main game loop and board traversal
*   **Modularization**: Division into functions for printing, validation, and game logic
*   **Control Structures**: Conditionals for rules and victory conditions

---

## Installation and Execution

### Prerequisites

*   GCC or compatible C compiler
*   Git (optional, for cloning the repository)

### 1. Clone the Repository

```bash
git clone https://github.com/mgpcampos/tic-tac-toe.git
cd tic-tac-toe/
```

### 2. Compile the Code

```bash
gcc -o jogo main.c
```

### 3. Run the Game

```bash
./jogo
```

On Windows:
```bash
jogo.exe
```

---

## How to Play

1. At startup, choose the game mode:
   - **1**: Player vs Player
   - **2**: Player vs Computer

2. The board is numbered 0 to 8:
   ```
   0 | 1 | 2
   ---------
   3 | 4 | 5
   ---------
   6 | 7 | 8
   ```

3. Players alternate turns by entering the desired position number
4. The game ends in victory or draw

---

## Project Structure

```
tic-tac-toe/
├── main.c              # Main game source code
├── LICENSE             # Project license
├── README.md           # Documentation in English
├── README.pt-br.md     # Documentation in Portuguese
├── specs.md            # Project specifications
└── .gitignore          # Git file for ignoring compiled files
```