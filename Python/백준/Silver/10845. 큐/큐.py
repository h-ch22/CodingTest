import sys

n = int(sys.stdin.readline().rstrip())
queue = []

for _ in range(n):
    command = sys.stdin.readline().rstrip()
    commands = command.split(' ')

    if len(commands) == 2:
        command = commands[0]
        data = commands[1]

        if command == 'push':
            queue.append(int(data))

    else:
        if command == 'pop':
            if queue:
                print(queue[0])
                queue.pop(0)

            else:
                print(-1)

        elif command == 'size':
            print(len(queue))

        elif command == 'empty':
            print(0 if queue else 1)

        elif command == 'front':
            print(queue[0] if queue else -1)

        elif command == 'back':
            print(queue[-1] if queue else -1)
