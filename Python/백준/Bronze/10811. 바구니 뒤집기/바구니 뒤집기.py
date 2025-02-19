import sys

n, m = map(int, sys.stdin.readline().rstrip().split(" "))
baskets = [i+1 for i in range(n)]

for x in range(m):
    i, j = map(int, sys.stdin.readline().rstrip().split(" "))
    split_arr = list(reversed(baskets[i-1:j]))

    idx = 0

    for y in range(i-1, j):
        baskets[y] = split_arr[idx]
        idx += 1

for b in baskets:
    print(b, end=" ")
