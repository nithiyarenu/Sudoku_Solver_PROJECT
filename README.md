OVERVIEW:

This project is a Sudoku Solver Web Application that allows users to generate and solve Sudoku puzzles directly in their web browser. The application features an interactive and user-friendly interface, providing a visually distinct Sudoku grid. Users can easily generate puzzles of varying difficulty and solve them with the click of a button.

FEATURES:

Generate Sudoku Puzzle: Users can generate a Sudoku puzzle of different difficulty levels (easy, medium, hard, or random) using the Get Puzzle button.

Solve Sudoku Puzzle: The application can solve the generated puzzle using a backtracking algorithm, which fills in the correct numbers in the grid when the Solve Puzzle button is clicked.

Interactive Grid: The Sudoku grid is styled with different colors to differentiate sections, making it easier to visualize and solve puzzles.

Responsive Design: The application is designed to work seamlessly on various screen sizes.

SUGOKU API:

This project uses the Sugoku API to fetch Sudoku puzzles. The API provides an easy-to-use endpoint that returns a Sudoku board of varying difficulty levels.

API Endpoint
URL: https://sugoku.onrender.com/board?difficulty={level}

Parameters:
difficulty: This parameter specifies the difficulty level of the Sudoku puzzle. It accepts the following values:

easy
medium
hard
random

Response: The API returns a JSON object with a 9x9 Sudoku board.

USAGE OF DSA:

1. Backtracking Algorithm
Concept: Used to solve the Sudoku puzzle by trying numbers sequentially in each cell and backtracking if a number violates Sudoku rules.
Implementation: The sudokusolver() function recursively fills the grid, checking validity with isvalid() and backtracking as needed.

2. 2D Arrays
Concept: Represents the Sudoku grid as a 9x9 matrix.
Implementation: The board variable holds the puzzle data, with each cell corresponding to a grid position.

3. Constraint Satisfaction
Concept: Ensures no repetition of numbers in rows, columns, or 3x3 sub-grids.
Implementation: The isvalid() function checks these constraints before placing a number.

4. Recursion
Concept: Used in the backtracking process to explore possible solutions.
Implementation: The sudokusolver() function recursively moves through the grid, solving the puzzle step by step.
