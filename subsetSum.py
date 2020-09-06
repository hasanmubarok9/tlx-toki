# ini algoritma yang sangat keren, dengan teknik tinggi
# dibutuhkan sebuah pengalaman, kesabaran, dan kemauan untuk
# terus belajar sehingga bisa menghasilkan ide seperti ini

def subset_sum(arr, starting_index, sum):
    if (sum == 0):
        return True
    if (len(arr) - starting_index == 1):
        if(arr[starting_index] == sum): 
            return True
        else:
            return False

    # optimized
    if arr[starting_index] > sum:
        return False
     
    result_1 = subset_sum(arr, starting_index + 1, sum - arr[starting_index])
     
    result_2 = subset_sum(arr, starting_index + 1, sum)
     
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

