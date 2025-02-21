import sys

t = int(sys.stdin.readline().rstrip())
units = [25, 10, 5, 1]

for _ in range(t):
    changes = [0, 0, 0, 0]
    n = int(sys.stdin.readline().rstrip())

    for i, u in enumerate(units):
        changes[i] += (n // u)
        n -= u * (n // u)
        n = round(n, 3)

    for c in changes:
        print(c, end=' ')