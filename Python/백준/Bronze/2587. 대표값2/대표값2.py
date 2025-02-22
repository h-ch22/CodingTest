import sys

nums = []

for _ in range(5):
    nums.append(
        int(sys.stdin.readline().rstrip())
    )

nums.sort()
print(int(sum(nums) / 5))
print(nums[2])
