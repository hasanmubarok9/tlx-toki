def petakMenarik(board, x):

    attractivenessValues = []

    # get attractiveness value from every element
    for i in range(len(board)):
        for j in range(len(board[i])):
            # handle top row
            if i == 0: top = 1 
            else: top = board[i-1][j]

            # handle rightmost column
            if j == len(board[i]) - 1: right = 1
            else: right = board[i][j+1]

            # handle bottom row
            if i == len(board) - 1: bottom = 1
            else: bottom = board[i+1][j]

            # handle leftmost column
            if j == 0: left = 1
            else: left = board[i][j-1]

            # append to attractivenessValue if result of products equals x
            if x == (top * right * bottom * left): attractivenessValues.append((i, j))

    # handle if data found more than one, pick the smallest column one
    if len(attractivenessValues) > 1:
        minByColumn = min(attractivenessValues, key=lambda x: x[1])
        attractivenessValues = [value for value in attractivenessValues if value[1] == minByColumn[1]]
        # handle if data found more than one, pick the smallest row one
        if len(attractivenessValues) > 1:
            minByRows = min(attractivenessValues, key=lambda x: x[0])
            attractivenessValues = [value for value in attractivenessValues if value[0] == minByRows[0]]
    
    # handle if data attractiveness is not found
    if len(attractivenessValues) == 0:
        return f'{0} {0}'

    return f'{attractivenessValues[0][0] + 1} {attractivenessValues[0][1] + 1}'

if __name__ == "__main__": 
    N, M, X = map(int, input().split())
    board = []
    for _ in range(N):
        board.append(list(map(int, input().split())))

    print(petakMenarik(board, X))