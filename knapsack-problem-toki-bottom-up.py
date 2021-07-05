n, k = map(int, input().split())
weights, prices = [], []

for _ in range(k):
    weight, price = map(int, input().split())
    weights.append(weight)
    prices.append(price)

# memo array
memo = [[0 for _ in range(n+1)] for _ in range(k+1)]


for i in range(k):
    for c in range(n+1):
        if c < weights[i]:
            memo[i+1][c] = memo[i][c]
        else:
            memo[i+1][c] = max(memo[i][c], memo[i][c - weights[i]] + prices[i])

print("memo ", memo)

taken = []
maxPrice = memo[k][n]

for i in range(n, 0, -1):
    if memo[k][i] == maxPrice:
        capacity = i

for i in range(k, 0, -1):
    if memo[i][capacity] != memo[i-1][capacity]:
        taken.append(i)
        capacity -= weights[i-1]

taken.sort()
for item in taken:
    print(item)
