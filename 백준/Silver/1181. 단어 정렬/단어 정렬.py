import sys

n = int(sys.stdin.readline().rstrip())
words = []

for _ in range(n):
    words.append(sys.stdin.readline().rstrip())

words = list(set(words))

# 사전 순 정렬
words.sort()

# 길이 순 정렬
words.sort(key=lambda x: len(x))

for word in words:
    print(word)
