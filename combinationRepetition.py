# Python3 program to print all combination 
# of size r in an array of size n 

''' arr[] ---> Input Array 
	chosen[] ---> Temporary array to store 
			current combination 
	start & end ---> Staring and Ending indexes in arr[] 
	r---> Size of a combination to be printed 

	'''
def CombinationRepetitionUtil(chosen, arr, index, 
							r, start, end): 
									
	# Current combination is ready, 
	# print it 
	if index == r: 
		for j in range(r): 
			print(chosen[j], end = " ") 
			
		print() 
		return
		
	# When no more elements are 
	# there to put in chosen[] 
	if start > n: 
		return
		
	# Current is included, put 
	# next at next location 
	chosen[index] = arr[start] 
	
	# Current is excluded, replace it 
	# with next (Note that i+1 is passed, 
	# but index is not changed) 
	CombinationRepetitionUtil(chosen, arr, index + 1, 
							r, start, end) 
	CombinationRepetitionUtil(chosen, arr, index, 
							r, start + 1, end) 

# The main function that prints all 
# combinations of size r in arr[] of 
# size n. This function mainly uses 
# CombinationRepetitionUtil() 
def CombinationRepetition(arr, n, r): 
	
	# A temporary array to store 
	# all combination one by one 
	chosen = [0] * r 

	# Print all combination using 
	# temprary array 'chosen[]' 
	CombinationRepetitionUtil(chosen, arr, 0, r, 0, n) 

# Driver code 
arr = [ 1, 2, 3, 4 ] 
r = 2
n = len(arr) - 1

CombinationRepetition(arr, n, r) 

# This code is contributed by Vaibhav Kumar 12.
