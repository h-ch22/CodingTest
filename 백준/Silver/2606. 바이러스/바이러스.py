import sys

def dfs(graph, start, visited):
    visited[start] = 1

    for node in graph[start]:
        if visited[node] == 0:
            dfs(graph, node, visited)

n = int(sys.stdin.readline().strip())
m = int(sys.stdin.readline().strip())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, sys.stdin.readline().strip().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [0] * (n+1)
dfs(graph, 1, visited)
print(sum(visited) - 1)
