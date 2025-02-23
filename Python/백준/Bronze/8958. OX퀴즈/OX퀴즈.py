import sys

n = int(sys.stdin.readline().rstrip())

for _ in range(n):
    score = 0
    unit = 1
    result = sys.stdin.readline().rstrip()

    for i, r in enumerate(result):
        score += unit if r == 'O' else 0

        try:
            if result[i+1] == 'O' and r == 'O':
                unit += 1

            else:
                unit = 1

        except IndexError:
            continue

    print(score)
