import sys

num_1, num_2 = sys.stdin.readline().rstrip().split(" ")
num_1 = "".join(list(reversed(num_1)))
num_2 = "".join(list(reversed(num_2)))

print(max(int(num_1), int(num_2)))
