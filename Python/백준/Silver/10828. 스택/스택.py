import sys

n = int(sys.stdin.readline().rstrip())
stack = []

for _ in range(n):
    command = sys.stdin.readline().rstrip()
    commands = command.split(' ')

    if len(commands) == 2:
        command = commands[0]
        data = commands[1]

        if command == 'push':
            stack.append(int(data))

    else:
        if command == 'top':
            print(-1 if not stack else stack[-1])

        elif command == 'size':
            print(len(stack))

        elif command == 'empty':
            print(1 if not stack else 0)

        elif command == 'pop':
            print(-1 if not stack else stack[-1])

            if stack:
                stack.pop()
