def insertionSort(arr):
    n = len(arr)
    for i in range(n):
        pos = i
        while (pos > 0 and arr[pos] > arr[pos - 1]):
            arr[pos], arr[pos - 1] = arr[pos - 1], arr[pos]
            pos -= 1
    return arr

def findCost(x, weights, prices):
    # print("nilai x ", x)
    divisions = [(p / w, w) for w, p in zip(weights, prices)]
    sortedDiv = insertionSort(divisions)
    # print(sortedDiv)
    totalWeights = 0
    totalCost = 0
    for pricePerKg, weight in sortedDiv:
        totalWeights += weight
        # print("nilai totalWeights ", totalWeights)
        if totalWeights >= x:
            totalWeights -= weight
            # print("nilai totalWeights di dalam if ", totalWeights)
            for _ in range(1, weight+1):
                if totalWeights >= x:
                    break
                totalWeights += 1
                totalCost += pricePerKg
            break
        # totalCost += float('{:.5f}'.format(pricePerKg * weight))
        totalCost += pricePerKg * weight

    return totalCost

if __name__ == "__main__": 
    N, X = map(int, input().split())
    weights = list(map(int, input().split()))
    prices = list(map(int, input().split()))
    result = findCost(X, weights, prices)
    print("%.5f" % result)
    # print(insertionSort([4, 3, 2, 8, 5, 3]))