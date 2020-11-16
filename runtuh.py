# R is number of row and C is number of column
def isFull(row):
    return row == ["1"]*len(row)

def runtuh(building):
    R = len(building)
    C = len(building[0])

    # finding base
    base = 0
    for i in range(R):
        # remove full row
        if building[i] == ["1"]*C: 
            building[i] = ["0"]*C 
            base = i

    # iterate over column
    for j in range(C):
        k = 0
        sumOne = 0
        while k < R:
            if building[k][j] == "1":
                if k < base:
                    sumOne += 1
                    building[k][j] = "0"
                else:
                    for r in range(k-sumOne, k): building[r][j] = "1"
                    break    

            if (k == R-1 and building[k][j] == "0" and sumOne > 0):  
                for r in range(k-sumOne+1, k+1): building[r][j] = "1"           
            k += 1

    if any(isFull(r) for r in building):
        return runtuh(building)

    for i in range(R): building[i] = "".join(building[i])

    return building


# Driver Code 
if __name__ == "__main__": 
    R, C = map(int, input().split())
    building = []
    # scanning input
    for i in range(R):
        building.append(list(input()))
    print()
    afterFallBuilding = runtuh(building)
    for row in afterFallBuilding:
        print(row)