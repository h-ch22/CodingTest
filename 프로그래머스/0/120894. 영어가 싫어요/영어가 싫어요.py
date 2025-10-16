def solution(numbers):
    d = {
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six": 6,
        "seven": 7,
        "eight": 8,
        "nine": 9,
        "zero": 0
    }
    
    answer = ''
    
    for key in d.keys():
        numbers = numbers.replace(key, str(d[key]), 50)
    
    return int(numbers)