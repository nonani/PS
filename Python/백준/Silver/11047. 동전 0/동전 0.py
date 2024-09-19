N, K = map(int, input().split())
l = []
for _ in range(N):
    l.append(int(input()))
l.sort(reverse=True)
# print(l)
answer = 0
while K > 0:
    for n in l:
        if n <= K:
            answer += K // n
            K = K % n
            break

print(answer)
    