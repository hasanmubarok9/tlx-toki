def solve(i, c, v, w, computed, memo):
    print("i ", i)
    # print("v[i] ", v[i])
    # print("w[i] ", w[i])
    print("c ", c)
    # print("computed ", computed)
    # print("memo ", memo)
    if i == 0:
        print("masuk 0 pas kapasitas ", c)
        return 0

    if computed[i][c]:
        # print("nilai memo ", memo)
        # print("ini i ", i, "dan c", c,
        #       "yang disimpan di memo ", memo[i][c])
        # if i == 3 and c == 7:
        #     print("ini i ", i, "dan c", c,
        #           "yang disimpan di memo ", memo[i][c])
        print("masuk computed dengan nilai i ", i, "dan kapasitas ",
              c, "dan nilai nilai memo[i][c] ", memo[i][c])
        return memo[i][c]

    best = solve(i-1, c, v, w, computed, memo)
    # print("best ", best)
    if(c >= w[i]):
        best = max(best, solve(i-1, c - w[i], v, w, computed, memo) + v[i])

    print("ini i ", i, "dan c", c, "yang akan disimpan, dengan best ", best)
    # if i == 3 and c == 7:
    #     print("ini i ", i, "dan c", c, "yang akan disimpan, dengan best ", best)
    computed[i][c] = True
    memo[i][c] = best
    print("nilai memo ", memo)
    # print("computed ", computed)
    # print("memo ", memo)
    print("ini nilai i ", i, "dan c ", c,
          "yang akan d return dengan best ", best)
    return best

# soal ini ingin menyelesaian permasalahan knapsack dengan deskripsi sebagai berikut:


# Diberikan n buah barang, dinomori dari 1 sampai N.
# Barang ke i memiliki harga vi rupiah dengan berat wi gram.
# Kita memiliki tas yang berkapasitas G gram.
# Kita ingin memasukkan beberapa barang ke dalam tas,
# sedemikian sehingga jumlah berat dari barang-barang yang kita masukkan tidak lebih dari
# kapasitas tas dan jumlah harganya sebanyak mungkin
# nomor barang | harga | berat
#       1      |   6   |   5
#       2      |   5   |   4
#       3      |   4   |   3
#       4      |   6   |   7
#       5      |   4   |   4
# Jika kita memiliki kapasitas sebesar 14,
# solusi terbaik adalah mengambil barang ke 1, 2, dan 5.
# Total harga yang diperoleh adalah 6 + 5 + 4 = 15
initialComputed = []
for _ in range(6):
    computed = []
    for _ in range(15):
        computed.append(False)
    initialComputed.append(computed)

initalMemo = []
for _ in range(6):
    computed = []
    for _ in range(15):
        computed.append(0)
    initalMemo.append(computed)


# initialComputed = [[False]*15]*6
# initalMemo = [[0]*15]*6
print(solve(5, 14, [0, 6, 5, 4, 6, 4], [
    0, 5, 4, 3, 7, 4], initialComputed, initalMemo))
