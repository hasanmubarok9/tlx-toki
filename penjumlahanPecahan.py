# Recursive function to return gcd of a and b 
def gcd(a,b): 
    if a == 0: 
        return b 
    return gcd(b % a, a) 
  
# Function to return LCM of two numbers 
def lcm(a,b): 
    return (a*b) / gcd(a,b) 

def sumFraction(*args):
    A, B, C, D = args
    numerator = (lcm(B, D)/B)*A + (lcm(B, D)/D)*C
    denumerator = lcm(B, D)
    return int(numerator/gcd(numerator, denumerator)), int(denumerator/gcd(numerator, denumerator))

if __name__ == "__main__": 
    A, B = map(int, input().split())
    C, D = map(int, input().split())
    numerator, denumerator = sumFraction(A, B, C, D)
    print(str(numerator) + " " + str(denumerator))
