from math import sqrt

def find_divisors(n):
    divisors = []
    divisors_2 = []

    for i in range(1, int(sqrt(n)) + 1):
        if n % i == 0:
            divisors.append(i)

    for d in divisors:
        divisors_2.append(n // d)

    result = list(set(divisors + divisors_2))
    return len(result)


def solution(n):
    answer = find_divisors(n)

    return answer