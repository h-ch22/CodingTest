import sys

n = int(sys.stdin.readline().rstrip())
cnt = n

for _ in range(n):
    sentence = sys.stdin.readline().rstrip()
    sentence_split = ""

    if len(sentence) == 1:
        continue

    if sentence == sentence[0] * len(sentence):
        continue

    for i, s in enumerate(sentence):
        if s in sentence_split and sentence[i - 1] != s:
            cnt -= 1
            break

        if s not in sentence_split:
            sentence_split += s

print(cnt)
