import sys

cases = {
    1: 1,
    2: 2,
    3: 3
}

n = int(sys.stdin.readline().rstrip())

if not n in cases.keys():
    for i in range(list(cases.keys())[-1] + 1, n+1):
        cases[i] = cases[i-1] + cases[i-2]

print(cases[n] % 10007)
