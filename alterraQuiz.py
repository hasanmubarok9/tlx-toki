a, b, sumA = 12, 6, 0
a = a*b
# a nya harusnya 72
print(a)
b = a//b
# b nya harusnya 12
print(b)
a = a//b
# a nya harusnya 6
print(a)

for i in range(1, a+1):
    print("i ", i)
    print("a ", a)
    sumA = sumA + a % i
    print("sumA ", sumA)

# sumA nya harusnya 3
print(sumA)
