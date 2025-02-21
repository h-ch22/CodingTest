import sys

x, y, w, h  = map(int, sys.stdin.readline().rstrip().split(' '))
l, b, t, r = 0, 0, w, h

diff_x_t = t - x
diff_x_b = b - x
diff_y_l = l - y
diff_y_r = r - y

diff = [abs(t-x), abs(b-x), abs(l-y), abs(r-y)]

print(min(diff))
