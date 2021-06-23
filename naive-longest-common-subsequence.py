def lcs(a, b):
    print("len a ", len(a))
    print("len b ", len(b))
    common = []
    last_found_b_index = 0
    for i in range(len(a)):
        for j in range(last_found_b_index, len(b)):
            if a[i] == b[j]:
                print("sama!, nilai i ", i)
                print("sama!, nilai j ", j)
                last_found_b_index = j
                break
        print("nilai i ", i)
        print("nilai last_found_b_index ", last_found_b_index)
        if a[i] == b[last_found_b_index]:
            common.append(b[last_found_b_index])
    return common


print(lcs("ajaib", "badai"))
print(lcs("abcdgh", "aedfhr"))
print(lcs("aggtab", "gxtxayb"))
