import sys
sys.setrecursionlimit(10**6)

def dfs(graph, start, visited):
    for g in graph[start]:
        if visited[g] == 0:
            visited[g] = start
            dfs(graph, g, visited)

n = int(sys.stdin.readline().strip())
graph = [[] for _ in range(n+1)]

for i in range(n-1):
    a, b = map(int, sys.stdin.readline().strip().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [0] * (n + 1)
dfs(graph, 1, visited)

for i in range(2, n+1):
    print(visited[i])
