def amount_of_change_coins(change, coins, computed, memo):
    if change == 0:
        return 0

    if computed[change]:
        return memo[change]

    best = 50000
    for coin in coins:
        if coin <= change:
            best = min(best, amount_of_change_coins(
                change-coin, coins, computed, memo)+1)

    computed[change] = True
    memo[change] = best

    return best


if __name__ == "__main__":
    n = int(input())
    coins = list(map(int, input().split()))
    change = int(input())

    computed = []
    for _ in range(change+1):
        computed.append(False)

    memo = []
    for _ in range(change+1):
        memo.append(0)

    result = amount_of_change_coins(change, coins, computed, memo)
    if result == 50000:
        print(-1)
    else:
        print(result)
