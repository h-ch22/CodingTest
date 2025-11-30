import sys

n = int(sys.stdin.readline().strip())
datas_copy = [0] * 10001

for _ in range(n):
    data = int(sys.stdin.readline().strip())
    datas_copy[data] += 1

for i, d in enumerate(datas_copy):
    for j in range(d):
        print(i)
