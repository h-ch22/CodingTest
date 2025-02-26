import sys

n = int(sys.stdin.readline().rstrip())
big = []

for _ in range(n):
    weight, tall = map(int, sys.stdin.readline().rstrip().split(' '))

    big.append((weight, tall))

for i, b in enumerate(big):
    rank = n
    weight, tall = b[0], b[1]

    for j in range(0, n):
        if j == i:
            continue

        new_weight, new_tall = big[j][0], big[j][1]

        if weight >= new_weight or tall >= new_tall:
            rank -= 1

    print(rank, end=' ', sep=' ')
