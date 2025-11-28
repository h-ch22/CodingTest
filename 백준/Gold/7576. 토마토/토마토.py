import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
m, n = map(int, sys.stdin.readline().strip().split())

graph = []
queue = deque()
days = 0

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().strip().split())))

for i in range(n):
    for j in range(m):
        if graph[i][j] == 1:
            queue.append((i, j))

while queue:
    x, y = queue.popleft()

    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]

        if nx < 0 or ny < 0 or nx >= n or ny >= m:
            continue

        if graph[nx][ny] == -1 or graph[nx][ny] == 1:
            continue

        if graph[nx][ny] == 0:
            graph[nx][ny] = graph[x][y] + 1
            queue.append((nx, ny))

for row in graph:
    for i in row:
        if i == 0:
            print(-1)
            exit()

    else:
        days = max(days, max(row))

print(days - 1)
