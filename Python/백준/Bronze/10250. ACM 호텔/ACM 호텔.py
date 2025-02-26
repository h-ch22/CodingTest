import sys
import math

t = int(sys.stdin.readline().rstrip())

for _ in range(t):
    h, w, n = map(int, sys.stdin.readline().rstrip().split(' '))
    floor = n % h if n % h > 0 else h
    room = int(math.ceil(n / h))

    print(f'{floor}%02d' % room)
