import sys
from collections import deque

m, n = map(int, sys.stdin.readline().strip().split())
graph = []
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
queue = deque()

def bfs():
    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < m and 0 <= ny < n and graph[ny][nx] == 0:
                graph[ny][nx] = graph[y][x] + 1
                queue.append((nx, ny))

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().strip().split())))

for c in range(n):
    for r in range(m):
        if graph[c][r] == 1:
            queue.append((r, c))

bfs()
days = 0

for c in range(n):
    if 0 in graph[c]:
        print(-1)
        exit()

    max_d = max(graph[c])
    days = max(days, max_d)

print(days - 1)
