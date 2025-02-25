import sys

n = int(sys.stdin.readline().rstrip())
money = []

for _ in range(n):
    price = int(sys.stdin.readline().rstrip())

    if price == 0:
        money.pop()

    else:
        money.append(price)

print(sum(money))
