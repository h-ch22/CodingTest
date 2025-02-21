import sys

sides = list(map(int, sys.stdin.readline().rstrip().split(' ')))
is_triangle = sides[0] == sides[1] == sides[2]

while not is_triangle:
    max_idx = sides.index(max(sides))

    if sum(sides) - max(sides) > max(sides):
        is_triangle = True
        break

    sides[max_idx] -= 1

print(sum(sides))
