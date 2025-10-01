import sys

s = sys.stdin.readline().rstrip()
char_set = set()

for i in range(len(s)):
    for j in range(i, len(s)):
        char_set.add(s[i:j+1])

print(len(char_set))
