import heapq

class edge:
    def __init__(self, start, end, cost):
        self.start = start
        self.end = end
        self.cost = cost
    def __lt__(self, other):
        return self.cost < other.cost


V, E = map(int, input().split())
graph = {i: [] for i in range(1, V+1)}
visited = [False for _ in range(V+1)]
cnt = 0
answer = 0
min_edge = edge(1, 1, 0)
for _ in range(E):
    A, B, C = map(int, input().split())
    graph[A].append((B, C))
    graph[B].append((A, C))



edges = [min_edge]

while edges and cnt != V:
    
    cur = heapq.heappop(edges)
  
    # print(cur.start, cur.end, cur.cost, answer)

    if not visited[cur.end]:
        answer += cur.cost
        cnt+=1
        visited[cur.end] = True
       
        for e in graph[cur.end]:
                heapq.heappush(edges, edge(cur.end, e[0], e[1]))


print(answer)

    
