n = int(input())
prices = list(map(int, input().split()))
m = int(input())

# looks for the smallest value for the element that will be the first digit
# but apart from the first element,
# because the first element (zero) cannot be the first digit
head_price = min(prices[1:], default=prices[0])

# handle if only the first element can be selected
if m < head_price:
    if m < prices[0]:
        print(0)
    else:
        print('1\n0\n0')
    exit()

# looks for the length of digits

# subtract m from the head_price,
# and the result can be used to determine the length of the digit
m -= head_price

# find the minimum value of the entire digit options
tail_price = min(prices)

# length is obtained from: the number of first digit that have been selected (1)
# and then, added to reminder of m divided by smallest price
length = 1 + m//tail_price

m %= tail_price

print("head_price ", head_price)
print("tail_price ", tail_price)
print("length ", length)
print("m ", m)

# specifies the actual head,
# if there is a digit greater than the digit corresponding to the current head_price
for i in reversed(range(n+1)):
    if prices[i] - head_price <= m:
        head = i
        m -= prices[i] - head_price
        break

numbers = [(head, 1)]
remaining_length = length - 1
for i in reversed(range(n+1)):
    diff_cost = prices[i] - tail_price
    if diff_cost == 0:
        print("remaining_length di diff_cost == 0", remaining_length)
        numbers.append((i, remaining_length))
        remaining_length = 0
    else:
        print("m ", m)
        print("diff_cost ", diff_cost)
        print("m // diff_cost ", m // diff_cost)
        print("remaining_length di diff_cost != 0", remaining_length)
        got = min(m // diff_cost, remaining_length)
        print("got ", got)
        numbers.append((i, got))
        remaining_length -= got
        m %= diff_cost
        print("numbers ", numbers)
        print("remaining_length ", remaining_length)
        print("m ", m)


def build_numbers(numbers, k):
    built = ''
    for (num, freq) in numbers:
        built += str(num) * min(freq, k)
        k -= freq
    return built


print(length)
print(build_numbers(numbers, 50))
print(build_numbers(reversed(numbers), 50)[::-1])


# test case

# 2
# 6 7 100
# 105

# 2
# 6 7 100
# 15

# 2
# 6 7 8
# 21

# 2
# 6 7 6
# 12

# 2
# 6 8 7
# 12

# 1
# 1 101
# 100

# 3
# 100 101 102 103
# 99

# 2
# 6 7 8
# 12

# 2
# 6 7 8
# 13

# 2
# 6 7 8
# 14

# 2
# 6 7 8
# 15

# 2
# 6 7 8
# 16

# 2
# 6 7 8
# 17

# 2
# 6 7 8
# 18

# 2
# 6 7 8
# 19

# 2
# 6 7 8
# 20

# 3
# 100 101 102 103
# 306

# 3
# 100 101 102 103
# 305
