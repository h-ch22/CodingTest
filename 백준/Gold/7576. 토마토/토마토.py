import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
queue = deque()
m, n = map(int, sys.stdin.readline().strip().split())
graph = []
is_all_ripen = True

for _ in range(n):
    g = list(map(int, sys.stdin.readline().strip().split()))
    graph.append(g)

    if g.count(1) != m:
        is_all_ripen = False

if is_all_ripen:
    print(0)
    sys.exit()

for y in range(n):
    for x in range(m):
        if graph[y][x] == 1:
            queue.append((x, y))

while queue:
    x, y = queue.popleft()

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if nx < 0 or ny < 0 or nx >= m or ny >= n:
            continue

        if graph[ny][nx] != 0:
            continue

        if graph[ny][nx] == 0:
            graph[ny][nx] = graph[y][x] + 1
            queue.append((nx, ny))

max_day = -1

for y in range(n):
    for x in range(m):
        if graph[y][x] == 0:
            print(-1)
            sys.exit()

        if graph[y][x] > max_day:
            max_day = graph[y][x]

print(max_day - 1)
