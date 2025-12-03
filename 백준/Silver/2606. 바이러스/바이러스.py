import sys
sys.setrecursionlimit(10**6)

result = 0

def dfs(graph, start, visited):
    visited[start] = True
    global result
    result += 1

    for g in graph[start]:
        if not visited[g]:
            dfs(graph, g, visited)

n = int(sys.stdin.readline().strip())
pairs = int(sys.stdin.readline().strip())
graph = [[] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for _ in range(pairs):
    a, b = map(int, sys.stdin.readline().strip().split())
    graph[b].append(a)
    graph[a].append(b)

dfs(graph, 1, visited)
print(result-1)
