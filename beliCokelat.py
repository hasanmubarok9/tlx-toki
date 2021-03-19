if __name__ == "__main__":
    n, d = map(int, input().split())
    v = []
    for _ in range(n):
        h, b = map(int, input().split())
        v.append((h, b))

    v.sort(key=lambda x: (x[0], x[1]))

    total = 0
    i = 0
    while d > 0 and i < len(v):
        if v[i][0]*v[i][1] > d:
            total += (d // v[i][0])
            d -= ((d // v[i][0])*v[i][0])
        else:
            total += v[i][1]
            d -= v[i][0] * v[i][1]
        i += 1

    print(total)
