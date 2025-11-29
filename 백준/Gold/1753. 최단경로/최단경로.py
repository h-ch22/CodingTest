import math
import sys
import heapq

def dijkstra(graph, start, distances):
    queue = []
    heapq.heappush(queue, (0, start))
    distances[start] = 0

    while queue:
        d, n = heapq.heappop(queue)

        if distances[n] < d:
            continue

        for node in graph[n]:
            weight, next = node[0], node[1]

            cost = d + weight

            if cost < distances[next]:
                distances[next] = cost
                heapq.heappush(queue, (cost, next))


v, e = map(int, sys.stdin.readline().strip().split())
k = int(sys.stdin.readline().strip())
distances = [math.inf] * (v + 1)
graph = [[] for _ in range(v + 1)]

for _ in range(e):
    start, end, weight = map(int, sys.stdin.readline().strip().split())
    graph[start].append((weight, end))

dijkstra(graph, k, distances)

for d in range(1, v + 1):
    if distances[d] == math.inf:
        print('INF')

    else:
        print(distances[d])
