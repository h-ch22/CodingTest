import sys

n, m = map(int, sys.stdin.readline().strip().split())
print('Yes' if 100 * n >= m else 'No')
