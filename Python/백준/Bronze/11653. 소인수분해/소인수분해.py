import sys

n = int(sys.stdin.readline().rstrip())

if n != 1:
    i = 2

    while n != 1:
        if n % i == 0:
            print(i)
            n/=i
            
        else:
            i+=1
