import sys
import heapq
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

n = int(sys.stdin.readline().strip())
m = int(sys.stdin.readline().strip())
graph = [[] for _ in range(n + 1)]
distances = [math.inf] * (n + 1)

for _ in range(m):
    u, v, w = map(int, sys.stdin.readline().strip().split())
    graph[u].append((v, w))

start, end = map(int, sys.stdin.readline().strip().split())
dijkstra(start, graph, distances)
print(distances[end])
