def findMax(arr, left, right):
    # condition to check whether the remaining elements are only one
    if left == right:
        return arr[left]
    else:
        mid = (left + right) // 2
        leftMax = findMax(arr, left, mid)
        rightMax = findMax(arr, mid+1, right)
        return max(leftMax, rightMax)


arr = [8, 3, 5, 1, 9, 6, 4, 2, 7]
# arr = [1, 2, 3]
print('arr ', arr)
res = findMax(arr, 0, len(arr)-1)
print('maximum ', res)
