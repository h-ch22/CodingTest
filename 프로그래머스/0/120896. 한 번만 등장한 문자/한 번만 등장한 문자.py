def solution(s):
    answer = ''.join(i for i in list(s) if s.count(i) == 1)
    answer = sorted(list(answer))
    return ''.join(answer)