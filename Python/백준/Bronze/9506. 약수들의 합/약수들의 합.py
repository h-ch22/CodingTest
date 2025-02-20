import sys

while True:
    n = int(sys.stdin.readline().rstrip())

    if n == -1:
        break

    nums = []

    for i in range(1, n):
        if n % i == 0:
            nums.append(i)

    nums.sort()

    if sum(nums) == n:
        print(f"{n} = {' + '.join(map(str, nums))}")

    else:
        print(f"{n} is NOT perfect.")
