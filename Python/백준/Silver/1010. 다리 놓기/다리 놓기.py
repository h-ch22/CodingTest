def fact(n):
    num = 1

    for i in range(1, n+1):
        num *= i

    return num

T = int(input())

for _ in range(0, T):
    N, M = map(int, input().split())
    bridge = fact(M) // (fact(N) * fact(M - N))

    print(bridge)
