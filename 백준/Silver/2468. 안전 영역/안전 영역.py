import sys
from collections import deque

n = int(sys.stdin.readline().strip())
graph = []
max_safe_area = 0
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
visited = [[False for _ in range(n)] for _ in range(n)]
height = 0
max_height = 0

def bfs(x, y):
    queue = deque([(x, y)])

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < n and graph[ny][nx] > height and not visited[ny][nx]:
                visited[ny][nx] = True
                queue.append((nx, ny))

for _ in range(n):
    g = list(map(int, sys.stdin.readline().strip().split()))
    max_height = max(max(g), max_height)
    graph.append(g)

for i in range(max_height):
    height = i
    visited = [[False for _ in range(n)] for _ in range(n)]
    safe_area = 0

    for y in range(n):
        for x in range(n):
            if graph[y][x] > height and not visited[y][x]:
                safe_area += 1
                bfs(x, y)

    max_safe_area = max(max_safe_area, safe_area)

print(max_safe_area)
