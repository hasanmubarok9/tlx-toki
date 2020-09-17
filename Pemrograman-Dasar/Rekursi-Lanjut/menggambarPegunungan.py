def drawMountains(n):
    # print("nilai n ", n)
    if n > 0:
        drawMountains(n - 1)
        for _ in range(n):
            print("*", end="")
        print()
        drawMountains(n - 1)

if __name__ == "__main__":
    n = int(input())
    drawMountains(n)