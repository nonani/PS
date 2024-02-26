N, M, H = map(int, input().split())

block = []
for i in range(N):
    block.append([0])
    block[i] +=list(map(int, input().split()))
# print(block)
dp = [[0]*(H+1) for _ in range(N+1)]
dp[0][0] = 1
for i in range(N) :
  for h in range(H+1) :
    if dp[i][h] :
      for j in block[i] :
        if h + j <= H :
          dp[i+1][h + j] = (dp[i][h] + dp[i+1][h + j] ) % 10007
print(dp[-1][-1])
