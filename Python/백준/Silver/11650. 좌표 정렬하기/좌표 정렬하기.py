import sys

n = int(sys.stdin.readline().rstrip())
coords = []

for _ in range(n):
    coords.append(list(map(int, sys.stdin.readline().rstrip().split(" "))))

coords.sort()

for coord in coords:
    print(coord[0], coord[1])