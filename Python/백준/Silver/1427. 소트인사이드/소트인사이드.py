import sys

num = list(sys.stdin.readline().rstrip())
num = [int(n) for n in num]
num.sort(reverse=True)

for n in num:
    print(n, end="", sep="")
