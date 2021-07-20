#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing N
non-attacking queens on an N×N board. Write a
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


def IsBoardOk(board, row, col):
    """Check if current queen placements is okay"""
    for c in range(col):
        if (board[row][c] == 'Q'):
            return False
    for r, c in zip(range(row-1, -1, -1), range(col-1, -1, -1)):
        if (board[r][c] == 'Q'):
            return False
    for r, c in zip(range(row+1, len(board), 1), range(col-1, -1, -1)):
        if (board[r][c] == 'Q'):
            return False
    return True


def DisplayBoard(board):
    """print current queen placements"""
    positions = []
    for row in range(len(board)):
        for tile in range(len(board[row])):
            if board[row][tile] == 'Q':
                positions.append([row, tile])
    print(positions)


def PlaceNQueens(board, col):
    """place N queens on the board"""
    global boardcnt
    if (col >= len(board)):
        boardcnt += 1
        DisplayBoard(board)
    else:
        for row in range(len(board)):
            board[row][col] = 'Q'
            if (IsBoardOk(board, row, col)):
                PlaceNQueens(board, col + 1)
            board[row][col] = '.'


def main():
    """Main"""
    board = []
    try:
        N = int(sys.argv[1])
    except Exception:
        print('N must be a number')
        exit()
    if N < 4:
        print('N must be at least 4')
        exit()
    for i in range(N):
        row = ["."] * N
        board.append(row)
    PlaceNQueens(board, 0)


if __name__ == "__main__":
    main()
