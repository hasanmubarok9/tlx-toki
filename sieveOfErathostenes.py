def siveOfErathostenes(n):
    eliminated = list(False for _ in range(n+1))
    primeList=[]
    for i in range(2, n+1):
        if not eliminated[i]:
            primeList.append(i)
            j = i*i
            while j <= n:
                eliminated[j] = True
                j += i
    return primeList

if __name__ == "__main__": 
    n = int(input())
    print(siveOfErathostenes(n))