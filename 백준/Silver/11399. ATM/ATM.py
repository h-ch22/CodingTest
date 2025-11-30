import sys

n = int(sys.stdin.readline().strip())
times = list(map(int, sys.stdin.readline().strip().split()))
times.sort()

for i, t in enumerate(times):
    if i > 0:
        times[i] += times[i-1]

print(sum(times))
