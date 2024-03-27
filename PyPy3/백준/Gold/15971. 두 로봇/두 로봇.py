import heapq


N, A, B = map(int, input().split())
graph = [{} for _ in range(N+1)]
visited = [False for _ in range(N+1)]
dp = [1000000 for _ in range(N+1)]
before_node = [0 for _ in range(N+1)]
q = []
dp[A] = 0

for i in range(N-1):
    a, b, d = map(int, input().split())
    graph[a][b] = d
    graph[b][a] = d
heapq.heappush(q, (0, A))
while len(q) != 0:
    _, a = heapq.heappop(q)
    if a == B:
        break
    visited[a] = True
    for next in graph[a]:
        if not visited[next]:
            d = graph[a][next]
            if dp[next] > dp[a] + d:
                dp[next] = dp[a] + d
                before_node[next] = a
            heapq.heappush(q, (d, next))

max_weight = 0
b = B
while A != b:
    max_weight = max(graph[b][before_node[b]], max_weight)
    b = before_node[b]

print(dp[B] - max_weight)
