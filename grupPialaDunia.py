def win(index1, index2, arr):
    newArr = arr[:]
    newArr[index1] += 3
    return newArr

def draw(index1, index2, arr):
    newArr = arr[:]
    newArr[index1] += 1
    newArr[index2] += 1
    return newArr

def lose(index1, index2, arr):
    newArr = arr[:]
    newArr[index2] += 3
    return newArr

def isPossible(n, index1, index2, arr, finalScore):
    if index1 == n-1:
        if arr == finalScore:
            return True
        else:
            return False

    winArr = win(index1, index2, arr)
    drawArr = draw(index1, index2, arr)
    loseArr = lose(index1, index2, arr)

    if index2 == n-1:
        index1 += 1 
        index2 = index1

    winResult = isPossible(n, index1, index2 + 1, winArr, finalScore)
    drawResult = isPossible(n, index1, index2 + 1, drawArr, finalScore)
    loseResult = isPossible(n, index1, index2 + 1, loseArr, finalScore)

    return winResult | drawResult | loseResult

if __name__ == "__main__": 
    t = int(input())
    results = []
    for _ in range(t):
        guess = list(map(int, input().split()))
        num = guess[0]
        finalScore = guess[1:]
        result = "YES" if isPossible(num, 0, 1, [0]*num, finalScore) else "NO"
        results.append(result)
    
    for res in results:
        print(res)
        
