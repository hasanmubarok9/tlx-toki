from sys import stdin, stdout

def search(a, n, x):
    right = 0
    h = n
    while right < h:
        m = (right+h)//2
        if x < a[m]: h = m
        else: 
            right = m+1
    return right-1

if __name__ == "__main__": 
    n = int(stdin.readline())
    weights = list(map(int, stdin.readline().split()))
    testCaseNum = int(stdin.readline())

    results = [0]*testCaseNum
    for i in range(testCaseNum):
        x, y = map(int, stdin.readline().split())

        upperBottom = search(weights, n, x)        
        upperTop = search(weights, n, y)    

        results[i] = upperTop - upperBottom


    for result in results:
        print(result)