import heapq
import sys
import math

def dijkstra(start, graph, distances):
    queue = []
    heapq.heappush(queue, (0, start))
    distances[start] = 0

    while queue:
        d, n = heapq.heappop(queue)

        if distances[n] < d:
            continue

        for i in graph[n]:
            c = d + i[1]

            if c < distances[i[0]]:
                distances[i[0]] = c
                heapq.heappush(queue, (c, i[0]))

n, e = map(int, sys.stdin.readline().strip().split())
distances = [math.inf] * (n + 1)
graph = [[] for _ in range(n + 1)]
start = int(sys.stdin.readline().strip())

for _ in range(e):
    u, v, w = map(int, sys.stdin.readline().strip().split())
    graph[u].append((v, w))

dijkstra(start, graph, distances)

for i in range(1, n + 1):
    if distances[i] == math.inf:
        print('INF')

    else:
        print(distances[i])
