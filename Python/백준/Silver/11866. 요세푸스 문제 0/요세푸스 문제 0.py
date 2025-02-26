import sys

n, k = map(int, sys.stdin.readline().rstrip().split(' '))
people = [i+1 for i in range(n)]
to_print = []
idx = 0

while people:
    idx += (k - 1)

    if idx >= len(people):
        idx %= len(people)

    to_print.append(str(people.pop(idx)))

print("<", ", ".join(to_print), ">", sep="")