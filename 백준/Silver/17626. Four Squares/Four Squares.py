import sys
import math

def is_square(num):
    return math.sqrt(num).is_integer()

n = int(sys.stdin.readline().strip())
_min = 4

if is_square(n):
    _min = 1
    
else:
    for i in range(int(math.sqrt(n)), 0, -1):
        if is_square(n - (i ** 2)):
            _min = 2
            break
            
        else:
            for j in range(int(math.sqrt(n - i ** 2)), 0, -1):
                if is_square(n - (i ** 2) - (j ** 2)):
                    _min = 3
                    break
                    
print(_min)
