import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
graph = []

def bfs(x, y):
    queue = deque([(x, y)])
    visited[y][x] = True
    cnt = 0

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < m and 0 <= ny < n and not visited[ny][nx] and graph[ny][nx] != 'X' and graph[ny][nx] != 'I':
                visited[ny][nx] = True

                if graph[ny][nx] == 'P':
                    cnt += 1

                queue.append((nx, ny))

    print(cnt if cnt > 0 else 'TT')


n, m = map(int, sys.stdin.readline().strip().split())

visited = [[False for _ in range(m)] for _ in range(n)]
current_x, current_y = 0, 0

for i in range(n):
    g = list(sys.stdin.readline().strip())
    graph.append(g)

    try:
        current_x, current_y = g.index('I'), i

    except ValueError:
        continue

bfs(current_x, current_y)
