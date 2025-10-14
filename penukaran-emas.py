def solve(n):
    if n <= 1: return n
    tmp = solve(n // 2) + solve(n // 3) + solve(n // 4)
    return max(tmp, n)

if __name__ == "__main__":
    n = int(input())

print(solve(n))