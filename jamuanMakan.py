if __name__ == "__main__":
    n = int(input())
    # startTimeAndDuration = []
    startTimeAndLastTime = []
    for _ in range(n):
        a, b = map(int, input().split())
        # startTimeAndDuration.append((a, b))
        startTimeAndLastTime.append((a, a+b-1))

    # print("startTimeAndDuration before sort ", startTimeAndDuration)
    # print("startTimeAndLastTime before sort ", startTimeAndLastTime)
    # startTimeAndDuration.sort(key=lambda x: (x[0], x[1]))
    startTimeAndLastTime.sort(key=lambda x: x[1])
    # print("startTimeAndDuration after sort ", startTimeAndDuration)
    # print("startTimeAndLastTime after sort ", startTimeAndLastTime)

    lastTime = 0
    total = 0
    for item in startTimeAndLastTime:
        # print("lastTime ", lastTime)
        # print("item[0] ", item[0])
        # print("item[1] ", item[1])
        if item[0] > lastTime:
            total += 1
            lastTime = item[1]

        # print("total ", total)
    print(total)
