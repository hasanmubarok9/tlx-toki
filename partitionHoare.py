# partisi Hoare
def partition(arr, left, right, pivot):
    pLeft = left
    pRight = right
    while pLeft <= pRight:
        while arr[pLeft] <= pivot:
            pLeft += 1
        while arr[pRight] > pivot:
            pRight -= 1

        if pLeft <= pRight:
            # swap arr[pLeft] and arr[pRight]
            arr[pLeft], arr[pRight] = arr[pRight], arr[pLeft]
            pLeft += 1
            pRight -= 1


arr = [2, 5, 7, 4, 6, 1, 3, 8, 9]
# select middle element as pivot
mid = (len(arr) // 2)
# pivot = arr[mid]
pivot = 5
partition(arr, 0, len(arr) - 1, pivot)
print(arr)