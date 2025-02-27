import sys

from collections import deque

n, k = map(int, sys.stdin.readline().rstrip().split(' '))
values = deque()

for _ in range(n):
    values.append(int(sys.stdin.readline().rstrip()))

values_sum = 0
coins = 0

while True:
    if k == 0:
        print(coins)
        break

    v = values.pop()

    if v > k:
        continue

    elif v == k:
        values_sum += v
        coins += 1
        k %= v
        continue

    else:
        values_sum += (k // v)
        coins += (k // v)
        k %= v
