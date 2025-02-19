import sys

# 100 * 100 list 생성
board = [[0] * 100 for _ in range(100)]
n = int(sys.stdin.readline().rstrip())
paper_pos = []

for _ in range(n):
    paper_pos.append(list(map(int, sys.stdin.readline().rstrip().split())))

for p in paper_pos:
    for i in range(p[0], p[0]+10):
        for j in range(p[1], p[1]+10):
            # 대상 영역의 값을 1로 변경
            board[i][j] = 1

area = 0

for i in range(100):
    # 넓이 구하기: 다 더하면 됨 (100 * 100)
    area += sum(board[i])

print(area)
