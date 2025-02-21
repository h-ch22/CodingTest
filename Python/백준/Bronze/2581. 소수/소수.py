import sys

m = int(sys.stdin.readline().rstrip())
n = int(sys.stdin.readline().rstrip())

prime_list = []

for i in range(m, n+1):
    if i == 1:
        continue
        
    is_prime = True

    for j in range(2, i):
        if i % j == 0:
            is_prime = False
            break

    if is_prime:
        prime_list.append(i)

if len(prime_list) > 0:
    print(sum(prime_list))
    print(min(prime_list))

else:
    print(-1)
