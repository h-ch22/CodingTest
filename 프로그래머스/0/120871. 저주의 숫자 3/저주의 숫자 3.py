def solution(n):
    nums = []
    num = 1
    
    while len(nums) < n:
        while num % 3 == 0 or num % 10 == 3 or num // 10 == 3 or '3' in str(num):
            num += 1
            
        nums.append(num)
        num += 1
            
    return nums[-1]