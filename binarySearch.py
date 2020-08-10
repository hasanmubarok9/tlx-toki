# def binarySearch(arr, x):
#     n = len(arr); result = 0
#     left = 1; right = n
#     while left <= right and result == 0:
#         mid = ((left + right) // 2)
#         if x < arr[mid]:
#             right = mid - 1
#         elif x > arr[mid]:
#             left = mid + 1
#         else:
#             result = mid

#     return result

# Iterative Binary Search Function 
# It returns index of x in given array arr if present, 
# else returns -1 
def binary_search(arr, x): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
  
        # Check if x is present at mid 
        # If x is greater, ignore left half 
        if arr[mid] < x: 
            low = mid + 1
  
        # If x is smaller, ignore right half 
        elif arr[mid] > x: 
            high = mid - 1
  
        else: 
            return mid 
  
    # If we reach here, then the element was not present 
    return -1
  
  
# Test array 
# arr = [ 2, 3, 4, 10, 40 ] 
# x = 10
  
# arr = [4, 5, 7, 9, 12, 15, 17, 20]
# x = 8

arr = [2, 2, 2, 2, 2, 2]
x = 1
# Function call 
result = binary_search(arr, x) 
  
if result != -1: 
    print("Element is present at index", str(result)) 
else: 
    print("Element is not present in array")

# print(binarySearch([4, 5, 7, 9, 12, 15, 17, 20], 6))
# print(binarySearch([4, 5, 7, 9, 12, 15, 17, 20], 7))
# print(binarySearch([4, 5, 7, 9, 12, 15, 17, 20], 9))
# print(binarySearch([4, 5, 7, 9, 12, 15, 17, 20], 13))
# print(binarySearch([4, 5, 7, 9, 12, 15, 17, 20], 19))
