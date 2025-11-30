import sys

n = int(sys.stdin.readline().strip())
coords = []

for _ in range(n):
    coords.append(list(map(int, sys.stdin.readline().strip().split())))

coords = sorted(coords, key=lambda x: (x[0], x[1]))

for c in coords:
    print(c[0], c[1])
