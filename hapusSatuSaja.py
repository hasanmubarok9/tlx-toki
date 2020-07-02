A = input()
B = input()

def checkIsAble(A, B):

    if len(A) - len(B) > 1:
        return "Wah, tidak bisa :("

    listA = list(A)
    listB = list(B)

    for i in range(len(listA)):

        if i == len(listA) - 1 and len(listA) - len(listB) == 1:
            listB.insert(len(listB), "$") 

        if listA[i] != listB[i]:
            listB.insert(i, "$")

    if sum([a != b for (a,b) in zip(listA, listB)]) > 1 :
        return "Wah, tidak bisa :("
    else:
        return "Tentu saja bisa!"

print(checkIsAble(A, B))

