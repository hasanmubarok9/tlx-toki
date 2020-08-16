def fib(n):

    if n <= 1:
        return n

    a = 0
    b = 1

    for _ in range(2, n+1):
        c = a + b
        a = b
        b = c
        # print("c ", c)

    return c

print(fib(0))
print(fib(1))
print(fib(2))
print(fib(3))
print(fib(4))
print(fib(5))
print(fib(6))
print(fib(7))
print(fib(8))
