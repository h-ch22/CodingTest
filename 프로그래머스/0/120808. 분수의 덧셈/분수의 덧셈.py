def gcd(num1, num2):
    r = num1 % num2
    
    if r == 0:
        return num2
    
    return gcd(num2, r)

def solution(numer1, denom1, numer2, denom2):
    answer = []
    denom = denom1 * denom2
    number = (numer1*denom2) + (numer2*denom1)
    
    answer = [number // gcd(number, denom), denom // gcd(number, denom)]
    return answer