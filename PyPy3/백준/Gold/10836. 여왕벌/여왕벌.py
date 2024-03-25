import sys
input = sys.stdin.readline
M, N = map(int, input().rstrip().rsplit())
board = [[1] * M for _ in range(M)]

for _ in range(N):
    grow = list(map(int, input().split()))
    day_grow = [[0] * M for _ in range(M)]
    for i in range(M-1, -1, -1):
        if grow[0] > 0:
            day_grow[i][0] = 0
            grow[0] -= 1
        elif grow[1] > 0:
            day_grow[i][0] = 1
            grow[1] -= 1
        elif grow[2] > 0:
            day_grow[i][0] = 2
            grow[2] -= 1
    for i in range(1, M):
        if grow[0] > 0:
            day_grow[0][i] = 0
            grow[0] -= 1
        elif grow[1] > 0:
            day_grow[0][i] = 1
            grow[1] -= 1
        elif grow[2] > 0:
            day_grow[0][i] = 2
            grow[2] -= 1
    for i in range(0, M):
        for j in range(0, M):
            if i == 0 or j == 0:
                board[i][j] += day_grow[i][j]
                continue
            day_grow[i][j] = max(day_grow[i-1][j-1], max(day_grow[i-1][j], day_grow[i][j-1]))
            board[i][j] += day_grow[i][j]

for i in range(M):
    for j in range(M):
        if j == M-1:
            print(board[i][j])
        else:
            print(board[i][j], end=' ')
