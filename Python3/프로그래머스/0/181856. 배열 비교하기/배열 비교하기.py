def solution(arr1, arr2):
    if len(arr1) != len(arr2):
        return 1 if len(arr1) > len(arr2) else -1
    
    else:
        sum_a = sum(arr1)
        sum_b = sum(arr2)
        
        if sum_a == sum_b:
            return 0
        
        else:
            return 1 if sum_a > sum_b else -1
