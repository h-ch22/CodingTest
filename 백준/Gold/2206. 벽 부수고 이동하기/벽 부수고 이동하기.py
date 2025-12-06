import sys
from collections import deque
from heapq import nlargest

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs():
    queue = deque([(0, 0, 0)])
    visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
    visited[0][0][0] = 1

    while queue:
        x, y, broken = queue.popleft()

        if x == m - 1 and y == n - 1:
            return visited[y][x][broken]

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < m and 0 <= ny < n:
                if graph[ny][nx] == 0 and visited[ny][nx][broken] == 0:
                    visited[ny][nx][broken] = visited[y][x][broken] + 1
                    queue.append((nx, ny, broken))

                elif graph[ny][nx] == 1 and broken == 0:
                    if visited[ny][nx][1] == 0:
                        visited[ny][nx][1] = visited[y][x][0] + 1
                        queue.append((nx, ny, 1))

    return -1

n, m = map(int, sys.stdin.readline().strip().split())
graph = []

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().strip())))

print(bfs())
