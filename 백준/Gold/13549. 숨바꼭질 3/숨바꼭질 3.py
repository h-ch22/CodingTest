import sys
from collections import deque

def bfs(graph, start):
    queue = deque([start])

    while queue:
        v = queue.popleft()

        if v == k:
            print(graph[v][0])
            return

        if 0 <= v * 2 <= 100000 and not graph[v * 2][1]:
            graph[v * 2][0] = graph[v][0]
            graph[v * 2][1] = True
            queue.append(v * 2)

        for i in ((v - 1), (v + 1)):
            if 0 <= i <= 100000 and not graph[i][1]:
                graph[i][0] = graph[v][0] + 1
                graph[i][1] = True
                queue.append(i)

n, k = map(int, sys.stdin.readline().strip().split())
graph = [[0, False] for _ in range(100001)]
bfs(graph, n)
