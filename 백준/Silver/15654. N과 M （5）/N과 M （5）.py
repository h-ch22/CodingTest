import sys
sys.setrecursionlimit(10**6)

answer = []

def dfs(graph, start):
    if len(answer) == m:
        print(' '.join(map(str, answer)))
        return

    for i in range(start, len(graph)):
        if graph[i] not in answer:
            answer.append(graph[i])
            dfs(graph, 0)
            answer.pop()

n, m = map(int, sys.stdin.readline().strip().split())
graph = list(map(int, sys.stdin.readline().strip().split()))
graph.sort()
dfs(graph, 0)
