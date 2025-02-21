import sys

n = int(sys.stdin.readline().rstrip())

for i in range(0, n):
    if i + sum(map(int, str(i))) == n:
        print(i)
        sys.exit(0)

print(0)
