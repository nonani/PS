answer = 0
def dfs(cur):
    global ad, hp, answer, N
    cnt = 0
    for i in range(N):
        if hp[i] <= 0:
            cnt+=1
        answer = max(cnt, answer)
    if cur > N - 1:
        return
    elif hp[cur] <= 0:
        return dfs(cur+1)
    else:
        for i in range(N):
            if i != cur and hp[i] > 0:
                hp[i] -= ad[cur]
                hp[cur] -= ad[i]
                dfs(cur+1)
                hp[i] += ad[cur]
                hp[cur] += ad[i]





N = int(input())
ad = [0] * N
hp = [0] * N

for i in range(N):
    hp[i], ad[i] = map(int, input().split())

dfs(0)
print(answer)