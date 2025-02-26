import sys

def print_fizz_buzz(n_4):
    if n_4 % 3 == 0 and n_4 % 5 == 0:
        print('FizzBuzz')

    elif n_4 % 3 == 0 and n_4 % 5 != 0:
        print('Fizz')

    elif n_4 % 3 != 0 and n_4 % 5 == 0:
        print('Buzz')

    else:
        print(n_4)

n_1 = sys.stdin.readline().rstrip()
n_2 = sys.stdin.readline().rstrip()
n_3 = sys.stdin.readline().rstrip()

if n_3.isnumeric():
    n_4 = int(n_3) + 1
    print_fizz_buzz(n_4)

else:
    if n_2.isnumeric():
        n_3 = int(n_2) + 1
        print_fizz_buzz(n_3 + 1)

    else:
        n_2 = int(n_1) + 1
        print_fizz_buzz(n_2 + 2)
