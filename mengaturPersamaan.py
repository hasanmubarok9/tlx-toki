# exist function is used to search element x in array arr
# search method use binary search
# array have to sorted before pass to function

def exist(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
  
        # Check if x is present at mid 
        # If x is greater than mid element, ignore left half 
        if arr[mid] < x: 
            low = mid + 1
  
        # If x is smaller, ignore right half 
        elif arr[mid] > x: 
            high = mid - 1
  
        else: 
            return True
            
    return False

def countTriplets(arr):    
    n = len(arr)
    count = 0
    for i in range(n):
        for j in range(n):
            p = arr[i]
            q = arr[j]
            r = -(p + q)
            if exist(sorted(arr), r):
                print("p ", p)
                print("q ", q)
                print("r ", r)
                count += 1

    return count

# print(exist(sorted([5, 3, 2, 4, 1]), 5))
print(countTriplets([-1, -2, 2, 3, 4]))