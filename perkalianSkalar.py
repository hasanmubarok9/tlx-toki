if __name__ == "__main__":
    n = int(input())
    v1 = list(map(int, input().split()))
    v2 = list(map(int, input().split()))

    v1.sort()
    v2.sort(reverse=True)

    print(sum([x1*x2 for (x1, x2) in zip(v1, v2)]))
