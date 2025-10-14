# check given input number is prime bu using square root
def isPrimeSqrt(n):

    if n <= 1:
        return False

    i = 2
    while i*i <= n:  # this line equals to equation i <= sqrt(n)
        if n % i == 0:
            return False
        i += 1

    return True

print(isPrimeSqrt(7))
print(isPrimeSqrt(6))