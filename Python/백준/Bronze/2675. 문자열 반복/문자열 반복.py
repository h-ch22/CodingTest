import sys

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    r, sentence = sys.stdin.readline().rstrip().split(" ")
    new_s = "".join([s * int(r) for s in sentence])

    print(new_s)
