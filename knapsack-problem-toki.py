def solve(n, k, stones, computed, memo):
    print("n ", n)
    print("k ", k)
    if k == 0:
        return 0

    if computed[k][n]:
        return memo[k][n]

    best = solve(n, k-1, stones, computed, memo)
    if stones[k][0] <= n:
        best = max(best, solve(
            n - stones[k][0], k-1, stones, computed, memo) + stones[k][1])

    computed[k][n] = True
    memo[k][n] = best
    return best


n, k = map(int, input().split())
stones = [(0, 0)]

for _ in range(k):
    stones.append(tuple(map(int, input().split())))

# computed array
computed = []
for i in range(k+1):
    tulus = []
    for j in range(n+1):
        tulus.append(False)
    computed.append(tulus)

# memo array
memo = []
for i in range(k+1):
    lembaran = []
    for j in range(n+1):
        lembaran.append(False)
    memo.append(lembaran)


print("n ", n)
print("k ", k)
print("stones ", stones)
print("computed ", computed)
print("memo ", memo)

print(solve(n, k, stones, computed, memo))
