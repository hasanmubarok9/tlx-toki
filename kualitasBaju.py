def countingSort(arr):
    n = len(arr)
    rangeValue = max(arr) + 1
    frequencyTable = [0]*rangeValue

    # analogi untuk logic ini adalah kita menyiapkan ember sebanyak semua kemungkinan nilai yang ada di array
    # ember-ember itu kita labeli sesuai nilai-nilai tadi
    # kemudian untuk elemen di array, kita masukkan ke dalam ember sesuai nilainya
    for i in range(n):
        x = arr[i]
        frequencyTable[x] += 1

    # setelah elemen-elemen tadi dimasukkan ke dalam ember yang sesuai
    # logic di bawah ini mengeluarkan kembali nilai-nilai di ember-ember tadi
    # kemudian kita sesuaikan urutannya ke dalam array semula
    index = 0
    for value in range(rangeValue):
        for _ in range(frequencyTable[value]):
            arr[index] = value
            index += 1

    return arr

if __name__ == "__main__": 
    n = int(input())
    qualities = []
    for _ in range(n):
        qualities.append(int(input()))

    # sorting array using counting sort
    sortedQualities = countingSort(qualities)
    length = len(sortedQualities)
    if length % 2 != 0:
        median = sortedQualities[(length // 2)]
    else:
        median = (sortedQualities[(length // 2) - 1] + sortedQualities[length // 2]) / 2

    print(float(median))