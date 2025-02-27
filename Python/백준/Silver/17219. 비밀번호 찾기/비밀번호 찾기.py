import sys

passwords = {}

n, m = map(int, sys.stdin.readline().rstrip().split(' '))

for _ in range(n):
    site, password = sys.stdin.readline().rstrip().split(' ')
    passwords[site] = password

for _ in range(m):
    target = sys.stdin.readline().rstrip()
    print(passwords[target])
