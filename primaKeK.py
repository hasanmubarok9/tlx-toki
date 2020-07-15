def siveOfErathostenes(n):
    eliminated = list(False for _ in range(n+1))
    primeList=[]
    for i in range(2, n):
        if not eliminated[i]:
            primeList.append(i)
            j = i*i
            while j <= n:
                eliminated[j] = True
                j += i
    return primeList


if __name__ == "__main__": 
    T = int(input())
    k = []
    for _ in range(T):
        k.append(int(input()))

    primes = siveOfErathostenes(1000000)

    for i in k:
        print(primes[i-1])