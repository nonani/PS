def dfs(x, y, n, result, oper, answer):
    global visited, N, M, data, a
    if str.isdigit(data[y][x]):
        result += oper * int(data[y][x])
        answer += str(y)+' '+str(x)+'\n'
        n+=1
        if n == M:
            if result == N:
                a = answer
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if xx >=0 and yy >=0 and xx < 3 and yy < 3 and not visited[yy][xx]:
                visited[yy][xx] = True
                dfs(xx, yy, n, result, oper, answer)
                visited[yy][xx] = False
    else:
        if data[y][x] == '+':
            oper = 1
        else:
            oper = -1
        for i in range(4):
            xx = x + dx[i]
            yy = y + dy[i]
            if xx >=0 and yy >=0 and xx < 3 and yy < 3 and not visited[yy][xx] :
                visited[yy][xx] = True
                dfs(xx, yy, n, result, oper, answer+str(y)+' '+str(x)+'\n')
                visited[yy][xx] = False

        


N, M = map(int, input().split())
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
a = ''
data = []
visited = [[False, False, False],
           [False, False, False],
           [False, False, False]]
# print(visited)
for i in range(3):
    data.append(list(input()))
for x, y in [(0, 0), (0, 2), (1, 1), (2, 0), (2, 2)]:
    # if a == '':
    visited[y][x] = True
    dfs(x, y, 0, 0, 1, '')
    visited[y][x] = False
if a == '':
    print(0)
else:
    print(1)
    print(a, end='')
    # and a == ''