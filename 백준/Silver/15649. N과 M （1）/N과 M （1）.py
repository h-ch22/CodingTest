import sys
sys.setrecursionlimit(10**6)

def dfs():
    if len(graph) == m:
        print(' '.join(map(str, graph)))
        return

    for i in range(1, n+1):
        if visited[i]:
            continue

        visited[i] = True
        graph.append(i)
        dfs()
        graph.pop()
        visited[i] = False

n, m = map(int, sys.stdin.readline().strip().split())
graph = []
visited = [False] * (n+1)
dfs()
