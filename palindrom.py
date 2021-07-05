def find_longest_palindrom(string, i, j, computed, memo):

    # base condition
    if i > j:
        return 0

    if i == j:
        return 1

    if computed[i][j]:
        return memo[i][j]

    best = 1
    # If the last character of the string is the same as the first character
    if string[i] == string[j]:
        best = find_longest_palindrom(
            string, i + 1, j - 1, computed, memo) + 2
    else:
        # If the last character of the string is different from the first character
        # 1. Remove the last character and recur for the remaining substring string[i, j-1]
        # 2. Remove the first character and recur for the remaining substring string[i+1, j]
        best = max(find_longest_palindrom(string, i + 1, j, computed, memo),
                   find_longest_palindrom(string, i, j-1, computed, memo))

    computed[i][j] = True
    memo[i][j] = best

    return best


if __name__ == "__main__":
    strings = []
    n = int(input())
    for _ in range(n):
        strings.append(input())

    for string in strings:
        length = len(string)
        # computed array
        computed = [[0 for _ in range(length)] for _ in range(length)]
        # memo array
        memo = [[False for _ in range(length)] for _ in range(length)]

        print(find_longest_palindrom(string, 0, length-1, computed, memo))
