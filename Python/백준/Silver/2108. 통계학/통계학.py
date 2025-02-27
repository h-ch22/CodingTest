import sys

from collections import Counter

def round_up(n):
    if n < 0:
        return round_up(-n)

    if n - int(n) >= 0.5:
        return int(n) + 1

    return int(n)

n = int(sys.stdin.readline().rstrip())
nums = []

for _ in range(n):
    nums.append(int(sys.stdin.readline().rstrip()))

print(round_up(sum(nums) / n) if sum(nums) / n > 0 else -1 * (round_up(sum(nums) / n)))
nums.sort()

mid = n // 2
print(nums[mid])

if n == 1:
    print(nums[0])

else:
    counter = Counter(nums)

    if len(counter.values()) == 1:
        print(list(counter.keys())[0])

    else:
        counter = sorted(counter.items(), key=lambda item: item[1], reverse=True)

        if counter[0][1] != counter[1][1]:
            print(counter[0][0])

        else:
            common = counter[0][1]
            counter = [(k, v) for k, v in counter if v == common]
            counter.sort(key=lambda item: item[0])
            print(counter[1][0])

print(max(nums) - min(nums))
