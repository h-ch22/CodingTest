import sys

dp = [1, 3, 5, 11, 21]
n = int(sys.stdin.readline().rstrip())

if len(dp) >= n:
    print(dp[n-1] % 10007)

else:
    for i in range(len(dp), n):
        dp.append(
            dp[-1] * 2 + 1 if i % 2 != 0 else dp[-1] * 2 - 1
        )

    print(dp[-1] % 10007)
