import sys

n = int(input())

for i in range(n):
    nums = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    print(nums[0] + nums[1])