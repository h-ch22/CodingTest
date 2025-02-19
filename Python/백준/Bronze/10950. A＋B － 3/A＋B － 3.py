n = int(input())
cases = []

for i in range(n):
    cases.append(input())

for case in cases:
    case_split = list(map(int, case.split(" ")))
    print(case_split[0] + case_split[1])
