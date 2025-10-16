from math import factorial

def solution(balls, share):
    return (factorial(balls) / (factorial(share) * factorial(balls - share)))