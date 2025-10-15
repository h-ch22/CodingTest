def solution(array, n):
    answer = 0
    
    array = sorted(array)
    
    if array[-1] <= n:
        answer = array[-1]
        
    elif array[0] >= n:
        answer = array[0]
        
    else:
        for i in range(len(array)):
            if array[i] <= n <= array[i+1]:
                if abs(array[i] - n) <= abs(array[i+1] - n):
                    answer = array[i]
                
                else:
                    answer = array[i+1]
                    
                break
                    
    return answer