def solution(array):
    answer = 0
    
    if len(array) == 1:
        return array[0]
    
    nums = set(array)
    freq = []
    
    for n in nums:
        f = array.count(n)
        freq.append(f)
        
    nums = list(nums)
    
    return nums[freq.index(max(freq))] if freq.count(max(freq)) == 1 else -1