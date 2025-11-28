import sys
from collections import deque

t = int(sys.stdin.readline().strip())
m, n, k = 0, 0, 0
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs(graph, x, y):
    queue = deque([(x, y)])
    graph[x][y] = 0
    result = 1

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n:
                continue

            if graph[nx][ny] == 0:
                continue

            if graph[nx][ny] == 1:
                result += 1
                graph[nx][ny] = 0
                queue.append((nx, ny))

    return result

for _ in range(t):
    m, n, k = map(int, sys.stdin.readline().strip().split())
    graph = [[0 for _ in range(n)] for _ in range(m)]
    results = []

    for _ in range(k):
        x, y = map(int, sys.stdin.readline().strip().split())
        graph[x][y] = 1

    for ix in range(m):
        for iy in range(n):
            if graph[ix][iy] == 1:
                result = bfs(graph, ix, iy)
                results.append(result)

    print(len(results))
