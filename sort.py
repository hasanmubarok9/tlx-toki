def simpleSort(arr):

    n = len(arr)

    for i in range(n):
        j = 0
        stop = n - i
        print("stop ", stop)
        while j < stop - 1:
            print("arr sebelum swap ", arr)
            if arr[j] > arr[j + 1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
            print("arr sesudah swap ", arr)
            j += 1
    return arr

print(simpleSort([7, 4, 1, 5]))