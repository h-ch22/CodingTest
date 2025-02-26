import sys
import math

# 파이썬의 round함수는 사사오입을 함
# 5에서 반올림할 때 앞자리가 홀수면 올림, 짝수면 내림
def round_up(n):
    if n - math.floor(n) >= 0.5:
        return math.floor(n) + 1

    else:
        return math.floor(n)

n = int(sys.stdin.readline().rstrip())
levels = []

for _ in range(n):
    levels.append(int(sys.stdin.readline().rstrip()))

if n == 0:
    print(0)
    sys.exit()

levels.sort()
r = round_up(n * 0.15)

levels = levels[int(r):n - int(r)]

print(round_up(sum(levels) / len(levels)))