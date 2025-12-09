import sys

n, c = map(int, sys.stdin.readline().strip().split())
coords = []

for _ in range(n):
    coords.append(int(sys.stdin.readline().strip()))

coords.sort()

start, end = 1, (coords[-1] - coords[0])

while start <= end:
    mid = (start + end) // 2
    cnt = 1
    current_coords = coords[0]

    for i in range(1, len(coords)):
        if coords[i] >= current_coords + mid:
            cnt += 1
            current_coords = coords[i]

    if cnt >= c:
        start = mid + 1

    else:
        end = mid - 1

print(end)
