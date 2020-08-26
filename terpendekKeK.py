def countingSort(arr):
    rangeValue = max(arr)+1
    fTables = [0] * rangeValue
    # counting the frequency for every element in arr:
    for data in arr:
        fTables[data] += 1

    # sorting
    index = 0
    for i in range(rangeValue):
        for _ in range(fTables[i]):
            arr[index] = i
            index += 1


    return arr

if __name__ == "__main__":
    N, K = map(int, input().split())
    heights = list(map(int, input().split()))
    sortedHeights = countingSort(heights)
    print(sortedHeights[K-1])