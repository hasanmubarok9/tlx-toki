# permutation dengan elemen boleh berulang dengan iterasi

# n = 3
# for i in range(1, n + 1):
#     for j in range(1, n + 1):
#         for k in range(1, n + 1):
#             print("%d %d %d " % (i, j, k))

# program ini men-generate barisan yang terdiri dari n
# bilangan dari 1 sampai m (inklusif) dengan m <= n

def generate(arr, n):
    # print("arr ", arr)
    if len(arr) == n:
        print(" ".join([str(i) for i in arr]))
        return

    for i in range(1, n+1):
        arr.append(i)
        generate(arr, n)
        arr.pop()


n = 3
generate([], n)
