X = int(input())

if X > 64:
    print("input value out of range")
    exit(0)

sticks = [64, 32, 16, 8, 4, 2, 1]
count = 0

for i in range(len(sticks)):
    if X >= sticks[i]:
        count += 1
        X -= sticks[i]

    if X == 0:
        break

print(count)
