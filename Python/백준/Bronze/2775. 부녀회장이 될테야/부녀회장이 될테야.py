import sys

t = int(sys.stdin.readline().rstrip())

for _ in range(t):
    k = int(sys.stdin.readline().rstrip())
    n = int(sys.stdin.readline().rstrip())

    residents = { i: i for i in range(1, n+1) }

    for i in range(k):
        for j in range(2, n+1):
            residents[j] += residents[j-1]

    print(residents[n])
