import sys

n = sys.stdin.readline().rstrip()
n_reverse = "".join(list(reversed(n)))

print(1 if n == n_reverse else 0)