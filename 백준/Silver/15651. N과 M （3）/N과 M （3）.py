import sys

graph = []

def dfs():
    if len(graph) == m:
        print(' '.join(map(str, graph)))
        return

    for i in range(1, n+1):
        graph.append(i)
        dfs()
        graph.pop()

n, m = map(int, sys.stdin.readline().strip().split())
dfs()
