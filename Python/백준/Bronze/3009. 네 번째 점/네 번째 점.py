import sys

x1, y1 = map(int, sys.stdin.readline().rstrip().split(' '))
x2, y2 = map(int, sys.stdin.readline().rstrip().split(' '))
x3, y3 = map(int, sys.stdin.readline().rstrip().split(' '))

x_list = [x1, x2, x3]
y_list = [y1, y2, y3]

x_cnt = [x_list.count(x) for x in x_list]
y_cnt = [y_list.count(y) for y in y_list]

x = x_list[x_cnt.index(1)]
y = y_list[y_cnt.index(1)]

print(x, y)
