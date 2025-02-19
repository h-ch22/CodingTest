import sys

croatia_alphabets = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
sentence = sys.stdin.readline().strip()

count = 0

for alphabet in croatia_alphabets:
    if sentence == '':
        break

    count += sentence.count(alphabet)
    sentence = sentence.replace(alphabet, "*")

sentence = sentence.replace("*", "")
count += len(sentence)
print(count)
