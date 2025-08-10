import sys

isbn = sys.stdin.readline().rstrip()
result = 0
checksum = int(isbn[-1])
broken_idx = -1

for i in range(len(isbn)):
    if i % 2 != 0 and isbn[i] != '*':
        result += (3 * int(isbn[i]))

    elif isbn[i] != '*':
        result += int(isbn[i])

    else:
        broken_idx = i

for i in range(1, 10):
    t_result = result + (i*3 if broken_idx % 2 != 0 else i)

    if t_result % 10 == 0:
        print(i)
        sys.exit(0)

print(0)
