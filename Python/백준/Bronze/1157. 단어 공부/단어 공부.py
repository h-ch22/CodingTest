import sys

sentence = list(sys.stdin.readline().rstrip().upper())
sentence_w_o_duplication = set(sentence)

max_c = '/'
max = 0

for s in sentence_w_o_duplication:
    if sentence.count(s) > max:
        max = sentence.count(s)
        max_c = s

    elif sentence.count(s) == max:
        max_c = '?'

print(max_c)