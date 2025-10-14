from math import sqrt

def solution(n):
    answer = []
    divisor = []

    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            divisor.append(i)

    for d in divisor:
        answer.append(n // d)

    answer += divisor

    return sorted(list(set(answer)))