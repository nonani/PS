import sys

input = sys.stdin.readline

craineNum = int(input()) #크레인 개수 입력
craineLimit = list(map(int, input().split()))

boxNum = int(input())
boxInfo = list(map(int, input().split()))

craineLimit.sort(reverse=True)
boxInfo.sort(reverse=True)
if craineLimit[0] < boxInfo[0]:
    print(-1)
else:
    answer = 0
    while boxInfo:
        answer+=1
        for craine in craineLimit:
            if boxInfo and craine < boxInfo[-1]:
                continue
            for i in range(len(boxInfo)):
                if craine >= boxInfo[i]:
                    boxInfo.pop(i)
                    break

    print(answer)

