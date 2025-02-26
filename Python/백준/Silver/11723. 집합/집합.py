import sys

m = int(sys.stdin.readline().rstrip())
arr = []

for _ in range(m):
    commands = sys.stdin.readline().rstrip().split(' ')
    command = commands[0]

    if len(commands) == 2:
        data = int(commands[1])

        if command == 'add' and data not in arr:
            arr.append(data)

        elif command == 'remove':
            if data in arr:
                arr.remove(data)

        elif command == 'check':
            print(1 if data in arr else 0)

        elif command == 'toggle':
            if data in arr:
                arr.remove(data)

            else:
                arr.append(data)

    else:
        if command == 'all':
            arr = [i for i in range(1, 21)]

        elif command == 'empty':
            arr = []
