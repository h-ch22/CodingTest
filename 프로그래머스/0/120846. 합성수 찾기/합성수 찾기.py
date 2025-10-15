from math import sqrt

def get_divisors(n: int):
    divisors = []
    d = []
    
    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            d.append(i)
                
    for i in d:
        divisors.append(n // i)
        
    divisors += d
    divisors = sorted(divisors)
    
    return divisors

def solution(n):
    answer = 0

    for i in range(1, n+1):
        if len(get_divisors(i)) >= 3:
            answer += 1
    
    return answer