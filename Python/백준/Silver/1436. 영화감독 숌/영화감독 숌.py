import sys

n = int(sys.stdin.readline().rstrip())
num = 666
nums = []

while True:
    if '666' in str(num):
        nums.append(num)

    if len(nums) == n:
        print(nums[n-1])
        break

    num += 1
