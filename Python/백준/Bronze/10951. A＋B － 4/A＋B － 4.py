import sys

while True:
    nums = sys.stdin.readline().rstrip()
    nums = nums.split(" ")

    if len(nums) != 2:
        break

    a, b = nums

    print(int(a) + int(b))