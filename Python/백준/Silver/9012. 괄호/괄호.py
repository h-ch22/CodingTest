import sys
from collections import deque

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    sentence = sys.stdin.readline().rstrip()
    stack = deque()

    for s in sentence:
        if s == '(':
            stack.append(s)

        elif s == ')':
            if stack:
                stack.pop()

            else:
                print('NO')
                break

    else:
        print('YES' if not stack else 'NO')