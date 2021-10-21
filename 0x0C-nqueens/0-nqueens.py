#!/usr/bin/python3
"""
Solving N Queens problem
"""
import sys

def print_board(board):
    new_lst = []
    for i, row in enumerate(board):
        value = []
        for j, col in enumerate(row):
            if col == 1:
                value.append(i)
                value.append(j)
        new_lst.append(value)
    print (new_lst)

def isSafe(board, row, col, number):
    for i in range(col):
        if board[row][i] == 1:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, number, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

def solveNQUtil(board, col, number):
    if (col == number):
        print_board(board)
        return True
    res = False
    for i in range(number):
        if (isSafe(board, i, col, number)):
            board[i][col] = 1
            res = solveNQUtil(board, col + 1, number) or res
            board[i][col] = 0
    return res

def solve(number):
    board = [[0 for i in range(number)] for i in range(number)]
    if not solveNQUtil(board, 0, number):
        return False
    return True

def validate(args):
    if (len(args) == 2):
        try:
            number = int(args[1])
        except Exception:
            print("N must be a number")
            exit(1)
        return number
    else:
        print("Usage: nqueens N")
        exit(1)




if __name__ == '__main__':
    number = validate(sys.argv)
    solve(number)
