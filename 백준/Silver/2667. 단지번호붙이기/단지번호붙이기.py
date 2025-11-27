import sys
from collections import deque

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque([(x, y)])
    graph[x][y] = 0
    count = 1

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue

            if graph[nx][ny] == 0:
                continue

            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                queue.append((nx, ny))
                count += 1

    return count

n = int(sys.stdin.readline().strip())
graph = []
counts = []

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().strip())))

for i in range(n):
    for j in range(n):
        if graph[i][j] == 1:
            counts.append(bfs(i, j))

print(len(counts))
counts = sorted(counts)

for c in counts:
    print(c)
