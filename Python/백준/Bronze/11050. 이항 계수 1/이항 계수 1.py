import sys
from math import factorial

n, k = map(int, sys.stdin.readline().rstrip().split(' '))

print(int(factorial(n) / (factorial(n - k) * factorial(k))))
