import sys

n, m = list(map(int, sys.stdin.readline().rstrip().split(" ")))
balls = [i+1 for i in range(n)]

for _ in range(m):
    i, j = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    target = balls[i-1]
    balls[i-1] = balls[j-1]
    balls[j-1] = target

for ball in balls:
    print(ball, end=" ")
