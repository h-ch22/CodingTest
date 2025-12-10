import sys

n = int(sys.stdin.readline().strip())
budgets = list(map(int, sys.stdin.readline().strip().split()))
total_budgets = int(sys.stdin.readline().strip())
budgets.sort()

if total_budgets >= sum(budgets):
    print(budgets[-1])
    exit()

start, end = 1, budgets[-1]
new_budgets = []

while start <= end:
    current_budgets = []
    mid = (start + end) // 2

    for b in budgets:
        if b <= mid:
            current_budgets.append(b)

        else:
            current_budgets.append(mid)

    if sum(current_budgets) > total_budgets:
        end = mid - 1

    elif sum(current_budgets) <= total_budgets:
        new_budgets = current_budgets
        start = mid + 1

print(new_budgets[-1])
