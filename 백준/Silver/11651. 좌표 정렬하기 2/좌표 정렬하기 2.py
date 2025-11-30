import sys

n = int(sys.stdin.readline().strip())
coords = []

for _ in range(n):
    x, y = map(int, sys.stdin.readline().strip().split())
    coords.append((x, y))

coords = sorted(coords, key=lambda x: (x[1], x[0]))

for c in coords:
    print(c[0], c[1])
