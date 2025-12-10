import sys

"""
3 -> 1 (3kg 1봉지)
4 -> -1
5 -> 1 (5kg 1봉지)

6 -> 2 (3kg 2봉지)
7 -> -1
8 -> 2 (3kg 1봉지 + 5kg 1봉지)

9 -> 3 (3kg 3봉지)
10 -> 2 (5kg 2봉지)
11 -> 3 (3kg 2봉지 + 5kg 1봉지)

12 -> 4 (3kg 4봉지)
13 -> -1
15 -> 3 (5kg 3봉지)

if n % 3 == 0 or n % 5 == 0 -> return n // 3 or n // 5
else -> min(arr[n-3], arr[n-5]) + 1
"""

n = int(sys.stdin.readline().strip())
dp = [9999] * (n + 5)

dp[3] = 1
dp[5] = 1

for i in range(6, n + 1):
    dp[i] = min(dp[i - 3], dp[i - 5]) + 1

if dp[n] >= 9999:
    print(-1)

else:
    print(dp[n])
