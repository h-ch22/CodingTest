def solution(numbers):
    numbers.sort(reverse=True)
    
    if numbers.count([x for x in numbers if x == 0]) == len(numbers):
        return 0
    
    return max(numbers[0] * numbers[1], numbers[-1] * numbers[-2])
