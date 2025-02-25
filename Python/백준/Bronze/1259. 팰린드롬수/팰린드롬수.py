import sys

while True:
    number = sys.stdin.readline().rstrip()

    if number == '0':
        break

    print('yes' if number == ''.join(reversed(number)) else 'no')
