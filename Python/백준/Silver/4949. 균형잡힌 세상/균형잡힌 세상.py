import sys
from collections import deque

while True:
    sentence = sys.stdin.readline().rstrip()

    if sentence == '.':
        break

    stack = deque()

    for s in sentence:
        if s == '(' or s == '[':
            stack.append(s)

        elif s == ')' or s ==']':
            if not stack:
                print('no')
                break
                
            if stack[-1] == '(' and s == ')':
                stack.pop()

            elif stack[-1] == '[' and s == ']':
                stack.pop()

            else:
                print('no')
                break

    else:
        print('yes' if not stack else 'no')
