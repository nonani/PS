dict = {}
for i in range(0,26):
    dict[chr(65+i)] = i+1

input = input()
answer = 0
for i in range(len(input)):
    answer += dict[input[i]]*pow(26, len(input)-1-i)
print(answer)

    
