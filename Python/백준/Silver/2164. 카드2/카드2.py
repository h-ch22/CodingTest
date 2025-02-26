import sys
from collections import deque

n = int(sys.stdin.readline().rstrip())
nums = deque([i+1 for i in range(n)])
i = 0

while True:
    if len(nums) == 1:
        print(nums[0])
        break

    current = nums.popleft()

    if (i + 1) % 2 == 0:
        nums.append(current)

    i += 1
