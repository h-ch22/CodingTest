import sys

n, b = map(int, sys.stdin.readline().rstrip().split(' '))
alphabets = 'abcdefghijklmnopqrstuvwxyz'.upper()
b_dict = { i+10: a for i, a in enumerate(alphabets) }

decimals = '0123456789'

for d in decimals:
    b_dict[int(d)] = d

answer = ''

while n != 0:
    value = int(n % b)
    answer += b_dict[value]
    n //= b

print("".join(reversed(answer)))
