def insertionSort(arr):
    n = len(arr)
    for i in range(n):
        pos = i
        while (pos > 0 and arr[pos] < arr[pos-1]):
            arr[pos], arr[pos-1] = arr[pos-1], arr[pos]
            pos -= 1

    return arr

if __name__ == "__main__": 
    n = int(input())
    names = []
    order = []
    for i in range(n):
        name = input()
        names.append(name)
        # ordering name using insertion sort
        ordered = insertionSort(names)
        # print("ordered ", ordered)
        # print("ordered index of name ", ordered.index(name))
        order.append(ordered.index(name) + 1)

    for data in order:
        print(data)

    