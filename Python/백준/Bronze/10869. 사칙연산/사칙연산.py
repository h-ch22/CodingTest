a, b = input().split(" ")
a, b = int(a), int(b)

results = [a + b, a - b, a * b, a // b, a % b]

for result in results:
    print(result)