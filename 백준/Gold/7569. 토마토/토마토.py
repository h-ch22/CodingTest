import sys
from collections import deque

m, n, h = map(int, sys.stdin.readline().strip().split())
graph = []
dx, dy, dz = [-1, 1, 0, 0, 0, 0], [0, 0, -1, 1, 0, 0], [0, 0, 0, 0, -1, 1]
queue = deque([])

def bfs():
    while queue:
        x, y, z = queue.popleft()

        for i in range(6):
            nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]

            if 0 <= nx < m and 0 <= ny < n and 0 <= nz < h:
                if graph[nz][ny][nx] == 0:
                    graph[nz][ny][nx] = graph[z][y][x] + 1
                    queue.append((nx, ny, nz))

for _ in range(h):
    current_floor = []

    for _ in range(n):
        current_floor.append(list(map(int, sys.stdin.readline().strip().split())))

    graph.append(current_floor)

for z in range(h):
    for y in range(n):
        for x in range(m):
            if graph[z][y][x] == 1:
                queue.append((x, y, z))

bfs()

max_days = 0

for i in range(h):
    for j in range(n):
        if 0 in graph[i][j]:
            print(-1)
            exit()

        max_d = max(graph[i][j])
        max_days = max(max_days, max_d)

print(max_days - 1)
