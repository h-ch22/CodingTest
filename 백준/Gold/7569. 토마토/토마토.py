import sys
from collections import deque

dx, dy, dz = [-1, 1, 0, 0, 0, 0], [0, 0, -1, 1, 0, 0], [0, 0, 0, 0, -1, 1]
queue = deque()

def bfs():
    while queue:
        x, y, z = queue.popleft()

        for i in range(6):
            nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]

            if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
                if graph[nz][ny][nx] == 0:
                    graph[nz][ny][nx] = graph[z][y][x] + 1
                    queue.append((nx, ny, nz))

m, n, h = map(int, sys.stdin.readline().strip().split())
graph = []

for _ in range(h):
    current_floor = []

    for _ in range(n):
        current_floor.append(list(map(int, sys.stdin.readline().strip().split())))

    graph.append(current_floor)

for f in range(h):
    for c in range(n):
        for r in range(m):
            if graph[f][c][r] == 1:
                queue.append((r, c, f))

bfs()
max_days = 0

for f in range(h):
    for c in range(n):
        if 0 in graph[f][c]:
            print(-1)
            exit()

        max_day = max(graph[f][c])
        max_days = max(max_days, max_day)

print(max_days - 1)
