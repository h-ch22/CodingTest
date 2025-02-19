import sys

students = []

for _ in range(28):
    students.append(int(sys.stdin.readline().rstrip()))

students = set(students)
not_commited = []

if 29 not in students:
    not_commited.append(29)

if 30 not in students:
    not_commited.append(30)

if len(not_commited) != 2:
    for i in range(28):
        if i + 1 not in students:
            not_commited.append(i+1)

print(min(not_commited))
print(max(not_commited))
