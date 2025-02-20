import sys

n = int(sys.stdin.readline().rstrip())
people = []

for i in range(n):
    info = sys.stdin.readline().rstrip().split(" ")
    # 'i' (가입 순서)를 넣어 secondary 정렬 기준 부여
    people.append([int(info[0]), i, info[1]])

people.sort()

for p in people:
    print(p[0], p[2])
