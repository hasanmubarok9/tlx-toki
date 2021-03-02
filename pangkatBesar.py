def findPower(a, b):
    mod = 1000000
    if b == 1:
        if (a >= mod):
            return (a % mod), True
        return a, False

    # case b is even
    if b % 2 == 0:
        temp, greater = findPower(a % mod, b // 2)

        # check if length of digit greater than 6
        if(temp * temp > mod):
            return ((temp * temp) % mod), True

        return (temp * temp), greater

    # case b is odd
    else:
        temp, greater = findPower(a % mod, b-1)

        if(a * temp > mod):
            return ((a * temp) % mod), True

        return (a * temp), greater


if __name__ == "__main__":
    a, b = map(int, input().split())
    res, greater = findPower(a, b)
    if(greater):
        stringLength = len(str(res))
        if stringLength < 6:
            print("0"*(6 - stringLength) + str(res))
        else:
            print(res)
    else:
        print(res)
