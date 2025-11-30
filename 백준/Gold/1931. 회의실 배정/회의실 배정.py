import sys

n = int(sys.stdin.readline().strip())
available = 1
times = []

for _ in range(n):
    start, end = map(int, sys.stdin.readline().strip().split())
    times.append((start, end))

times = sorted(times, key=lambda x: (x[1], x[0]))
end = times[0][1]

for i in range(1, n):
    if times[i][0] >= end:
        end = times[i][1]
        available += 1
        
print(available)
