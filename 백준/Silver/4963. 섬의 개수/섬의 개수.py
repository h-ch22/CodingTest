import sys
from collections import deque

graph = []
dx, dy = [-1, 1, 0, 0, -1, 1, -1, 1], [0, 0, -1, 1, -1, 1, 1, -1]

def bfs(x, y):
    queue = deque([(x, y)])
    graph[y][x] = 0

    while queue:
        x, y = queue.popleft()

        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < w and 0 <= ny < h:
                if graph[ny][nx] == 1:
                    graph[ny][nx] = 0
                    queue.append((nx, ny))

while True:
    graph = []
    w, h = map(int, sys.stdin.readline().strip().split())
    islands = 0

    if w == 0 and h == 0:
        break

    for _ in range(h):
        graph.append(list(map(int, sys.stdin.readline().strip().split())))

    for i in range(h):
        for j in range(w):
            if graph[i][j] == 1:
                islands += 1
                bfs(j, i)

    print(islands)
