def subset_sum(arr, starting_index, sum):
    print("Arr ", arr)
    print("starting_index ", starting_index)
    print("sum ", sum)
    if (sum == 0):
        return True
    if (len(arr) - starting_index == 1):
        print("nilai arr[starting_index] ", arr[starting_index])
        print("nilai sum ", sum)
        if(arr[starting_index] == sum): 
            return True
        else:
            return False

    # optimized
    if arr[starting_index] > sum:
        return False
     
    result_1 = subset_sum(arr, starting_index + 1, sum - arr[starting_index])
    print("result_1 ", result_1)
     
    result_2 = subset_sum(arr, starting_index + 1, sum)
    print("result_2 ", result_2)
     
    return result_1 or result_2      

# print(subset_sum([1, 2, 3], 0, 1))
# print(subset_sum([1, 2, 3], 0, 2))
# print(subset_sum([1, 2, 3], 0, 3))
# print(subset_sum([1, 2, 3], 0, 4))
# print(subset_sum([1, 2, 3], 0, 5))
# print(subset_sum([1, 2, 3], 0, 6))
# print(subset_sum([1, 2, 3], 0, 7))
print(subset_sum([1, 2, 3], 0, -1))
# print(subset_sum([1, 2, 9, 2, 20], 0, 20))

