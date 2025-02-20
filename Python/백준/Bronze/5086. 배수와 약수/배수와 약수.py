import sys

a, b = -1, -1

while True:
    a, b = map(int, sys.stdin.readline().split(" "))
    
    if a == 0 and b == 0:
        break
    
    is_factor = b % a == 0
    is_multiple = a % b == 0

    if is_factor:
        print("factor")

    elif is_multiple:
        print("multiple")

    else:
        print("neither")
