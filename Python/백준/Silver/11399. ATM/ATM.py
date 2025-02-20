import sys

n = int(sys.stdin.readline().rstrip())
people = list(map(int, sys.stdin.readline().rstrip().split(" ")))
people.sort()

for i in range(len(people)):
    if i > 0:
        people[i] = people[i] + people[i - 1]

print(sum(people))
