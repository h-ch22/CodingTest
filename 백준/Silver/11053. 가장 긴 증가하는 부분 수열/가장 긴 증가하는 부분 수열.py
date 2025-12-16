import sys

n = int(sys.stdin.readline().strip())
sequence = list(map(int, sys.stdin.readline().strip().split()))

d = [1] * n

for i in range(1, n):
    for j in range(i):
        if sequence[j] < sequence[i]:
            d[i] = max(d[i], d[j] + 1)
            
print(max(d))
