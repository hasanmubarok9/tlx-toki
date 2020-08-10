# This program decompose integer

import sys

def partition(n, top, out):
    print("n ", n)
    print("top ", top)
    print("out ", out)
    if n == 0:
        print(out)
    elif n > 0:
        for i in range(1, top+1):
            print("i ", i)
            partition(n - i, i, out + str(i) + " ")

if __name__ == "__main__":
    input = int(sys.argv[1])
    partition(input, input, "")
    