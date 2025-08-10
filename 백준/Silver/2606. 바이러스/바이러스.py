import sys
from collections import deque

dfs_visited = []
def dfs(v: int, graph: dict[int, list[int]]):
    dfs_visited.append(v)

    if v in graph.keys():
        for nxt in graph[v]:
            if nxt not in dfs_visited:
                dfs(nxt, graph)

n = int(sys.stdin.readline().rstrip())
m = int(sys.stdin.readline().rstrip())
graph: dict[int, list[int]] = {}

for _ in range(m):
    l, r = map(int, sys.stdin.readline().rstrip().split())

    if l in graph.keys():
        graph[l].append(r)

    else:
        graph[l] = [r]

    if r in graph.keys():
        graph[r].append(l)
    else:
        graph[r] = [l]

for k in graph.keys():
    graph[k].sort()

bfs_visited = []
q = deque([1])
bfs_visited.append(1)

while q:
    v = q.popleft()

    if v in graph.keys():
        for nxt in graph[v]:
            if nxt not in bfs_visited:
                bfs_visited.append(nxt)
                q.append(nxt)

print(len(bfs_visited) - 1)
