import sys

def fibonacci(n):
    if nums[n] == -1:
        nums[n] = fibonacci(n - 1) + fibonacci(n - 2)

    return nums[n]

n = int(sys.stdin.readline().rstrip())
nums = [-1 for _ in range(n+1)]
nums[0] = 0
nums[1] = 1

print(fibonacci(n))
