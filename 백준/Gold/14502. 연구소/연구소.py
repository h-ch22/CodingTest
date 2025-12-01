import sys
from collections import deque

dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
result = 0

empty_spaces = []
viruses = []
graph = []

n, m = map(int, sys.stdin.readline().strip().split())

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().strip().split())))

for i in range(n):
    for j in range(m):
        if graph[i][j] == 0:
            empty_spaces.append((i, j))
        elif graph[i][j] == 2:
            viruses.append((i, j))


def bfs():
    global result

    temp_graph = [row[:] for row in graph]

    queue = deque(viruses)

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if 0 <= nx < n and 0 <= ny < m:
                if temp_graph[nx][ny] == 0:
                    temp_graph[nx][ny] = 2
                    queue.append((nx, ny))

    count = 0
    for row in temp_graph:
        count += row.count(0)

    result = max(result, count)


def create_wall(count, start_idx):
    if count == 3:
        bfs()
        return

    for i in range(start_idx, len(empty_spaces)):
        r, c = empty_spaces[i]

        graph[r][c] = 1
        create_wall(count + 1, i + 1)
        graph[r][c] = 0


create_wall(0, 0)
print(result)