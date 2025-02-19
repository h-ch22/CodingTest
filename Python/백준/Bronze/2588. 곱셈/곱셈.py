num_1 = input()
num_2 = input()

assert len(num_1) == 3 and len(num_2) == 3

num_1 = int(num_1)

for n in reversed(num_2):
    print(num_1 * int(n))

print(num_1 * int(num_2))
