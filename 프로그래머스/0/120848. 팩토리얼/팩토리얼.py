from math import factorial

def solution(n):
    answer = 0
    
    for i in range(1, 11):
        if factorial(i) == n:
            answer = i
            break
            
        elif factorial(i) < n < factorial(i+1):
            answer = i
            break
            
    return answer
    