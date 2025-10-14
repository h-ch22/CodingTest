def solution(my_string):
    answer = my_string.lower()
    return ''.join(sorted(list(answer)))