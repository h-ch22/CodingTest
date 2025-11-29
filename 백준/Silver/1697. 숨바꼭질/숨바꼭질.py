import sys
from collections import deque

def bfs(start, visited, destination):
    queue = deque()
    queue.append(start)

    while queue:
        start = queue.popleft()

        if start == destination:
            print(visited[start])
            break

        for i in (start - 1, start + 1, start * 2):
            if 0 <= i <= 100000 and not visited[i]:
                visited[i] = visited[start] + 1
                queue.append(i)

n, k = map(int, sys.stdin.readline().strip().split())
visited = [0] * 100001

bfs(n, visited, k)
