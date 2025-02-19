import sys

n = int(sys.stdin.readline().rstrip())
nums = sys.stdin.readline().rstrip()
sum = 0

for n in nums:
    sum += int(n)

print(sum)