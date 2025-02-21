import sys

n = int(sys.stdin.readline().rstrip())
x_list, y_list = [], []

for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    x_list.append(x)
    y_list.append(y)

min_x, max_x = min(x_list), max(x_list)
min_y, max_y = min(y_list), max(y_list)

print((max_x - min_x) * (max_y - min_y))
