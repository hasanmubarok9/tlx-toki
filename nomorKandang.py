n = int(input())
prices = list(map(int, input().split()))
m = int(input())

head = min(prices[1:], default=prices[0])

if m < head or n == 0:
    if m < prices[0]:
        print(0)
    else:
        print('1\n0\n0')
    exit()

m -= head
tail = min(prices)
length = 1 + (m//tail)
m %= tail

for i in reversed(range(n+1)):
    if prices[i] - head <= m:
        head = i
        m -= prices[i] - head
        break

numbers = [(head, 1)]
remaining_length = length - 1

for i in reversed(range(n+1)):
    diff_cost = prices[i] - tail
    if diff_cost == 0:
        numbers.append((i, remaining_length))
        remaining_length = 0
    else:
        got = min(m//diff_cost, remaining_length)
        numbers.append((i, got))
        remaining_length -= got
        m %= diff_cost


def build_number(numbers, k):
    built = ''
    for (number, freq) in numbers:
        built += str(number) * min(freq, k)
        k -= freq
    return built


print(length)
print(build_number(numbers, 50))
print(build_number(reversed(numbers), 50)[::-1])
