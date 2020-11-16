def jawBreaker(m, f, pick, total):

    currentRowIndex = pick[0]
    currentColIndex = pick[1]

    f[currentRowIndex][currentColIndex] = True
    total.append(pick)

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

# check if all element of matrices is true
def allTrue(f):
    return all([all(el) for el in f])

def searchPick(arr, m, n):
    for i in range(m):
        for j in range(n):
            if not arr[i][j]:
                return i, j

def lookingForTheBiggest(m, n, matrices):
    allPossibleResult = []
    flagMatrices = [[False]*n for _ in range(m)]
    # brute force, looking for the pick
    while not allTrue(flagMatrices):
        b, k = searchPick(flagMatrices, m, n)
        picked = jawBreaker(matrices, flagMatrices, (b, k), [])
        allPossibleResult.append(picked)
    return max(allPossibleResult, key=len)

def runtuhkan(arr, m, n):

    # iterate over column
    for j in range(n):
        # finding base
        # starting from the bottom
        base = m-1
        while base > 0 and arr[base][j] != '.':
            base -= 1

        if base == 0:
            continue
        
        # find the number of element that equal dots (".")
        # elements that will be dropped
        toBeDropped = []
        totalDots = 0
        # iterate over row, start from base
        # actually can started from the top, but I prefer from the bottom
        for k in range(base, -1, -1):
            if arr[k][j] == '.':
                totalDots += 1
            else:
                toBeDropped.append(arr[k][j])

        # assign tobedropped
        for l in range(base, base - (len(toBeDropped)), -1):
            arr[l][j] = toBeDropped[base - l]

        # assign dot
        for o in range(totalDots):
            arr[o][j] = '.'

    display(arr)

def display(m):
    for row in m:
        print(" ".join(row))

if __name__ == "__main__": 
    m, n = map(int, input().split())
    matrices = []
    for _ in range(m):
        # matrices.append(list(map(int, input().split())))
        matrices.append(list(input().split()))

    maxIndexPicked = lookingForTheBiggest(m, n, matrices)

    for a, b in maxIndexPicked:
        matrices[a][b] = '.'

    runtuhkan(matrices, m, n)

