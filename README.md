# Sudoku Solver (Backtracking) – C++

A C++ implementation of a 9×9 Sudoku solver using recursion and backtracking.
The program includes a console-based visualization that displays each placement
and backtracking step during the solving process.

---

## Features

- Solves standard 9×9 Sudoku puzzles
- Uses recursion and backtracking
- Console visualization of the solving process
- Accepts input using `.` for empty cells
- Detects unsolvable puzzles

---

## Input Format

Provide the Sudoku grid as 9 lines of input.
Each line must contain 9 characters:

- `1–9` for filled cells  
- `.` for empty cells  

Example:
53..7....
6..195...
.98....6.
8...6...3
4..8.3..1
7...2...6
.6....28.
...419..5
....8..79

how to run:
compile the program: g++ sudoku.cpp -o sudoku
run the executable:  ./sudoku.exe 
