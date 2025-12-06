import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

def bfs():
    queue = set([(0, 0, graph[0][0])])
    count = 1

    while queue:
        x, y, visited = queue.pop()
        count = max(count, len(visited))

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < c and 0 <= ny < r:
                if graph[ny][nx] not in visited:
                    queue.add((nx, ny, visited + graph[ny][nx]))

    print(count)

r, c = map(int, sys.stdin.readline().strip().split())
graph = []

for _ in range(r):
    graph.append(list(sys.stdin.readline().strip()))

bfs()
