import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs(x, y, visited):
    queue = deque([(x, y)])
    visited[y][x] = 0

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < m and 0 <= ny < n and visited[ny][nx] == -1:
                if graph[ny][nx] == 1:
                    visited[ny][nx] = visited[y][x] + 1
                    queue.append((nx, ny))

                elif graph[ny][nx] == 0:
                    visited[ny][nx] = 0

n, m = map(int, sys.stdin.readline().strip().split())
graph = []
destination = []

for i in range(n):
    g = list(map(int, sys.stdin.readline().strip().split()))
    graph.append(g)

    try:
        destination = [g.index(2), i]

    except ValueError:
        continue

visited = [[-1 for _ in range(m)] for _ in range(n)]
bfs(destination[0], destination[1], visited)

for y in range(n):
    for x in range(m):
        if visited[y][x] == -1 and graph[y][x] == 0:
            print(0, end=' ')

        else:
            print(visited[y][x], end=' ')

    print()
