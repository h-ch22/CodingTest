import sys

n = int(sys.stdin.readline().rstrip())
w, h = 2, 2

for i in range(n):
    w += (w - 1)
    h += (h - 1)

print(w * h)
