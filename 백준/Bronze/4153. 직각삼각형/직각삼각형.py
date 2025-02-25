import sys
import math

while True:
    x, y, z = map(int, sys.stdin.readline().rstrip().split(' '))

    if x == 0 and y == 0 and z == 0:
        break

    length = [x, y, z]
    max_l = max(length)
    length.remove(max_l)

    if math.sqrt(length[0] ** 2 + length[1] ** 2) == max_l:
        print('right')

    else:
        print('wrong')
