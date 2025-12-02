import sys
from collections import deque

dx, dy, dz = [-1, 1, 0, 0, 0, 0], [0, 0, -1, 1, 0, 0], [0, 0, 0, 0, -1, 1]
m, n, h = map(int, sys.stdin.readline().strip().split())
queue = deque()
graph = []

for i in range(h):
    current_floor = []

    for j in range(n):
        g = list(map(int, sys.stdin.readline().strip().split()))

        for k in range(m):
            if g[k] == 1:
                queue.append((k, j, i))

        current_floor.append(g)

    graph.append(current_floor)

def bfs():
    while queue:
        x, y, z = queue.popleft()

        for i in range(6):
            nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]

            if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
                if graph[nz][ny][nx] == 0:
                    graph[nz][ny][nx] = graph[z][y][x] + 1
                    queue.append((nx, ny, nz))

bfs()
max_days = 0

for z in range(h):
    for y in range(n):
        for x in range(m):
            if graph[z][y][x] == 0:
                print(-1)
                exit()

            max_days = max(max_days, graph[z][y][x])

print(max_days - 1)
