import sys
from collections import deque

dx, dy = [-1, 1, 0, 0, -1, 1, 1, -1], [0, 0, -1, 1, -1, 1, -1, 1]

def bfs(x, y):
    queue = deque([(x, y)])
    graph[y][x] = 0

    while queue:
        x, y = queue.popleft()

        for i in range(8):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < w and 0 <= ny < h and graph[ny][nx] != 0:
                graph[ny][nx] = 0
                queue.append((nx, ny))

while True:
    w, h = map(int, sys.stdin.readline().strip().split())
    cnt = 0

    if w == 0 and h == 0:
        exit()

    graph = []

    for _ in range(h):
        m = list(map(int, sys.stdin.readline().strip().split()))
        graph.append(m)

    for y in range(h):
        for x in range(w):
            if graph[y][x] == 1:
                cnt += 1
                bfs(x, y)

    print(cnt)
