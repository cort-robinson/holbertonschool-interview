#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N chessboard. Write a
program that solves the N queens problem.

Usage: nqueens N
If the user called the program with the wrong number
of arguments, print Usage: nqueens N, followed by a
new line, and exit with the status 1 where N must be
an integer greater or equal to 4 If N is not an integer,
print N must be a number, followed by a new line, and
exit with the status 1 If N is smaller than 4, print N
must be at least 4, followed by a new line, and exit
with the status 1 The program should print every possible
solution to the problem one solution per line
You don’t have to print the solutions in a specific order
You are only allowed to import the sys module
"""
import sys


boardcnt = 0


def IsBoardOk(chessboard, row, col):
    # Check if there is a queen 'Q' positioned to the left of column col on the same row.
    for c in range(col):
        if (chessboard[row][c] == 'Q'):
            return False

    # Check if there is queen 'Q' positioned on the upper left diagonal
    for r, c in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if (chessboard[r][c] == 'Q'):
            return False

    # Check if there is queen 'Q' positioned on the lower left diagonal
    for r, c in zip(range(row+1, len(chessboard), 1), range(col-1, -1, -1)):
        if (chessboard[r][c] == 'Q'):
            return False

    return True


def DisplayBoard(chessboard):
    positions = []
    for row in range(len(chessboard)):
        for tile in range(len(chessboard[row])):
            if chessboard[row][tile] == 'Q':
                positions.append([row, tile])
    print(positions)


def PlaceNQueens(chessboard, col):
    # If all the columns have a queen 'Q', a solution has been found.
    global boardcnt
    if (col >= len(chessboard)):
        boardcnt += 1
        DisplayBoard(chessboard)
    else:
        # Else try placing the queen on each row of the column and check if the chessboard remains OK.
        for row in range(len(chessboard)):
            chessboard[row][col] = 'Q'
            if (IsBoardOk(chessboard, row, col) == True):
                # Chess board was OK, hence try placing the queen 'Q' in the next column.
                PlaceNQueens(chessboard, col + 1)
            # As previously placed queen was not valid, restore '.'
            chessboard[row][col] = '.'


def main():
    chessboard = []
    N = int(sys.argv[1])

    for i in range(N):
        row = ["."] * N
        chessboard.append(row)

    # Start placing the queen 'Q' from the 0'th column.
    PlaceNQueens(chessboard, 0)


if __name__ == "__main__":
    main()
