def count(n, coins):
    table_dp = [0]*(n+1)
    table_dp[0] = 0

    for i in range(1, n+1):
        best = 1e38
        print("table_dp before ", table_dp)
        for coin in coins:
            if coin <= i:
                print("for coin ", coin)
                print("best before ", best)
                best = min(best, table_dp[i-coin]+1)
                print("best after ", best)
        table_dp[i] = best
        print("table_dp after ", table_dp)
        print()

    return table_dp[n]


n = int(input())
coins = list(map(int, input().split()))

print("count ", count(n, coins))
