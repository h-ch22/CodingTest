import sys

n, b = sys.stdin.readline().rstrip().split(' ')
alphabets = 'abcdefghijklmnopqrstuvwxyz'.upper()
b_dict = { a: i+10 for i, a in enumerate(alphabets) }

decimals = '0123456789'

for d in decimals:
    b_dict[d] = int(d)

result = 0

for i, c in enumerate(reversed(n)):
    result += (b_dict[c] * int(b) ** i)

print(result)
