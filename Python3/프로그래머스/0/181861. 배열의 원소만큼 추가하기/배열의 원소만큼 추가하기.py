def solution(arr):
    x = []
    
    for a in arr:
        [x.append(a) for _ in range(a)]
            
    return x