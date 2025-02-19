import sys

def convert_grade_to_score(c, credit):
    if c == 'A+':
        return 4.5 * credit

    elif c == 'A0':
        return 4.0 * credit

    elif c == 'B+':
        return 3.5 * credit

    elif c == 'B0':
        return 3.0 * credit

    elif c == 'C+':
        return 2.5 * credit

    elif c == 'C0':
        return 2.0 * credit

    elif c == 'D+':
        return 1.5 * credit

    elif c == 'D0':
        return 1.0 * credit

    elif c == 'F':
        return 0.0 * credit

scores = {}

sum = 0.0
sum_of_credit = 0.0

for _ in range(20):
    name, credit, grade = sys.stdin.readline().rstrip().split(" ")

    if grade == 'P':
        continue

    scores[name] = convert_grade_to_score(grade, float(credit))
    sum_of_credit += float(credit)

for v in scores.values():
    sum += v

print(sum / sum_of_credit)
