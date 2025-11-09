import math

def find_primes(n):
    primes = []
    i = 2

    while True:
        if i ** 2 > n:
            break

        while n % i == 0:
            primes.append(int(i))
            n/=i

        i+=1

    if n > 1 and n not in primes:
        primes.append(int(n))

    primes = sorted(list(set(primes)))

    if all(i in [2, 5] for i in primes):
        return True

    return False

def solution(a, b):
    g = math.gcd(a, b)
    
    if g != 1:
        b //= g

    return 1 if find_primes(b) else 2
