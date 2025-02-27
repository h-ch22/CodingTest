import sys

n = int(sys.stdin.readline().rstrip())
stack = list()
op = list()
find = True
last = 1

for _ in range(n):
    num = int(sys.stdin.readline().rstrip())

    while last <= num:
        stack.append(last)
        op.append('+')
        last += 1

    if stack[-1] == num:
        stack.pop()
        op.append('-')

    else:
        find = False
        break

if not find:
    print('NO')

else:
    for o in op:
        print(o)
