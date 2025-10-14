# from itertools import permutations

def per(a, n):
    # recursion anchor
    if n <= 0:
        return [[]]
    else:
        result = []
        for smallPerm in per(a, n-1):
            # take all elements from a
            for elem in a:
                # and prepend them to all permutations we get from perm(n-1, 1)
                # if elem not in smallPerm:
                    # result.append([elem] + smallPerm)
                if [elem] + smallPerm not in result:
                    if n == len(a):
                        if ([([elem] + smallPerm).count(x) for x in set([elem] + smallPerm)] == [a.count(x) for x in set(a)]):
                            result.append([elem] + smallPerm)
                    else:
                        result.append([elem] + smallPerm)
    
        return result


def findBoundaries(weights, n):
    m = len(weights)
    
    # create parittion
    division = m // n
    partition = [division for _ in range(n)]


    # handling residu
    modulo = m % n
    if modulo > 0:
        for i in range(modulo):
            partition[i] += 1

    # sorting python
    weights.sort()

    boundaries = []
    # print("partition ", partition)
    # print("per(partition, len(partition)) ", per(partition, len(partition)))
    for item in set(map(tuple, per(partition, len(partition)))):
        
        # array to gather boundary
        boundaries = []

        # range
        span = 0

        # to iterate over partition
        index = 0
        while index < len(item) - 1:
            span += item[index]
            upperBound = weights[:span][-1] + 1
            boundaries.append(upperBound)
            index += 1

        upperLimit = 0
        lowerLimit = 0

        # validation
        valid = True
        for i in range(len(boundaries)):
            upperLimit += item[i]
            if i > 0 and (any(x >= boundaries[i] for x in weights[lowerLimit:upperLimit]) or any(x < boundaries[i-1] for x in weights[lowerLimit:upperLimit])):
                valid = False
            lowerLimit += item[i]

        if valid:
            # print("item ", item)
            # print("weights ", weights)
            return boundaries            

    return boundaries


if __name__ == "__main__": 
    # number of weight put in
    m = int(input())
    weights = []
    for _ in range(m):
        weights.append(int(input()))
    
    # input for number of desired groups
    n = int(input())

    boundaries = findBoundaries(weights, n)
    print(" ".join(map(str, boundaries)))