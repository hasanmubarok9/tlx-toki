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
                # if elem not in smallPerm:
                    # result.append([elem] + smallPerm)
                if [elem] + smallPerm not in result:
                    if n == len(a):
                        if ([([elem] + smallPerm).count(x) for x in set([elem] + smallPerm)] == [a.count(x) for x in set(a)]):
                            result.append([elem] + smallPerm)
                    else:
                        result.append([elem] + smallPerm)
    
        return result

# driver code
# print(perm([1, 2, 3], 2))
# print(perm([1, 2, 3], 3))
# print(perm([3, 3, 2], 3))
print(perm([2, 2, 2, 1, 1], 5))