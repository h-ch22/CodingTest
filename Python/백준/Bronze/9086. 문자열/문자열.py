import sys

n = int(sys.stdin.readline().rstrip())

for i in range(n):
    s = sys.stdin.readline().rstrip()
    print(f"{s[0]}{s[-1]}")