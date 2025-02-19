import sys

n, m = list(map(int, sys.stdin.readline().rstrip().split(" ")))
balls = [0 for _ in range(n)]

for x in range(m):
    i, j, k = list(map(int, sys.stdin.readline().rstrip().split(" ")))

    for y in range(i - 1, j):
        balls[y] = k

for ball in balls:
    print(ball, end=" ")