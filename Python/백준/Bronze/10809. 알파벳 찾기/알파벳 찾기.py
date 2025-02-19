import sys

s = sys.stdin.readline().rstrip()
alphabets = 'abcdefghijklmnopqrstuvwxyz'

for a in alphabets:
    print(s.index(a) if a in s else '-1', end=' ')
