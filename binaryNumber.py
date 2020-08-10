# this program count the number of one in binary numbers for given integer

if __name__ == '__main__':
    n = int(input())
    count = 0
    while n:
        n &= n << 1
        print("n ", n)
        count += 1

    print(count)