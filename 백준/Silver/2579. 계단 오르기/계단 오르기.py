import sys

dp = []
stairs = int(sys.stdin.readline().rstrip())
scores = []

for i in range(stairs):
    score = int(sys.stdin.readline().rstrip())

    if i == 0:
        dp.append(score)

    elif i == 1:
        dp.append(dp[-1] + score)

    elif i == 2:
        dp.append(
            max(scores[-1], scores[-2]) + score
        )

    else:
        dp.append(
            max(dp[-2], dp[-3] + scores[-1]) + score
        )

    scores.append(score)

print(dp[-1])
