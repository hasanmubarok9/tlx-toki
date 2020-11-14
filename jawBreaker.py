def jawBreaker(m, f, pick, total):

    currentRowIndex = pick[0]
    currentColIndex = pick[1]

    f[currentRowIndex][currentColIndex] = True
    total.append(1)

    currentPick = m[currentRowIndex][currentColIndex]

    # upper
    if currentRowIndex != 0:
        topRowIndex = currentRowIndex - 1
        topColIndex = currentColIndex
        if not f[topRowIndex][topColIndex] and m[topRowIndex][topColIndex] == currentPick:
            jawBreaker(m, f, (topRowIndex, topColIndex), total)

    # right
    if currentColIndex != len(m[0])-1:
        rightRowIndex = currentRowIndex
        rightColIndex = currentColIndex + 1
        if not f[rightRowIndex][rightColIndex] and m[rightRowIndex][rightColIndex] == currentPick:
            jawBreaker(m, f, (rightRowIndex, rightColIndex), total)

    # bottom
    if currentRowIndex != len(m)-1:
        bottomRowIndex = currentRowIndex + 1
        bottomColIndex = currentColIndex
        if not f[bottomRowIndex][bottomColIndex] and m[bottomRowIndex][bottomColIndex] == currentPick:
            jawBreaker(m, f, (bottomRowIndex, bottomColIndex), total)

    # left
    if currentColIndex != 0:
        leftRowIndex = currentRowIndex
        leftColIndex = currentColIndex - 1
        if not f[leftRowIndex][leftColIndex] and m[leftRowIndex][leftColIndex] == currentPick:
            jawBreaker(m, f, (leftRowIndex, leftColIndex), total)

    return total

if __name__ == "__main__": 
    m, n = map(int, input().split())
    matrices = []
    for _ in range(m):
        matrices.append(list(map(int, input().split())))

    b, k = map(int, input().split())

    flagMatrices = [[False]*n for _ in range(m)]

    result = jawBreaker(matrices, flagMatrices, (b, k), [])

    total = len(result)

    print(total * (total - 1))
