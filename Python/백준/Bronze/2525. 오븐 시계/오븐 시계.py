h, m = input().split(" ")
time = input("")

h, m, time = int(h), int(m), int(time)

m += time

while m >= 60:
    m -= 60
    h += 1

    if h > 23:
        h -= 24

print(h, m)