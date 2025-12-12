import sys

graph = []

def dfs(start):
    if len(graph) == m:
        print(' '.join(map(str, graph)))
        return

    for i in range(start, n + 1):
        graph.append(i)
        dfs(i)
        graph.pop()

n, m = map(int, sys.stdin.readline().strip().split())
dfs(1)
