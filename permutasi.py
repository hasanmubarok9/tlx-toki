# program ini men-generate barisan yang terdiri dari n
# bilangan dari 1 sampai m (inklusif) dengan m <= n

def generate(arr, chosen, n):
    # print("arr ", arr)
    if len(arr) == n:
        print(" ".join([str(i) for i in arr]))

    for i in range(1, n+1):
        if(chosen[i]):
            continue
        chosen[i] = True
        arr.append(i)
        generate(arr, chosen, n)
        chosen[i] = False
        arr.pop()


n = 3
chosen = [False for _ in range(n+1)]
# print("chosen ", chosen)
generate([], chosen, n)
