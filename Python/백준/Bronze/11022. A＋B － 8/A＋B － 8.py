import sys

n = int(sys.stdin.readline().rstrip())

for i in range(n):
    a, b = map(int, sys.stdin.readline().rstrip().split(" "))
    print(f"Case #{i+1}: {a} + {b} = {a+b}")
