def perm(a, n):
  # recursion anchor
  if n <= 0:
    return [[]]
  else:
    result = []
    for smallPerm in perm(a, n-1):
      # take all elements from a
      for elem in a:
        # and prepend them to all permutations we get from perm(n-1, 1)
        if elem not in smallPerm:
            result.append([elem] + smallPerm)
    
    return result

# driver code
# print(perm([1, 2, 3], 2))
print(perm([1, 2, 3], 3))
print(perm([3, 3, 2], 3))