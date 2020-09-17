def perm(n, a):
  print("n ", n)
  print("a ", a)
  # recursion anchor
  if n <= 0:
    return [[]]
  else:
    result = []
    for smallPerm in perm(n-1, a):
      print("smallPerm ", smallPerm)
      # take all elements from a
      for elem in a:
        print("elem ", elem)
        # and prepend them to all permutations we get from perm(n-1, 1)
        if elem not in smallPerm:
            result.append([elem] + smallPerm)
    
    print("result ", result)
    return result

# driver code
print(perm(2, [1, 2, 3]))
# print(perm(3, [1, 2, 3]))