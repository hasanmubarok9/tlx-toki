if __name__ == "__main__":
    n, m = map(int, input().split())
    # ukuran kaki-kaki bebek
    footDuckSizes = []
    for _ in range(n):
        footDuckSizes.append(int(input()))

    # ukuran sepatu-sepatu bebek yang dimiliki pak dengklek
    shoeSizes = []
    for _ in range(m):
        shoeSizes.append(int(input()))

    footDuckSizes.sort()
    shoeSizes.sort()

    i = 0
    j = 0
    total = 0
    while i < len(footDuckSizes) and j < len(shoeSizes):
        stop = False
        while (not stop) and j < len(shoeSizes):
            if shoeSizes[j] in [footDuckSizes[i], footDuckSizes[i]+1]:
                total += 1
                stop = True
                j += 1
            elif shoeSizes[j] > footDuckSizes[i]+1:
                stop = True
            else:
                j += 1
        i += 1

    print(total)
