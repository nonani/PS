import heapq
pq = []
N = int(input())
answer = 0

for i in range(N):
    x = int(input())
    heapq.heappush(pq, x)
while len(pq) > 1:
    a = heapq.heappop(pq)
    b = heapq.heappop(pq)
    num = a + b
    answer += num
    heapq.heappush(pq, num)

print(answer)
