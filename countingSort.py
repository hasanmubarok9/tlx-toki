def countingSort(arr):
    n = len(arr)
    rangeValue = max(arr)+1
    ftable = [0] * (rangeValue)
    for i in range(n):
        x = arr[i]
        ftable[x] += 1

    print("ftable ", ftable)

    index = 0
    for i in range(rangeValue):
        for _ in range(ftable[i]):
            print("nilai i ", i)
            print("nilai arr sebelum", arr)
            print("nilai index sebelum", index)
            arr[index] = i
            index += 1
            print("nilai index sesudah", index)
            print("nilai arr sesudah", arr)

    return arr

print(countingSort([4, 3, 2, 8, 5, 3]))