# this code is copied from book pemrograman kompetitif
def quickSort(arr, left, right):
    # print("left ", left)
    # print("right ", right)
    # print("partisi arr[left:right+1] ", arr[left:right+1])
    if (left >= right):
        return
    else:
        # menggunakan partisi hoare
        pivot = arr[(left + right) // 2]
        pLeft = left
        pRight = right

        print("pivot ", pivot)

        while pLeft <= pRight:
            print("arr selama pengacakan ", arr)

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
        # print("arr ", arr)
        # print("left ", left)
        # print("pRight ", pRight)
        # print("pLeft ", pLeft)
        # print("right ", right)
        # print("partisi arr[left:pRight+1] ", arr[left:pRight+1])
        # print("partisi arr[pLeft:right+1] ", arr[pLeft:right+1])
        quickSort(arr, left, pRight)
        quickSort(arr, pLeft, right)


# arr = [10, 7, 8, 9, 1, 5]
# arr = [10, 30, 80, 90, 40, 50, 70]
# arr = [4, 3, 2, 1]
arr = [2, 5, 7, 4, 6, 1, 3, 8, 9]
print("arr before sorted ", arr)
quickSort(arr, 0, len(arr) - 1)
print("arr after sorted ", arr)
