import sys

grid = [[0 for _ in range(9)] for _ in range(9)]

for h in range(9):
    w = list(map(int, sys.stdin.readline().rstrip().split(" ")))

    for i, v in enumerate(w):
        grid[h][i] = v

max_value = grid[0][0]
max_w, max_h = 1, 1

for i, row in enumerate(grid):
    max_v = max(row)

    if max_v > max_value:
        max_value = max(row)
        max_h = i+1
        max_w = row.index(max_value)+1

print(max_value)
print(max_h, max_w)