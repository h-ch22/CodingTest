import sys

n = int(sys.stdin.readline().rstrip())
dp = {1 : 0}

def validate(n):
    if n in dp.keys():
        return dp[n]

    if n % 3 == 0 and n % 2 == 0:
        dp[n] = min(validate(n // 3) + 1, validate(n // 2) + 1)

    elif n % 3 == 0:
        dp[n] = min(validate(n // 3) + 1, validate(n - 1) + 1)

    elif n % 2 == 0:
        dp[n] = min(validate(n // 2) + 1, validate(n - 1) + 1)

    else:
        dp[n] = validate(n - 1) + 1

    return dp[n]

print(validate(n))
