def per(l):
    if len(l) == 1:
        return [l]
    # direct return
    return [[l[i]] + p for i in range(len(l))for p in per(l[:i] + l [i+1:])]

print(per([3, 3, 2]))