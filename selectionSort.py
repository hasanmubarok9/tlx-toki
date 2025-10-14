def selectionSort(arr):
    n = len(arr)
    for i in range(n):
        # search for minimum element's index
        minIndex = i
        for j in range(i+1, n):
            print("i ", i)
            if arr[j] < arr[minIndex]:
                minIndex = j

        # swap arr[i] with element arr[minIndex]
        print("i ", i)
        print("minIndex ", minIndex)
        arr[i], arr[minIndex] = arr[minIndex], arr[i]

        print("arr ", arr)

    return arr

print(selectionSort([4, 3, 2, 8, 5, 3]))