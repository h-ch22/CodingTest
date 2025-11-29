import sys
sys.setrecursionlimit(2000)

def dfs(graph, start, visited):
    visited[start] = True

    for x in graph[start]:
        if not visited[x]:
            dfs(graph, x, visited)


n, m = map(int, sys.stdin.readline().strip().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    u, v = map(int, sys.stdin.readline().strip().split())
    graph[u].append(v)
    graph[v].append(u)

visited = [False] * (n+1)
count = 0

while True:
    if visited.count(False) == 1:
        print(count)
        break

    dfs(graph, visited.index(False, 1), visited)
    count += 1
