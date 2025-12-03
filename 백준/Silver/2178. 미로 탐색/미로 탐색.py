import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs(x, y):
    queue = deque([(x, y)])
    visited[y][x] = True

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < m and 0 <= ny < n and graph[ny][nx] != 0 and not visited[ny][nx]:
                graph[ny][nx] = graph[y][x] + 1
                visited[ny][nx] = True
                queue.append((nx, ny))

n, m = map(int, sys.stdin.readline().strip().split())
graph = []

for _ in range(n):
    graph.append(list(map(int, list(sys.stdin.readline().strip()))))

visited = [[False for _ in range(m)] for _ in range(n)]
bfs(0, 0)

max_move = 0
print(graph[n-1][m-1])
