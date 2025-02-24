import sys

room = int(sys.stdin.readline().rstrip())

if room == 1:
    print(1)
    sys.exit()

cnt = 1
room -= 1

while True:
    room -= (6 * cnt)
    cnt +=1

    if room <= 0:
        break

print(cnt)
