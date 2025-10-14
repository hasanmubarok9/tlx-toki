if __name__ == "__main__":
    n = int(input())
    startTimeAndLastTime = []
    for _ in range(n):
        a, b = map(int, input().split())
        startTimeAndLastTime.append((a, a+b-1))

    startTimeAndLastTime.sort(key=lambda x: x[1])

    lastTime = 0
    total = 0
    for item in startTimeAndLastTime:
        if item[0] > lastTime:
            total += 1
            lastTime = item[1]

    print(total)
