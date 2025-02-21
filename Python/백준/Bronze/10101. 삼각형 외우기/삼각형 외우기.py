import sys

d_1 = int(sys.stdin.readline().rstrip())
d_2 = int(sys.stdin.readline().rstrip())
d_3 = int(sys.stdin.readline().rstrip())

if d_1 == d_2 == d_3 == 60:
    print("Equilateral")

elif d_1 + d_2 + d_3 != 180:
    print("Error")

else:
    degree_list = [d_1, d_2, d_3]
    degree_set = set(degree_list)
    del degree_list

    print("Isosceles" if len(degree_set) == 2 else "Scalene")
