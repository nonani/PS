def recur(i, map):
    s = "--"
    if map == {}:
        return
    key = list(map.keys())
    key.sort()
    for c in key:
        print(s*i+c)
        recur(i+1, map[c])




N = int(input())
map = {}
for i in range(N):
    line_list = input().split()
    num, data = int(line_list[0]), line_list[1:]
    temp = map
    for j in range(len(data)):
        if not data[j] in temp:
            temp[data[j]]={}
        temp =temp[data[j]]
        
        
recur(0, map)