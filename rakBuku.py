if __name__ == "__main__":
    n, b = map(int, input().split())
    heightDucks = []
    for i in range(n):
        heightDucks.append(int(input()))

    heightDucks.sort()
    total = 0
    sumResult = 0
    index = len(heightDucks) - 1
    while sumResult < b:
        sumResult += heightDucks[index]
        total += 1
        index -= 1

    print(total)
