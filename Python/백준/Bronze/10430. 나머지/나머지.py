a, b, c = input().split(" ")
a, b, c = int(a), int(b), int(c)

results = [(a+b)%c, ((a%c)+(b%c))%c, (a*b)%c, ((a%c)*(b%c))%c]

for result in results:
    print(result)