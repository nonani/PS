N, M = map(int, input().split())

cur = 0
answer = 0
if M == N:
    print(0)
else:
    for i in range(N):
        cur += M
        if cur == N:
            cur = 0
        elif cur > N:
            if cur % N == 0:
                answer += cur // N - 1
            else:
                answer += cur // N
            cur = cur % N
    print(answer)
    

