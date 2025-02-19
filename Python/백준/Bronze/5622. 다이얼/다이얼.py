import sys

alphabets = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz']
times = {}

for i, a in enumerate(alphabets):
    for c in list(a):
        times[c.upper()] = i+3

number = list(sys.stdin.readline().rstrip())
sum = 0

for n in number:
    sum += times[n]

print(sum)
