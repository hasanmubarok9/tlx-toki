def quadree(code, indexCode, m, indexRowM, indexColM):

    if len(code) == 1:
        for i in range(indexRowM[1]):
            for j in range(indexColM[1]):
                m[i][j] = 1
        return
    
    # quadran 1
    if code[indexCode] == "0":
        indexRowM = (indexRowM[0], indexRowM[0] + (indexRowM[1]-indexRowM[0]) // 2)
        indexColM = (indexColM[0], indexColM[0] + (indexColM[1] - indexColM[0]) // 2)
    # quadran 2
    elif code[indexCode] == "1":
        indexRowM = (indexRowM[0], indexRowM[0] + (indexRowM[1]-indexRowM[0]) // 2)
        indexColM = (indexColM[0] + (indexColM[1]-indexColM[0]) // 2, indexColM[1])
    # quadran 3
    elif code[indexCode] == "2":
        indexRowM = (indexRowM[0] + (indexRowM[1] - indexRowM[0]) // 2, indexRowM[1])
        indexColM = (indexColM[0], indexColM[0] + (indexColM[1]-indexColM[0]) // 2)
    # quadran 4
    elif code[indexCode] == "3":
        indexRowM = (indexRowM[0] + (indexRowM[1] - indexRowM[0]) // 2, indexRowM[1])
        indexColM = (indexColM[0] + (indexColM[1] - indexColM[0]) // 2, indexColM[1])

    if indexCode == len(code) - 1:
        for i in range(indexRowM[0], indexRowM[1]):
            for j in range(indexColM[0], indexColM[1]):
                m[i][j] = 1

        return

    return quadree(code, indexCode+1, m, indexRowM, indexColM)

def formatMatrix(m, r, c):
    for i in range(r):
        for j in range(c):
            if j != c - 1:
                print(m[i][j], end=" ")
            else:
                print(m[i][j], end="")
        print()

# find the nearest power of two
def nearestPowerofTwo(n):
    power = 0
    while(n > 2**power):
        power += 1

    return power

if __name__ == "__main__": 
    n = int(input())
    codes = []
    for _ in range(n):
        codes.append(input())
    r, c = map(int, input().split())

    # find the pow
    greater = r if r > c else c
    pow = nearestPowerofTwo(greater)
    dim = 2**pow

    # create a matrix where all elements are zero
    m = [[0]*dim for _ in range(dim)]

    for code in codes:
        quadree(code, 1, m, (0, dim), (0, dim))

    slicedM = [row[:c] for row in m[:r]]
    formatMatrix(slicedM, r, c)
