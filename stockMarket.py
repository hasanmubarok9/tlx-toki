from itertools import combinations

def selectStock(saving, currentValue, futureValue):
    selected = []
    for i in range(1, len(currentValue)+1):
        allPair = [value for value in combinations(zip(currentValue, futureValue), i)]
        for pair in allPair:
            if sum(map(lambda x: x[0], pair)) <= saving:
                sumCurrent = sum(map(lambda x: x[0], pair))
                sumFuture = sum(map(lambda x: x[1], pair))
                if(sumFuture - sumCurrent >= 0):
                    selected.append(sumFuture - sumCurrent)
    if len(selected) > 0:
        return max(selected)
    else:
        return 0           

print(selectStock(250, [175, 133, 109, 210, 97], [200, 125, 128, 228, 133]))        
print(selectStock(30, [1, 2, 4, 6], [5, 3, 5, 6]))        