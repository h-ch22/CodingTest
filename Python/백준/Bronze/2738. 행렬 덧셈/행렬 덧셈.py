import sys

h, w = list(map(int, sys.stdin.readline().rstrip().split(" ")))

matrix = [["" for _ in range(h)] for _ in range(2)]

for i in range(2):
    for j in range(h):
        matrix[i][j] = sys.stdin.readline().rstrip()

for i in range(h):
    row_0, row_1 = matrix[0][i], matrix[1][i]
    row_0, row_1 = list(map(int, row_0.split(" "))), list(map(int, row_1.split(" ")))

    row_sum = ""

    for j in range(w):
        row_sum += str(row_0[j] + row_1[j])

        if j < w - 1:
            row_sum += " "

    print(row_sum)
