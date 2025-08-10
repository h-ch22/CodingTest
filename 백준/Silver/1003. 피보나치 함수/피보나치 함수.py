import sys

nums = {
    0: [1, 0],
    1: [0, 1]
}

t = int(sys.stdin.readline().rstrip())
for _ in range(t):
    n = int(sys.stdin.readline().rstrip())

    if n - 1 in nums.keys() and n - 2 in nums.keys():
        nums[n] = [nums[n-1][0] + nums[n-2][0], nums[n-1][1] + nums[n-2][1]]

    else:
        for i in range(list(nums.keys())[-1] + 1, n+1):
            nums[i] = [nums[i-1][0] + nums[i-2][0], nums[i-1][1] + nums[i-2][1]]

    print(f'{nums[n][0]} {nums[n][1]}')
