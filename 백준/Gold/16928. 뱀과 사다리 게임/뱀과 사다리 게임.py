import sys
from collections import deque

graph = [0 for _ in range(101)]
visited = [False for _ in range(101)]

def bfs():
    queue = deque([(1, 0)])
    visited[1] = True

    while queue:
        pos, c = queue.popleft()

        if pos == 100:
            print(c)
            break

        for i in range(1, 7):
            pos_n = pos + i

            if 0 < pos_n <= 100:
                if graph[pos_n] != 0:
                    pos_n = graph[pos_n]

                if not visited[pos_n]:
                    visited[pos_n] = True
                    queue.append((pos_n, c + 1))

n, m = map(int, sys.stdin.readline().strip().split())

for i in range(n):
    j, k = map(int, sys.stdin.readline().strip().split())
    graph[j] = k

for i in range(m):
    j, k = map(int, sys.stdin.readline().strip().split())
    graph[j] = k

bfs()
