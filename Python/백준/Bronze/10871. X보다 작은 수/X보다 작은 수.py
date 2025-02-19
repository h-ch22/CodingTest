import sys

n, x = list(map(int, sys.stdin.readline().rstrip().split(" ")))
nums = list(map(int, sys.stdin.readline().rstrip().split(" ")))
nums = list(filter(lambda v: v < x, nums))

for v in nums:
    print(v, end=" ")
