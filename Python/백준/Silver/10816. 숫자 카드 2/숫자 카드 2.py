import sys

n = int(sys.stdin.readline().rstrip())
cards_num = list(map(int, sys.stdin.readline().rstrip().split(' ')))
cards = {}

for card in cards_num:
    if card in cards:
        cards[card] += 1

    else:
        cards[card] = 1

m = int(sys.stdin.readline().rstrip())
to_count = list(map(int, sys.stdin.readline().rstrip().split(' ')))

for c in to_count:
    if c in cards:
        print(cards[c], end=' ', sep=' ')
    else:
        print(0, end=' ', sep=' ')
