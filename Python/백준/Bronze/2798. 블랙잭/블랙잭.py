import sys

n, m = map(int, sys.stdin.readline().rstrip().split(' '))
cards = list(map(int, sys.stdin.readline().rstrip().split(' ')))
cards_sum = []

for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            sum_value = cards[i] + cards[j] + cards[k]

            if sum_value > m:
                continue

            cards_sum.append(sum_value)

print(max(cards_sum))
