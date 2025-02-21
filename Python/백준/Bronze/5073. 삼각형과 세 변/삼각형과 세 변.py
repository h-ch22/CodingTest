import sys

while True:
    sides = list(map(int, sys.stdin.readline().rstrip().split(' ')))

    if sides[0] == sides[1] == sides[2] == 0:
        break

    elif sides[0] == sides[1] == sides[2]:
        print('Equilateral')

    else:
        max_side = max(sides)
        sum_side = sum(sides)

        if sum_side - max_side <= max_side:
            print("Invalid")

        else:
            sides = set(sides)

            print("Isosceles" if len(sides) == 2 else "Scalene")
