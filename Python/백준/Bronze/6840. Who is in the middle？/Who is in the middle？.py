import sys

a = int(sys.stdin.readline().rstrip())
b = int(sys.stdin.readline().rstrip())
c = int(sys.stdin.readline().rstrip())

min_num = min(a, b, c)
max_num = max(a, b, c)
mid_num = a + b + c - min_num - max_num

print(mid_num)
