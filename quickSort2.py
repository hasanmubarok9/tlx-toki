# this code is copied from book pemrograman kompetitif
def quickSort(arr, left, right):
    if (left >= right):
        return
    else:
        # menggunakan partisi hoare
        pivot = arr[(left + right) // 2]
        pLeft = left
        pRight = right

        while pLeft <= pRight:

            # gerakkan pleft ke kanan sampai ditemui arr[pLeft] yang >= pivot
            while arr[pLeft] < pivot:
                pLeft += 1

            # gerakkan pright ke kiri sampai ditemui arr[pRight] yang <= pivot
            while arr[pRight] > pivot:
                pRight -= 1

            if pLeft <= pRight:
                # swap arr[pLeft] and arr[pRight]
                arr[pLeft], arr[pRight] = arr[pRight], arr[pLeft]
                pLeft += 1
                pRight -= 1
        quickSort(arr, left, pRight)
        quickSort(arr, pLeft, right)


# arr = [10, 7, 8, 9, 1, 5]
# arr = [10, 30, 80, 90, 40, 50, 70]
# arr = [4, 3, 2, 1]
# arr = [2, 5, 7, 4, 6, 1, 3, 8, 9]
arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
print("arr before sorted ", arr)
quickSort(arr, 0, len(arr) - 1)
print("arr after sorted ", arr)
