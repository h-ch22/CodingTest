import sys

alphabets = 'abcdefghijklmnopqrstuvwxyz'

hashes = {
    a: i+1 for i, a in enumerate(alphabets)
}

l = int(sys.stdin.readline().rstrip())
sentence = sys.stdin.readline().rstrip()
result = 0

for i, s in enumerate(sentence):
    new_s = hashes[s]
    result += new_s * (31 ** i)

print(result)
