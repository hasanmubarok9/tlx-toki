# menghitung nilai dari gerakan tarian 
def countMoveValue(arr, Y):
    # print("arr ", arr)
    # print("Y ", Y)
    n = len(arr)
    K = 0
    convincing = False
    for i in range(n):   
        val = 0     
        # jika tarian sebelumnya ada yang meyakinkan
        if convincing:
            val += Y
        # flag untuk menentukan jika tarian meyakinkan
        if arr[i][1] == 'Y': convincing = True
        if i == 0:
            val += arr[i][0]        
        else:
            # jika tarian ke i-1 sebelumnya memukau
            if arr[i-1][1] == 'P':
                val += (arr[i][0] * 2)
            # jika tarian ke i-1 sebelumnya melelahkan
            elif arr[i-1][1] == 'L':
                val += arr[i][0] // 2            
            else:
                val += arr[i][0]

        # print("nilai val ", val)
        K += val
    # print("nilai K ", K)
    return K

# brute force digunakan di sini, untuk men-generate semua kemungkinan nilai dari 
# gerakan-gerakan yang dikuasai oleh peserta
def perm(n, a):
    if n <= 0:
        return [[]]
    else:
        result = []
        for smallPerm in perm(n-1, a):
            for elem in a:
                if elem not in smallPerm:
                    result.append([elem] + smallPerm)
        return result

def possiblyAmazed(r, moves, limitValue, y):
    total = 0
    convertedMoves = [(int(x), y) for (x, y) in moves]
    for move in perm(r, convertedMoves):
        if countMoveValue(move, y) > limitValue:
            total += 1
    return total

if __name__ == "__main__":
    subSoal = input().split()

    # N banyak jenis gerakan yang dikuasai oleh peserta
    # R banyak gerakan yang harus ditampilkan oleh peserta selama kontes 
    # Y Nilai yang ditambahkan pada total ketika terdapat tarian yang meyakinkan
    # J banyak juri kontes

    N, R, Y, J = map(int, input().split())
    moves = []
    for _ in range(N):
        moves.append(input())
    
    splittedMoves = [tuple(move.split()) for move in moves]
    
    beautyLimitValues = []
    for _ in range(J):
        beautyLimitValues.append(int(input()))

    results = []
    for value in beautyLimitValues:
        results.append(possiblyAmazed(R, splittedMoves, value, Y))
    

    for res in results:
        print(res)