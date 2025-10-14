def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            print("i ", i)
            print("j ", j)
            if arr[j] > arr[j+1]:
                # swap the element with the next element if current element less than next element
                arr[j], arr[j+1] = arr[j+1], arr[j]

    return arr

print(bubbleSort([4, 3, 2, 8, 5, 3]))