
# this sorting use counting sort, but it failed, because its using len only
def countingSort(arr):
    n = len(arr)

    # rangeValue is all possible value in arr
    rangeValue = len(max(arr, key=len))

    # create array that will used to store the frequency of len for every name
    fTable = [0] * (rangeValue+1)

    # counting the frequence for every len name
    for i in range(n):
        fTable[len(arr[i])] += 1

    print("fTable ", fTable)

    index = 0
    # looping over range value zero to all possible value of arr
    for i in range(rangeValue+1):
        # for every value in fTable, insert to previous arr
        for _ in range(fTable[i]):
            arr[index] = i
            index += 1
    return arr

if __name__ == "__main__": 
    n = int(input())
    names = []
    for i in range(n):
        names.append(input())

    # sorting len name using counting sort
    # print(countingSort(names))
    names.sort(key=lambda item: (len(item), item))
    for data in names:
        print(data)
    