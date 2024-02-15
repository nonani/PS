
str = input()
l = [s for s in str]
l.sort(reverse=True)
for s in l:
    print(s, end="")