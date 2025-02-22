import sys

n, k = map(int, sys.stdin.readline().rstrip().split(' '))
scores = list(map(int, sys.stdin.readline().rstrip().split(' ')))
scores.sort()

print(scores[-k])
