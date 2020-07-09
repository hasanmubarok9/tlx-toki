def sumFraction(*args):
    A, B, C, D = args
    return (A, B, C, D)

if __name__ == "__main__": 
    A, B = map(int, input().split())
    C, D = map(int, input().split())
    print(sumFraction(A, B, C, D))
