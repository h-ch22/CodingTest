import sys

n, m = map(int, sys.stdin.readline().rstrip().split())
nums = list(map(int, sys.stdin.readline().rstrip().split()))
prefixes = [0] * (n + 1)

for i in range(1, n+1):
    prefixes[i] = prefixes[i-1] + nums[i-1]

for _ in range(m):
    start, end = map(int, sys.stdin.readline().rstrip().split())
    print(prefixes[end] - prefixes[start - 1])
