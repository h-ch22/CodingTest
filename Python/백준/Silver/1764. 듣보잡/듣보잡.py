import sys

n_of_never_heard, n_of_never_seen = map(int, sys.stdin.readline().rstrip().split(' '))
never_heard_or_seen = {}
never_heard_and_seen = []

for i in range(n_of_never_heard+n_of_never_seen):
    name = sys.stdin.readline().rstrip()

    if name in never_heard_or_seen.keys():
        never_heard_or_seen[name] += 1

    else:
        never_heard_or_seen[name] = 0

for k, v in never_heard_or_seen.items():
    if v == 1:
        never_heard_and_seen.append(k)

print(len(never_heard_and_seen))
never_heard_and_seen.sort()

for name in never_heard_and_seen:
    print(name)