def guess_the_answer(arr, guess, left, right):
    mid = (left + right) // 2
    if left == right:
        return mid + 1
    else:
        # the key for this answer is here
        if guess <= arr[mid]:
            return guess_the_answer(arr, guess, left, mid)
        elif arr[mid] < guess:
            return guess_the_answer(arr, guess, mid+1, right)


if __name__ == "__main__":
    # number of input
    n = int(input())

    # array for save boundary for every group of cattle
    queue = []

    # variable to flag boundary
    boundary = 0
    for i in range(n):
        boundary += int(input())
        queue.append(boundary)

    answer = []
    # number of guesses
    q = int(input())
    for i in range(q):
        guess = int(input())
        res = guess_the_answer(queue, guess, 0, n-1)
        answer.append(res)

    for ans in answer:
        print(ans)
