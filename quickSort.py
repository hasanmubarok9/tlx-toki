def partition(arr, low, high):
    print("nilai low ", low)
    print("nilai high ", high)
    pivot = arr[high]

    print("nilai pivot ", pivot)

    i = low - 1

    for j in range(low, high):

        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

        print("nilai j ", j)
        print("nilai i ", i)

        print("nilai arr ", arr)

    arr[high], arr[i + 1] = arr[i + 1], arr[high]
    print("nilai arr di akhir partisi ", arr)
    return i + 1


def quickSort(arr, low, high):
    print("nilai arr di quickSort ", arr)
    if low < high:

        pi = partition(arr, low, high)
        print("nilai pi ", pi)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)


# arr = [10, 7, 8, 9, 1, 5]
# arr = [10, 30, 80, 90, 40, 50, 70]
# arr = [4, 3, 2, 1]
arr = [2, 5, 7, 4, 6, 1, 3, 8, 9]
n = len(arr)
quickSort(arr, 0, n - 1)
print("Sorted array is:")
for i in range(n):
    print("%d" % arr[i])
