def find_primes(n):
    primes = [True for _ in range(n+1)]
    primes[0] = False
    primes[1] = False
    
    for i in range(2, n+1):
        if not primes[i]:
            continue
            
        for j in range(2, n+1):
            if i * j > n:
                break
                
            primes[i*j] = False
            
    return primes

def solution(n):
    p = find_primes(n)
    primes = []
    
    for (i, x) in enumerate(p):
        if x and n % i == 0:
            primes.append(i)
    
    return primes