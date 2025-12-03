import sys
from collections import deque

t = int(sys.stdin.readline().strip())
queue = deque()

def bfs(start, end, w, visited):
    queue.append((start))
    visited[start[1]][start[0]] = True

    while queue:
        start = queue.popleft()
        start_x, start_y = start[0], start[1]

        if start_x == end[0] and start_y == end[1]:
            print(graph[start_y][start_x])
            break

        for i in ((start_x + 2, start_y + 1), (start_x + 1, start_y + 2), (start_x - 2, start_y + 1), (start_x - 1, start_y + 2), (start_x + 2, start_y - 1), (start_x + 1, start_y - 2), (start_x - 2, start_y - 1), (start_x - 1, start_y - 2)):
            if 0 <= i[0] < w and 0 <= i[1] < w and not visited[i[1]][i[0]]:
                visited[i[1]][i[0]] = True
                graph[i[1]][i[0]] = graph[start_y][start_x] + 1
                queue.append((i[0], i[1]))

for _ in range(t):
    queue = deque()
    w = int(sys.stdin.readline().strip())
    graph = [[0 for _ in range(w)] for _ in range(w)]

    current_x, current_y = map(int, sys.stdin.readline().strip().split())
    dest_x, dest_y = map(int, sys.stdin.readline().strip().split())
    visited = [[False for _ in range(w)] for _ in range(w)]
    bfs((current_x, current_y), (dest_x, dest_y), w, visited)
