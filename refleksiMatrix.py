def isIdentic(arr1, arr2):
    return arr2 == arr1

def isHorizontalIdentic(arr1, arr2):
    return arr2 == arr1[::-1]

def isVerticalIdentic(arr1, arr2):
    return arr2 == [row[::-1] for row in arr1]

# right diagonal axe, equivalent to transpose of matrix
def isRightDiagonalIdentic(arr1, arr2):
    n = len(arr1)
    return arr2 == [[arr1[j][i] for j in range(n)] for i in range(n)]

# left diagonal axe
def isLeftDiagonalIdentic(arr1, arr2):
    n = len(arr1)
    transpose = [[arr1[j][i] for j in range(n)] for i in range(n)]
    return arr2 == [row[::-1] for row in transpose[::-1]]

def identicalIdentifier(arr1, arr2):
    if isIdentic(arr1, arr2):
        return "identik"
    elif isHorizontalIdentic(arr1, arr2):
        return "horisontal"
    elif isVerticalIdentic(arr1, arr2):
        return "vertikal"
    elif isRightDiagonalIdentic(arr1, arr2):
        return "diagonal kanan bawah"
    elif isLeftDiagonalIdentic(arr1, arr2):
        return "diagonal kiri bawah"
    return "tidak identik"

if __name__ == "__main__": 
    n, m = map(int, input().split())
    firstMatrix = []
    for _ in range(n):
        rows = list(map(int, input().split()))
        firstMatrix.append(rows)

    k, l = map(int, input().split())
    secondMatrix = []
    for _ in range(k):
        rows = list(map(int, input().split()))
        secondMatrix.append(rows)

    print(identicalIdentifier(firstMatrix, secondMatrix))