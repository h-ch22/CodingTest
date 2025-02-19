import sys

grid = []

max_len = 0
col = 0
row = 0

for i in range(5):
    sentence = list(sys.stdin.readline().rstrip())

    if len(sentence) > max_len:
        max_len = len(sentence)

    grid.append(sentence)

for i in range(max_len):
    for j in range(5):
        try:
            print(grid[j][i], end='', sep='')

        except IndexError:
            continue

    row += 1
