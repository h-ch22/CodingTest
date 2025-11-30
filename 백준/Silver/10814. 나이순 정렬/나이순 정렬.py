import sys

n = int(sys.stdin.readline().strip())
members = []

for i in range(n):
    age, name = sys.stdin.readline().strip().split()
    members.append((int(age), name))

members = sorted(members, key=lambda x: x[0])

for m in members:
    print(m[0], m[1])
