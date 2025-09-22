def solution(nums):
    answer = 0
    ponkemons = {}
    
    for n in nums:
        if n in ponkemons.keys():
            ponkemons[n] += 1
            
        else:
            ponkemons[n] = 1
            
    if len(list(ponkemons.keys())) <= len(nums) // 2:
        answer = len(list(ponkemons.keys()))
        
    else:
        answer = len(nums) // 2
        
    return answer
    