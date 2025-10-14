# this program validates whether the given sudoku is valid or not
import itertools

def validate(arr):
    return list(range(1, 10)) == sorted(arr)

def sudoku(grid):
    for i in range(9):
        # validate row
        if not validate(grid[i]):
            return False

        # validate column
        if not validate([grid[j][i] for j in range(9)]):
            return False

    # validate sub
    for i in range(3):
        for j in range(3):
            sub = [grid[k][i*3:i*3+3] for k in range(j*3, j*3 + 3)]
            if not validate(list(itertools.chain.from_iterable(sub))):
                return False

    return True

print(sudoku([
    [1, 3, 2, 5, 4, 6, 9, 8, 7],
    [4, 6, 5, 8, 7, 9, 3, 2, 1],
    [7, 9, 8, 2, 1, 3, 6, 5, 4],
    [9, 2, 1, 4, 3, 5, 8, 7, 6],
    [3, 5, 4, 7, 6, 8, 2, 1, 9],
    [6, 8, 7, 1, 9, 2, 5, 4, 3],
    [5, 7, 6, 9, 8, 1, 4, 3, 2],
    [2, 4, 3, 6, 5, 7, 1, 9, 8],
    [8, 1, 9, 3, 2, 4, 7, 6, 5]
]))

# print(sudoku([
#     [1, 3, , 5, 4, 6, 9, 2, 7],
#     [4, 6, 5, 8, 7, 9, 3, 8, 1],
#     [7, 9, 8, 2, 1, 3, 6, 5, 4],
#     [9, 2, 1, 4, 3, 5, 8, 7, 6],
#     [3, 5, 4, 7, 6, 8, 2, 1, 9],
#     [6, 8, 7, 1, 9, 2, 5, 4, 3],
#     [5, 7, 6, 9, 8, 1, 4, 3, 2],
#     [2, 4, 3, 6, 5, 7, 1, 9, 8],
#     [8, 1, 9, 3, 2, 4, 7, 6, 5]
# ]))