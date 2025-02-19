import sys

s = sys.stdin.readline().rstrip().split(" ")
blank_count = s.count("")

print(len(s) - blank_count)
