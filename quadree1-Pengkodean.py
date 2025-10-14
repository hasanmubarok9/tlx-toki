# playing recursive here
def quadtree1(m, arr, answers):
    dim = len(m)

    if homogen(m):
        if m[0][0] == 1:
            result = [1]
            result.extend(arr)
            answers.append(result) 
            return answers
        return []

    # create partition
    # kuadran 1
    quadrant1 = [el[:dim//2] for el in m[:dim//2]]
    arr1 = arr[:]
    arr1.append(0)
    quadtree1(quadrant1, arr1, answers)

    # kuadran 2
    quadrant2 = [el[dim//2:] for el in m[:dim//2]]
    arr2 = arr[:]
    arr2.append(1)
    quadtree1(quadrant2, arr2, answers)

    # kuadran 3
    quadrant3 = [el[:dim//2] for el in m[dim//2:]]
    arr3 = arr[:]
    arr3.append(2)
    quadtree1(quadrant3, arr3, answers)

    # kuadran 4
    quadrant4 = [el[dim//2:] for el in m[dim//2:]]
    arr4 = arr[:]
    arr4.append(3)
    quadtree1(quadrant4, arr4, answers)

    return answers

def homogen(m): 
    return all(list(all(el == 1 for el in row) for row in m)) or all(list(all(el == 0 for el in row) for row in m))


# find the nearest power of two
def nearestPowerofTwo(n):
    power = 0
    while(n > 2**power):
        power += 1

    return power

# completing the matrice so the shape is 2^p * 2^p
def completeMatrices(r, c, matrices):
    # complete row number if row less than column
    greater = r if r > c else c
    pow = nearestPowerofTwo(greater)
    newDim = 2**pow

    # extending the row
    matrices.extend([[0]*newDim]*(2**pow - r))
    # extending the columns
    for i in range(newDim-(newDim-r)):
        matrices[i].extend([0]*(2**pow-c))

if __name__ == "__main__": 
    r, c = map(int, input().split())
    matrices = []
    for _ in range(r):
        matrices.append(list(map(int, input().split())))

    completeMatrices(r, c, matrices)

    answers = quadtree1(matrices, [], [])

    print(len(answers))
    for answer in answers:
        print(''.join(map(str, answer)))


