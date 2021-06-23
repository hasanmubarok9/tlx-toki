def solve(n, g, v, w):
    dp = []
    for _ in range(2):
        row = []
        for _ in range(15):
            row.append(0)
        dp.append(row)

    for c in range(0, g):
        dp[0][c] = 0

    for i in range(1, n+1):
        i_now = i % 2
        i_prev = 1 - i_now
        for c in range(0, g+1):
            best = dp[i_prev][c]
            if c >= w[i]:
                best = max(best, dp[i_prev][c - w[i]] + v[i])
            dp[i_now][c] = best
        print("dp untuk i ", i, " : ", dp)

    return dp[n % 2][g]

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

# dp = []
# for _ in range(6):
#     row = []
#     for _ in range(15):
#         row.append(0)
#     dp.append(row)

print(solve(5, 14, [0, 6, 5, 4, 6, 4], [
    0, 5, 4, 3, 7, 4]))
