import sys

n, m = map(int, sys.stdin.readline().rstrip().split(' '))
pocket_monsters = {}
pocket_monsters_idx = {}

for i in range(n):
    name = sys.stdin.readline().rstrip()
    pocket_monsters[name] = i+1
    pocket_monsters_idx[i+1] = name

for _ in range(m):
    quiz = sys.stdin.readline().rstrip()

    if quiz.isnumeric():
        print(pocket_monsters_idx[int(quiz)])

    else:
        print(pocket_monsters[quiz])
