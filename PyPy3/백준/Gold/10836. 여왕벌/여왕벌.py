import sys
input = sys.stdin.readline
M, N = map(int, input().split())
board = [[1] * M for _ in range(M)]

for _ in range(N):
    a,b,c = map(int, input().split())
    grow = [0]*(2*M-1)
    for idx in range(a,a+b):
        grow[idx] += 1
    for idx in range(a+b,2*M-1):
        grow[idx] += 2
    for i in range(M) :
        board[-1 - i][0] += grow[i]
    for i in range(M, 2*M-1) :
        board[0][i+1-M] += grow[i]
for i in range(M) :
    for j in range(M) :
        if i == 0 or j == 0 :
            if j == M-1 :
                print(board[i][j])    
            else:
                print(board[i][j], end = ' ')
        elif j != M-1 :
            print(board[0][j], end = ' ')
        else : print(board[0][j])
