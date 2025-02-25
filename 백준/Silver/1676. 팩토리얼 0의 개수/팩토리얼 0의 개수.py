import sys
from math import factorial

n = int(sys.stdin.readline().rstrip())
fac = factorial(n)
fac = ''.join(reversed(str(fac)))
cnt = 0

for f in fac:
    if f == '0':
        cnt += 1

    else:
        break

print(cnt)
