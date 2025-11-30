import sys

n = int(sys.stdin.readline().strip())
datas = []

for _ in range(n):
    datas.append(int(sys.stdin.readline().strip()))

datas = sorted(datas)

for d in datas:
    print(d)
