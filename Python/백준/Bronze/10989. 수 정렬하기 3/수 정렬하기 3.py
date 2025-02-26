import sys

# 계수 정렬 사용

count = [0] * 10001

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    num = int(sys.stdin.readline().rstrip())
    count[num] += 1

for i, c in enumerate(count):
    if c != 0:
        for _ in range(c):
            print(i)