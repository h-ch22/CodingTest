import sys

a, b = map(int, sys.stdin.readline().split(" "))
nums = []

for i in range(1, a+1):
    if a % i == 0:
        nums.append(i)

nums.sort()

try:
    print(nums[b-1])

except IndexError:
    print(0)
