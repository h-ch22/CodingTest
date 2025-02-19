nums = list(map(int, input().split(" ")))

if nums.count(nums[0]) == 3:
    print(10000 + nums[0] * 1000)

elif nums.count(nums[0]) == 2 or nums.count(nums[1]) == 2:
    print(1000 + nums[0] * 100 if nums.count(nums[0]) == 2 else 1000 + nums[1] * 100)

else:
    print(max(nums) * 100)