# Tic-Tac-Toe Game

This is a simple implementation of the classic Tic-Tac-Toe game in C. It includes two versions:
- `tictactoe`: The original version.
- `tictactoe2`: An improved version with enhanced features.

## Features

- Play against another human player.
- Choose X or O for each player.
- View a leaderboard to track scores.
- Automatically record game results in a text file (`score.txt`).

## Requirements

- This game requires a C compiler (e.g., GCC) to compile the source code.

## Compilation

To compile the game, navigate to the directory containing the source files (`main.c`, `improved_main.c`, and any other necessary files) and the `Makefile`, then run the following command:

```console
make
```

This command will compile both versions of the game (tictactoe and tictactoe2) and generate executable files.

## Running the Game
Once compiled successfully, you can run each version of the game using the following commands:

```console
User@Github:~$ ./tictactoe
User@Github:~$ ./tictactoe2
```

Follow the on-screen instructions to play the game. Enjoy!

## Cleanup
To remove the compiled executable files and object files, you can run:

```console
make clean
```