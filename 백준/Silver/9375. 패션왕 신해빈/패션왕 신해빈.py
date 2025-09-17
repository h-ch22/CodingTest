import sys
from math import factorial

def combination(n):
    return factorial(n) // factorial(n - 1)

n = int(sys.stdin.readline().rstrip())

for i in range(n):
    result = 1
    t = int(sys.stdin.readline().rstrip())
    cases = t
    clothes = {}

    for j in range(t):
        name, cat = sys.stdin.readline().rstrip().split()

        if clothes.get(cat) is None:
            clothes[cat] = [name]

        else:
            clothes[cat].append(name)

    for k in clothes.keys():
        result *= combination(len(clothes[k]) + 1)
            
    print(result - 1)
