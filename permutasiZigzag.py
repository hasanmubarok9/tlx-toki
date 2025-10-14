def isZigzag(arr):
    n = len(arr)
    for i in range(1, n-1):
        if (arr[i-1] <= arr[i] <= arr[i+1]) or (arr[i-1] >= arr[i] >= arr[i+1]):
            return False
    return True


def zigZagPermutation(n, depth, arr, pernah):
    if depth >= n and isZigzag(arr):
        print("".join([str(w+1) for w in arr]))

    for i in range(n):
        if not pernah[i]:
            pernah[i] = True
            arr[depth] = i
            zigZagPermutation(n, depth + 1, arr, pernah)
            pernah[i] = False

if __name__ == "__main__": 
    n = int(input())
    zigZagPermutation(n, 0, [0]*n, [False]*n)
