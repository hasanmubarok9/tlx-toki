def power(a, b, mod):
    print("nilai a, b, dan n", a, b, mod)
    if b == 1:
        return a % mod

    # case b is even
    if b % 2 == 0:
        print("masuk even b ", b)
        temp = power(a % mod, b // 2, mod)
        print("nilai temp ", temp)
        print("nilai temp * temp", temp * temp)
        return (temp * temp) % mod

    # case b is odd
    else:
        print("masuk odd, b ", b)
        temp = power(a % mod, b-1, mod)
        print("nilai temp ", temp)
        print("nilai temp * a", temp * a)
        return (a * temp) % mod

# power without residu


def power_without_residu(a, b):
    if b == 1:
        return a

    # case b is even
    if b % 2 == 0:
        temp = power_without_residu(a, b // 2)
        return temp * temp

    # case b is odd
    else:
        temp = power_without_residu(a, b-1)
        return a * temp


# Driver Code
if __name__ == "__main__":
    a, b, c, n = map(int, input().split())
    # solusi naif
    ans = a
    for i in range(c):
        # ans = power(ans, b, n)
        ans = power_without_residu(ans, b)
        print("ans d loop ", ans)

    print("ans ", ans)
    # print(ans+1)
