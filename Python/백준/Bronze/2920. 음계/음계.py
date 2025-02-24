import sys

asc = '12345678'
dec = '87654321'

inp = ''.join(sys.stdin.readline().rstrip().split(' '))

if asc == inp:
    print('ascending')

elif dec == inp:
    print('descending')

else:
    print('mixed')
