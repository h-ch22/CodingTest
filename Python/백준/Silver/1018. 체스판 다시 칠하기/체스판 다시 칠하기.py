import sys

n, m = map(int, sys.stdin.readline().rstrip().split(' '))
board = []
result = []

for _ in range(n):
    board.append(sys.stdin.readline().rstrip())

for i in range(n-7):
    for j in range(m-7):
        draw_1 = 0
        draw_2 = 0

        for a in range(i, i+8):
            for b in range(j, j+8):
                if (a + b) % 2 == 0:
                    if board[a][b] != 'B':
                        draw_1 += 1

                    if board[a][b] != 'W':
                        draw_2 += 1

                else:
                    if board[a][b] != 'W':
                        draw_1 += 1

                    if board[a][b] != 'B':
                        draw_2 += 1

        result.append(draw_1)
        result.append(draw_2)

print(min(result))
