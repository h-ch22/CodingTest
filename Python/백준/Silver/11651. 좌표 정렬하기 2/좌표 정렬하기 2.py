import sys

n = int(sys.stdin.readline().rstrip())
arr = []

for _ in range(n):
    x, y = map(int, sys.stdin.readline().rstrip().split(" "))
    arr.append([x, y])

arr.sort(key=lambda x: (x[1], x[0]))

for a in arr:
    print(a[0], a[1])
