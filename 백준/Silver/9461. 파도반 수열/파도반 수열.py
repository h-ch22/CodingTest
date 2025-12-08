import sys

t = int(sys.stdin.readline().strip())
arr = [0, 1, 1, 1] + [0 for _ in range(97)]

def dp(x):
    if arr[x]:
        return arr[x]

    arr[x] = dp(x - 2) + dp(x - 3)

    return arr[x]

for _ in range(t):
    case = int(sys.stdin.readline().strip())
    print(dp(case))
