import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs(x, y):
    queue = deque([(x, y)])
    current_color = graph[x][y]

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and graph[nx][ny] == current_color:
                visited[nx][ny] = True
                queue.append((nx, ny))

n = int(sys.stdin.readline().strip())
graph = []
visited = [[False] * n for _ in range(n)]

for _ in range(n):
    graph.append(list(sys.stdin.readline().strip()))

normal = 0

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            normal += 1
            bfs(i, j)

blind = 0
visited = [[False] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if graph[i][j] == 'R':
            graph[i][j] = 'G'

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            blind += 1
            bfs(i, j)

print(normal, blind)
