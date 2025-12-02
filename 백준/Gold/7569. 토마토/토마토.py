import sys
from collections import deque

dx, dy, dz = [-1, 1, 0, 0, 0, 0], [0, 0, -1, 1, 0, 0], [0, 0, 0, 0, -1, 1]
m, n, h = map(int, sys.stdin.readline().strip().split())
graph = []
queue = deque()

for i in range(h):
    current_floor = []

    for j in range(n):
        g = list(map(int, sys.stdin.readline().strip().split()))

        for k in range(m):
            if g[k] == 1:
                queue.append((i, j, k))

        current_floor.append(g)

    graph.append(current_floor)

def bfs():
    while queue:
        z, x, y = queue.popleft()

        for i in range(6):
            nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]

            if 0 <= nx < n and 0 <= ny < m and 0 <= nz < h:
                if graph[nz][nx][ny] == 0:
                    graph[nz][nx][ny] = graph[z][x][y] + 1
                    queue.append((nz, nx, ny))

bfs()
max_days = 0

for i in range(h):
    for j in range(n):
        for k in range(m):
            if graph[i][j][k] == 0:
                print(-1)
                exit()

            max_days = max(max_days, graph[i][j][k])

print(max_days - 1)
