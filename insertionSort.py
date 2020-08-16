def insertionSort(arr):
    n = len(arr)
    for i in range(n):
        pos = i
        while ((pos > 0) and (arr[pos] < arr[pos-1])):
            arr[pos], arr[pos-1] = arr[pos-1], arr[pos]
            print("nilai i ", i)
            print("nilai pos ", pos)
            print("arr ", arr)
            pos -= 1


    return arr

print(insertionSort([4, 3, 2, 8, 5, 3]))

# algoritma insertion sort bekerja dengan cukup baik ketika array dalam keadaan sudah hampir terurut
# print(insertionSort([2, 3, 3, 4, 5, 8]))