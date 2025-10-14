def get_gcd(a: int, b: int):
    r = a % b
    
    if r == 0:
        return b
    
    return get_gcd(b, r)

def solution(n):
    return ((6 * n) / get_gcd(n, 6)) // 6