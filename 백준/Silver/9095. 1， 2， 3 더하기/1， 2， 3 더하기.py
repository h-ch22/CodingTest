import sys

t = int(sys.stdin.readline().rstrip())
dp = { 0: 1, 1: 1, 2: 2, 3: 4, 4: 7 }

def sum(n):
    idx = list(dp.keys()).index(n)
    return dp[list(dp.keys())[idx]] + dp[list(dp.keys())[idx-1]] + dp[list(dp.keys())[idx-2]]

for _ in range(t):
    n = int(sys.stdin.readline().rstrip())

    if not n in dp.keys():
        for i in range(list(dp.keys())[-1] + 1, n+1):
            dp[i] = sum(i-1)

    print(dp[n])