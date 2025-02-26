import sys

n = int(sys.stdin.readline().rstrip())
sizes = list(map(int, sys.stdin.readline().rstrip().split(' ')))
t, p = map(int, sys.stdin.readline().rstrip().split(' '))
shirts = 0

for s in sizes:
    if s == 0:
        continue

    elif s <= t:
        shirts += 1

    elif s % t == 0:
        shirts += s // t

    else:
        shirts += s // t + 1

print(shirts)
print(n // p, n % p)