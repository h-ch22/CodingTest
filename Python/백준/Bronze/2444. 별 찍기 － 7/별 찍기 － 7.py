import sys

n = int(sys.stdin.readline().rstrip())

for i in range(1, n*2, 2):
    print(" " * ((n*2-i)//2) + "*" * i, sep="")

for i in range(n*2-3, 0, -2):
    print(" " * ((n*2-i)//2) + "*" * i, sep="")
