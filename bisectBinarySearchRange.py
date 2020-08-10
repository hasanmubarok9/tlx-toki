from bisect import bisect_left, bisect_right

daysSick = [0, 0, 0, 0, 1, 2, 3, 3, 3, 4, 5, 5, 5, 6, 6, 11, 15, 24]

# print(bisect_left(daysSick, 5))
# print(bisect_right(daysSick, 5))

result = bisect_right(daysSick, 10)
print(result)

