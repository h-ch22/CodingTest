import sys

n, m = map(int, sys.stdin.readline().split())
not_heard = []
not_seen = []

for _ in range(n):
    name = sys.stdin.readline().strip()
    not_heard.append(name)

for _ in range(m):
    name = sys.stdin.readline().strip()
    not_seen.append(name)

not_heard, not_seen = set(not_heard), set(not_seen)
not_heard_and_seen = not_heard & not_seen
not_heard_and_seen = list(not_heard_and_seen)
not_heard_and_seen.sort()
print(len(not_heard_and_seen))

for name in not_heard_and_seen:
    print(name)
