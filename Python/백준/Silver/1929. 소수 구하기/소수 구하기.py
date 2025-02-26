import sys

def find_primes(x, b):
    a = [False, False] + [True] * (b - 1)
    prime_nums = []

    for i in range(2, b+1):
        if a[i]:
            if i >= x:
                prime_nums.append(i)

            for j in range(2*i, n+1, i):
                a[j] = False

    return prime_nums

m, n = map(int, sys.stdin.readline().rstrip().split(' '))
primes = find_primes(m, n)

for p in primes:
    print(p)
