import sys

n = int(sys.stdin.readline().rstrip())
m = int(sys.stdin.readline().rstrip())
s = sys.stdin.readline().rstrip()

condition = 'I' + ('OI' * n)
cnt = 0

for i, _ in enumerate(s):
    try:
        if s[i:i + len(condition)] == condition:
            cnt += 1

    except IndexError:
        break

print(cnt)
