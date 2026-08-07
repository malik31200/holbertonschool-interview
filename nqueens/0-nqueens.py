#!/usr/bin/python3
"""Solve the N queens problem."""

import sys


def solve_n_queens(size):
    """Print every solution for the N queens puzzle."""
    board = []
    columns = set()
    diag_left = set()
    diag_right = set()

    def backtrack(row):
        """Place queens row by row."""
        if row == size:
            print(board)
            return

        for col in range(size):
            if (col in columns or (row - col) in diag_left or
                    (row + col) in diag_right):
                continue

            board.append([row, col])
            columns.add(col)
            diag_left.add(row - col)
            diag_right.add(row + col)

            backtrack(row + 1)

            board.pop()
            columns.remove(col)
            diag_left.remove(row - col)
            diag_right.remove(row + col)

    backtrack(0)


def main():
    """Validate arguments and run the solver."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_n_queens(n)


if __name__ == "__main__":
    main()
