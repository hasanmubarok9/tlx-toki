def binarySearch(arr, x):
    n = len(arr); result = 0
    left = 0; right = n-1
    while left <= right and result == 0:
        mid = ((left + right) // 2) - 1
        if x < arr[mid][1]:
            right = mid - 1
        elif x > arr[mid][1]:
            left = mid + 1
        else:
            result = mid
    if result != 0:
        return arr[result]
    return ((0, 0), 0)
