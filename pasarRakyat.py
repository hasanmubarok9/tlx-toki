# Python program to find LCM of two numbers 
  
# Recursive function to return gcd of a and b 
def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
  
# Function to return LCM of two numbers 
def lcm(a,b): 
    return (a*b) / gcd(a,b)

if __name__ == "__main__": 
    n = int(input())
    periods = []
    for i in range(n):
        periods.append(int(input()))

    next = lcm(periods[0], periods[1])
    for i in range(2, len(periods)):
        next = lcm(next, periods[i])

    print(int(next))