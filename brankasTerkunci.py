def kombinasiTombol(n, k, depth, arr, pernah):
    if depth == k:
        for i in range(k):
            if i != k-1:
                print(arr[i] + 1, end=" ")
            else:
                print(arr[i] + 1, end="")
        print()

    for i in range(arr[depth-1], n):
        if not pernah[i]:
            pernah[i] = True
            arr[depth] = i
            kombinasiTombol(n, k, depth+1, arr, pernah)
            pernah[i] = False


if __name__ == "__main__": 
    n, k = map(int, input().split())
    # n = int(input())
    # kombinasiTombol(n, k)
    kombinasiTombol(n, k, 0, [0]*n, [False]*n)