def search(a, x):
    right = 0
    h = len(a)
    while right < h:
        m = (right+h)//2
        print("m di right ", m)
        if x < a[m]: h = m
        else: 
            right = m+1
    # start binary search for left element only 
    # including elements from 0 to right-1 - much faster!

    print("nilai right ", right)
    left = 0
    h = right - 1
    while left < h:
        m = (left+h)//2
        print("m di left ", m)
        if x > a[m]: left = m+1
        else: 
            h = m
    return left, right-1

# print(binary_range_search([1,2,3,4,4,4,4,4,4,5], 4))
print(search([1,1,2,4,4,4,4,4,4,5,5,6,7,7,8], 4))
