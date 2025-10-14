def count(sum, coins, computed, memo):
    if sum <= 0:
        return 0

    if computed[sum]:
        return memo[sum]
    
    best = 1e38
    for coin in coins:
        if coin <= sum:
            best = min(count(sum - coin, coins, computed, memo) + 1, best)

    computed[sum] = True
    memo[sum] = best

    print("computed ", computed)
    print("memo ", memo)
    return best

n = int(input())
coins = list(map(int, input().split()))
computed = [False]*(n+1)
memo = [0]*(n+1)

print("count ", count(n, coins, computed, memo))


