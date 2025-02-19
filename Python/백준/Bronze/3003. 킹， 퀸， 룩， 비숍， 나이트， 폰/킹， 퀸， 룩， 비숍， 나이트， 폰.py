import sys

all_pieces = [1, 1, 2, 2, 2, 8]
pieces = list(map(int, sys.stdin.readline().split(" ")))

for i, p in enumerate(pieces):
    print(all_pieces[i] - p, end=" ")
