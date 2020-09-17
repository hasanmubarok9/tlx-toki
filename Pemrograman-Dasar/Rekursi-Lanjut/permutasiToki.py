
def perm(n, depth, arr, pernah):
    # print("n ", n)
    # print("depth ", depth)
    # print("arr ", arr)
    # print("pernah ", pernah)
    if depth > n-1:
        for i in range(n):
            print(arr[i], end="")
        print()    
    else:
        for i in range(n):
            # print("pernah ", pernah)
            # print("i ", i)
            # print("depth ", depth)
            # print("pernah[i] ", pernah[i])
            # print()
            if not pernah[i]:
                pernah[i] = True
                arr[depth] = i
                perm(n, depth + 1, arr, pernah)
                pernah[i] = False


print(perm(3, 0, [0]*3, [False]*3))