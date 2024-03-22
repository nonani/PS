n, m = input().split()
n, m = int(n), float(m)
m*=100
m+=0.5
m = int(m)

while n != 0 or m != 0:
    dp = [0] * 10001
    for i in range(n):
        a, b = input().split()
        a, b = int(a), float(b)
        b*=100
        b+=0.5
        b = int(b)
        for j in range(b, m + 1):
            dp[j] = max(dp[j], dp[j - b] + a)
    print(dp[m])
    n, m = input().split()
    n, m = int(n), float(m)
    m *= 100
    m+=0.5
    m = int(m)