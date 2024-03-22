while True:
    candy = []
    dp = [0] * 10001
    n, m = input().split()
    n, m = int(n), float(m)
    m *= 100
    m+=0.5
    m = int(m)
    if n == 0 and m == 0:
        break
    for i in range(n):
        a, b = input().split()
        a, b = int(a), float(b)
        b*=100
        b+=0.5
        b = int(b)
        candy.append((a, b))
        
    for i in range(1, m + 1):
        for a, b in candy:
            if i - b >= 0:
                dp[i] = max(dp[i], dp[i - b] + a)
    print(dp[m])